#include <RH_RF95.h>
#include <SoftwareSerial.h>

//rpi
const byte RX = A1; //gpio14
const byte TX = A2; //gpio15
SoftwareSerial Ser(RX,TX); 

//LoRa
SoftwareSerial COMSerial(5, 6);  // RX(yellow), TX(white)
RH_RF95<SoftwareSerial> rf95(COMSerial);

void setup() {
  Serial.begin(9600);
  if (!rf95.init()) {
    Serial.println("init failed");
    while (1);
  }
  rf95.setFrequency(433.0);
}

void loop() {
  if(rf95.available()){
    uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      Serial.print("got request: ");
      Serial.println((char*)buf);
    } 
  }
}
