#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h> 
#include <RH_RF95.h>
//softwareserial for rpi
const byte rxPin = 15;  //rpi GPIO 14 右邊從上往下數第四個
const byte txPin = 14;  //rpi GPIO 15 右邊從上往下數第五個
SoftwareSerial Ser(rxPin, txPin); //gnd 右邊從上往下數第三個

//softwareserial for LoRa
const byte RX = A0; //LoRa TX 
const byte TX = A1; //LoRa RX 
SoftwareSerial Lora(RX,TX);


//RFID
#define SS_PIN 53  // SDA
#define RST_PIN 22  //  RST
//SCK 52
//MISO 50
//MOSI 51
MFRC522 mfrc522(SS_PIN, RST_PIN);  // 創建MFRC522對象

#define MAX_CARDS 4  // 最大不同卡號數量

String cardIDs[MAX_CARDS] = { "E0DD9218", "CC6F3BD5", "8054E119", "E0EAA718" };  // 定義四個卡號ID
String cardNames[MAX_CARDS] = { "one", "two", "three", "four" };                            // 對應卡號名稱
int cardCounts[MAX_CARDS] = { 0 };

const int in1 = 4;   //控制馬達1正轉
const int in2 = 5;   // 控制馬達1反轉
const int in3 = 6;   // 控制馬達2正轉
const int in4 = 7;   // 控制馬達2反轉
const int enA = 10;  //控制PWM
const int enB = 11;
//循跡傳感器
const int sensor1 = 3;  
const int sensor2 = 8;
const int sensor3 = 9;
const int sensor4 = 12;
const int sensor5 = 13;
const byte speed = 80;
const byte turn_speed = 60;
//超音波
const byte trigPin1 = 19;  // 右邊超音波 觸發腳Trig
const byte echoPin1 = 18;  // 右邊超音波 接收腳 Echo
int distance1;             // 距離 cm

const byte trigPin2 = 17;  // 左邊超音波 觸發腳Trig
const byte echoPin2 = 16;  // 左邊超音波 接收腳 Echo
int distance2;            // 距離 cm

// const byte trigPin3 = 15;  // 左邊超音波 觸發腳Trig
// const byte echoPin3 = 14;  // 左邊超音波 接收腳 Echo
// int distance3;    



unsigned long ping1() {
    digitalWrite(trigPin1, HIGH); // 觸發腳位設定為高電位
    delayMicroseconds(10); // 持續10微秒
    digitalWrite(trigPin1, LOW);
    return (pulseIn(echoPin1, HIGH) / 58.2); // 換算成 cm 並傳回
}

unsigned long ping2() {
    digitalWrite(trigPin2, HIGH); // 觸發腳位設定為高電位
    delayMicroseconds(10); // 持續10微秒
    digitalWrite(trigPin2, LOW);
    return (pulseIn(echoPin2, HIGH) / 58.2); // 換算成 cm 並傳回
}

// unsigned long ping3() {
//     digitalWrite(trigPin3, HIGH); // 觸發腳位設定為高電位
//     delayMicroseconds(10); // 持續10微秒
//     digitalWrite(trigPin3, LOW);
//     return (pulseIn(echoPin3, HIGH) / 58.2); // 換算成 cm 並傳回
// }

// can 1 => a
// can 2 => b => e
// can 3 => b => e
// can 4 => c

void setup() {

  Serial.begin(9600);
  Ser.begin(9600); 
  SPI.begin();        // 初始化SPI
  mfrc522.PCD_Init(); // 初始化MFRC522

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
           
  Serial.println("請放置卡片");  // 提示請放置卡片
  while (!Ser) {}

    if (!rf95.init()) {
    ShowSerial.println("init failed");
    while (1);
  }
  rf95.setFrequency(433.0);

  // pinMode(trigPin3, OUTPUT);
  // pinMode(echoPin3, INPUT);
}

void loop() {
  tracing();
  rfidRead();
  ulDistance();
}
