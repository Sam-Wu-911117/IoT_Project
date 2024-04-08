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

void setup() {
  Serial.begin(115200);
  Ser.begin(115200);
  //rpi
  pinMode(rx,INPUT);
  pinMode(tx,OUTPUT);
  //Serial.println("RF95 server test."); 
  if (!rf95.init()) {
    Serial.println("init failed");
    while (1);
  }
  rf95.setFrequency(433.0);
  while (!Ser) {}
}

void loop() {
  if(rf95.available()){
    //uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t buf[4];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      //Serial.print("got request: ");
      Serial.println((char*)buf);
      Ser.print(String((char*)buf));
      delay(1000);
    } 
  }
  delay(1000);
}
