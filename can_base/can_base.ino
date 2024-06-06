#include <RH_RF95.h>
#include <SoftwareSerial.h>
#include <SPI.h>

// rpi
const byte rx = 8; // gpio14
const byte tx = 9; // gpio15
SoftwareSerial Ser(rx, tx);

// LoRa

const byte RX = 2; 
const byte TX = 3; 
SoftwareSerial Lora(RX,TX);//LoRa TX (yellow),RX (white)
RH_RF95<SoftwareSerial> rf95(Lora);


// 传感器引脚
const int PressurePin[2] = {A0, A1};
const int numSensors = 2;

int fsrValues1;
int fsrValues2;
int deltaValue[numSensors];

String command;
uint8_t cmd[sizeof(command)];

void setup() {
  Serial.begin(115200);
  Ser.begin(115200);
  
  // 初始化传感器引脚
  pinMode(PressurePin[0], INPUT);
  pinMode(PressurePin[1], INPUT);
  
  // 初始化 rpi 串口引脚
  pinMode(rx, INPUT);
  pinMode(tx, OUTPUT);

  // 初始化 LoRa 模块
  if (!rf95.init()) {
    Serial.println("LoRa init failed");
    while (1);
  }
  rf95.setFrequency(433.0);

  // 等待 Ser 就绪
  while (!Ser) {}
}

void loop() {
  // 检查是否有来自 LoRa 模块的数据
  // if (rf95.available()) {
  //   uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
  //   uint8_t len = sizeof(buf);
  //   if (rf95.recv(buf, &len)) {
  //     rfid = (char*)buf;
  //   }
  // }
  // 调用压力传感器处理函数
  pressure();

  // 延时一秒
  //delay(1000);
}

// void pressure() {
//   for (int i = 0; i < numSensors; i++) {
//     fsrValuesBefore[i] = analogRead(PressurePin[i]);
//     delay(10);
//     fsrValuesAfter[i] = analogRead(PressurePin[i]);
//     deltaValue[i] = fsrValuesAfter[i] - fsrValuesBefore[i];
//   }

//   // 处理传感器数据
//   for (int i = 0; i < numSensors; i++) {
//     Serial.print("Sensor ");
//     Serial.print(i);
//     Serial.print(": ");
//     Serial.println(deltaValue[i]);
//   }
// }
