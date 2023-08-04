#define BLYNK_TEMPLATE_ID "TMPL-0KP5Ocb"
#define BLYNK_DEVICE_NAME "SmartHelmet"
#define BLYNK_AUTH_TOKEN "woxFUjELDiZWys6bzI86umHcIBqRd7SA"

#define BLYNK_PRINT SwSerial

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(2,3);

#include <BlynkSimpleStream.h>


#include <RF24.h>
#include <RF24_config.h>
#include <nRF24L01.h>
#include <printf.h>
#include<stdbool.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "10001";

struct DataPack{
  int pressureReading;
  float h;
  float t;
  bool flag;
  int out;
  float ppm;
}MyData;

char auth[] = BLYNK_AUTH_TOKEN;

BlynkTimer timer;

void myTimerEvent(){
  if (radio.available()) {
    
    radio.read(&MyData, sizeof(MyData));
    
    Blynk.virtualWrite(V0,MyData.h);
    Blynk.virtualWrite(V1,MyData.t);
    Blynk.virtualWrite(V2,MyData.pressureReading);
    Blynk.virtualWrite(V3,MyData.out);
    Blynk.virtualWrite(V4,MyData.ppm);
    Blynk.virtualWrite(V5,MyData.flag);
  }    
}

void setup(){
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
  SwSerial.begin(9600);
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  timer.setInterval(1000L, myTimerEvent);
}

void loop(){
  Blynk.run();
  timer.run();  
}
