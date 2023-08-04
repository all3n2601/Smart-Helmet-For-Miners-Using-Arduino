#include <SPI.h>
#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
#include "MQ7.h"
#include <DHT.h>
#include "MQ135.h"
#include <stdbool.h>

#define dataPin 2
#define DHTType DHT11
#define ANALOGPIN A0
#define RZERO 206.85
#define A_PIN 3
#define VOLTAGE 5

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "10001";

MQ135 gasSensor = MQ135(ANALOGPIN);

DHT dht = DHT(dataPin, DHTType);

int pressureAnalogPin = 1;
int pressureReading;
int noPressure = 5;
int lightPressure = 100;
int mediumPressure = 1000;
int Force;
int Area = 14.7;
int out;

int IRSensor = 3;

struct DataPack{
  int pressureReading;
  float h;
  float t;
  bool flag;
  int out;
  float ppm;
}MyData;

MQ7 mq7(A_PIN, VOLTAGE);
 
void setup(void) {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.stopListening();

  Serial.begin(9600);

  Serial.println("");

  Serial.println("Calibrating MQ7");
  mq7.calibrate();
  Serial.println("Calibration done!");
  
  pinMode(IRSensor, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  dht.begin();

  float rzero = gasSensor.getRZero();
  Serial.print("MQ135 RZERO Calibration Value : ");
  Serial.println(rzero);
}
 
void loop(void) {
  delay(5000);
  ////////////////// Force Sensor///////////////////////////
  ////////////////////////////////////////////////////////// 

  pressureReading = analogRead(pressureAnalogPin);
  Serial.println("------------------------------------------------------------------------------------------------------");
  Serial.print("Pressure Pad Reading = ");
  Serial.println(pressureReading);

  if (pressureReading < noPressure) {
    Serial.println(" - No Force Exerted");
  } else if (pressureReading < lightPressure) {
    Serial.println(" - Force Exerted is Normal");
  } else if (pressureReading < mediumPressure) {
    Serial.println(" - Medium Force Exerted");
  } else{
    Serial.println(" - High Force is being Exerted");
  }

  Force = pressureReading * Area;
  Serial.print("Force = ");
  Serial.println(Force);
  Serial.println(""); 
  
  /////////////DHT 11 Temperature and Humidity////////////////////////
  ////////////////////////////////////////////////////////////////////

  float h = dht.readHumidity();
  float t = dht.readTemperature();
    
  if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from the DHT sensor, check wiring.");
        return;
    }

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("% || Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  Serial.println();

  ////////////Infra Red Sensor/////////////////
  ////////////////////////////////////////////
  int sensorStatus = digitalRead(IRSensor);

  if (digitalRead(IRSensor) == HIGH)
  {
    Serial.println("Helmet Not Weared!");
  }
  if (digitalRead(IRSensor) == LOW)
  {
    Serial.println("Helmet Weared!");
  }

  Serial.println("");
  bool flag;

  if (digitalRead(IRSensor) == HIGH)
  {
    flag = false;
  }
  if (digitalRead(IRSensor) == LOW)
  {
    flag = true;
  }

  ///////////////////MQ135///////////////////
  /////////////////////////////////////////// 

  float ppm = gasSensor.getPPM();
  Serial.print("CO2 ppm value : ");
  Serial.println(ppm);

  if (ppm <= 150){
    Serial.println("Normal air");
  }
  if ((ppm <= 700)&&(ppm >= 150)){
    Serial.println("Alcohol Detected ! ");
  }
  if (ppm >= 700){
    Serial.println("Lighter gas Detected");
  }
  Serial.println(""); 

  ////////////CO Sensor MQ7///////////////////
  //////////////////////////////////////////// 
  Serial.print("CO PPM = ");
  Serial.println(mq7.readPpm());
  out = mq7.readPpm();  
  Serial.println(""); 
  
 ////////////////////////////////////////////
 //////////////Sending Packets///////////////  
  MyData.pressureReading = pressureReading;
  MyData.h = h;
  MyData.t = t;
  MyData.flag = flag;
  MyData.ppm = ppm;
  MyData.out = out;
  
  radio.write(&MyData, sizeof(MyData));
}
