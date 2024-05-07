#include <RH_RF95.h>
#include <SoftwareSerial.h>

//rpi
const byte rx = A4; //gpio14
const byte tx = A5; //gpio15
SoftwareSerial Ser(rx,tx); 

//LoRa
const byte RX = 2; //LoRa TX (yellow)
const byte TX = 3; //LoRa RX (white)
SoftwareSerial COMSerial(RX,TX);  
RH_RF95<SoftwareSerial> rf95(COMSerial);

const int PressurePin[4] = {A0,A1,A2,A3};
const int numSensors = 4;
int sensorValues[numSensors]; 
float weight[numSensors];
float percentage[numSensors];
// 定義壓力感測器的量程 (0.1kg ~ 10kg)
// const float minPressure = 0.1; // 最小壓力（kg）
// const float maxPressure = 10.0; // 最大壓力（kg）
String rfid,command;
char cmd[2];
void setup() {
  Serial.begin(115200);
  Ser.begin(115200);

  pinMode(PressurePin[0],INPUT);
  pinMode(PressurePin[1],INPUT);
  pinMode(PressurePin[2],INPUT);
  pinMode(PressurePin[3],INPUT);
  //rpi
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  //Serial.println("RF95 server test."); 
  // if (!rf95.init()) {
  //   Serial.println("init failed");
  //   while (1);
  // }
  rf95.setFrequency(433.0);
  while (!Ser) {}
}

void loop() {
  if(rf95.available()){
    //uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t buf[1];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      //Serial.print("got request: ");
      Serial.print("NowAt:");
      Serial.println((char*)buf);
      rfid = (char*)buf;
      delay(1000);
    } 
  }
  pressure(rfid);
  delay(1000);
}