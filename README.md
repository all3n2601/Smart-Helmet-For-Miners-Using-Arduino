# Smart-Helmet-For-Miners-Using-Arduino
The Smart Helmet for Miners Using Arduino Connected to BLYNK Backend 


Mining is a dangerous profession. The traditional occupationa hazards such as coal dust inhalation. As mines are getting deeper, the risk of collapse has greatly increased. 
With a rise in surface temperatures and an increasingly unpredictable climate, the temperature of a mine is more likely to fluctuate and as a result, consistent temperature control is even more important than it had previously been.
Every Year mining workers lose their lives in mining accidents in India . Wide Spread illegal mining activities and private mines accentuates the problem . 
While the safety of mineworkers is the most serious problem that is faced by the Mining Industry.
Flooding of the tunnels in the mines.Working in a coal mine is dangerous.Workers face many issues Like the collapsing of the tunnels
The mines could flood with water due to various factors. As the workers deal with dynamites to blast coal , they are also exposed to poisonous gases.
To Encounter all the problems we have found a solution (ie) Smart Helmet it helps detect poisonous gases, measures temperature and humidity, detects pressure changes on body to find if a rock or object has fallen over him/her , the IR sensor ensures the worker is wearing the helmet. This project can ensure the worker is provided with a safety equipment that is with him throughout his work hours.


METHODOLOGY

1) The proposed project is to design a system that monitors Environment temperature and humidity,the gases around the miner,And if he is wearing the helmet and if any obstacles has fallen over him, and transmit the information to the remote receiver at the Base Station outside the Mine. The ultimate goal is to collect, monitor, and effectively employ relevant data for Mining processes, with the purpose of achieving an optimized and more hazard free way of mining.
2) The proposed system consists of Arduino as processing unit and Wireless Sensor
Network (WSN) base station.A temperature and humidity sensor,gas sensors,force sensors and IR Sensor data is fetched to the WSN data collection node.
3) The sensor node consists of a Liquid Crystal Display (LCD) module, where the
sensor output is monitored in real time and any abnormal conditions are buzzed out so precautions can be taken out accordingly
4) The sensor node is a building unit of the WSN. Its function is to achieve the perception, collection, processing and wireless transmission.
5) Arduino UNO board controls the processing and manages the different types of sensors for the Working of the Smart Helmet
6) In the proposed system, Transmitter consists of MQ7 and MQ135 gas Sensor, DHT11 sensor for sensing the humidity and temperature of the mine. The data of these sensors is directly displayed on the LCD and it is sent to the cloud server using Long Range radio (LoRa) transmitter module. 
7) The receiver consists of LoRa receiver for receiving the processed data and it also consists of LCD, Cloud server to store the processed databy using Blynk.
8) The proposed Safety Device aims in providing the safety of Mine Workers in a more secure way.


Materials Used

Material	QTY	Rate	Amount
			
DHT11	1	110	110
IR Sensor	1	50	50
MQ7	1	130	130
MQ135	1	130	130
Bread Board	2	50	100
Arduino UNO (with cable)	2	750	1500
Force Sensor	1	350	350
NRF 24L01	2	90	180
Buzzer	2	10	20
WIFI Module			
Jumper Cable	60	1	60
Helmet	1	250	250


Environment	Cost
	
ARDUNO IDE	Open Source
BLYNK	Free Plan



CONCLUSION AND FUTURE SCOPE

This Project Helps Miners Work Freely without having any fear over the possible hazards for them.The Sensors in the Miners Helmet Monitors the Realtime Environment and If the Data read is above the threashold Value the Miner is Alerted using the Buzzer in the Helmet.
Through this smart helmet, the Supervisor can continuously monitor the entire Workers involved in Mining process and can also get notification about the Worker’s condition and can Immediately save the workers from any serious issues in case of any Emergency Situation.
Hence, The Issues faced by Miners are reduced  to a Great   extent Decreased amount of Death Rates and Safe and well Alerted Environment is setup for Workers.

Future Scope :
Further it can be improved by the integrating more sensors on the helmet such as heart rate sensor and other gas sensors in order to take safety measures over miner’s health .and also Actual mine conditions with all the emergencies can be simulated and the miners can be trained in the simulated environment for better performance and intelligent responses. They must also be given proper training and licenses for the explosive handling inside the mines.



