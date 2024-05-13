#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h> 
#include <RH_RF95.h>

//softwareserial for rpi
//mega  Serial1 rx 19,tx 18
// const byte rxPin = 15;  //rpi GPIO 14 右邊從上往下數第四個
// const byte txPin = 14;  //rpi GPIO 15 右邊從上往下數第五個
// SoftwareSerial Ser(rxPin, txPin); //gnd 右邊從上往下數第三個

//softwareserial for LoRa
const byte RX = 12; 
const byte TX = 13; 
SoftwareSerial Lora(RX,TX);//LoRa TX (yellow),RX (white)
RH_RF95<SoftwareSerial> rf95(Lora);

//RFID
#define SS_PIN 53  // SDA uno 10,mega 53
#define RST_PIN 5  //  RST uno 9, mega 5
//SCK 13,MOSI 11,MISO 12 (uno)
//SCK 52,MOSI 51,MISO 50 (Mega)
char *reference;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // 創建MFRC522對象
#define MAX_CARDS 4  // 最大不同卡號數量
struct Card {
  String cardIDs;
  String cardNames;
};
Card cards[] = {
  { "E0DD9218" ,"1" },{ "CC6F3BD5" ,"2" },{ "8054E119" ,"3" },{ "E0EAA718" ,"4" }
};
int cardCounts[MAX_CARDS] = { 0 };

const int in1 = 4;   // 控制馬達1正轉
const int in2 = 14;  // 控制馬達1反轉
const int in3 = 6;   // 控制馬達2正轉
const int in4 = 7;   // 控制馬達2反轉
const int enA = 10;  // 控制PWM
const int enB = 11;

// 馬達初始轉速和固定轉速
const int initial_speed = 100;  // 初始轉速 (0-255)
const int fixed_speed = 80;  // 第一個固定轉速 (0-255)

int speed;
const int turn_speed = 230;
const int turn_speed_n = 190 ;

// 開始執行第一個固定轉速的時間
unsigned long initial_speed_start_time = 0;
// 第一個固定轉速持續時間（毫秒）
const unsigned long initial_speed_duration = 500;

unsigned long last_stop_time = 0;

bool vehicle_stopped = false;

//循跡傳感器
const int sensor1 = 3;  
const int sensor2 = 8;
const int sensor3 = 9;
const int sensor4 = 22;
const int sensor5 = 23;

//超音波
// Left
const byte trigPin1 = 24;  
const byte echoPin1 = 25;  
int distance1;             
// Right
const byte trigPin2 = 26;  
const byte echoPin2 = 27;  
int distance2;             
// Back
const byte trigPin3 = 28;  
const byte echoPin3 = 29;  
int distance3;    

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

unsigned long ping3() {
  digitalWrite(trigPin3, HIGH); // 觸發腳位設定為高電位
  delayMicroseconds(10); // 持續10微秒
  digitalWrite(trigPin3, LOW);
  return (pulseIn(echoPin3, HIGH) / 58.2); // 換算成 cm 並傳回
}

// can 1 => a
// can 2 => b => e
// can 3 => b => e
// can 4 => c
String collect;



ISR(TIMER1_COMPA_vect){

  tracing(collect);
}

void setup() {
  Serial.begin(115200);
  Serial1.begin(115200); 
  SPI.begin();        // 初始化SPI
  mfrc522.PCD_Init(); // 初始化MFRC522
  Serial.println("請放置卡片");  // 提示請放置卡片
  
  cli(); // 關閉中斷
  TCCR1A = 0; // 設置 Timer1 控制寄存器A為0
  TCCR1B = (1<<WGM12); // 設置 Timer1 控制寄存器B，啟用CTC模式
  TCCR1B |=(1<<CS10)|(1<<CS11); // 設置 Timer1 的分頻係數為64
  OCR1A = 3125; // 設置計時器的計數值，以實現200毫秒的時間間隔
  TCNT1 = 0; // 將 Timer1 計數器清零
  TIMSK1 |=(1<<OCIE1A); // 啟用 Timer1 的比較匹配中斷
  sei(); // 啟用中斷


  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  // 設置馬達初始轉速
  analogWrite(enA, initial_speed);
  analogWrite(enB, initial_speed);

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);

  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  
  while (!Serial1) {}
  if (!rf95.init()) {
    Serial.println("init failed");
    while (1);
  }
  rf95.setFrequency(433.0);
}

void loop() {
    if(rf95.available()){
    //uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
    uint8_t buf[2];
    uint8_t len = sizeof(buf);
    if (rf95.recv(buf, &len)) {
      //Serial.print("got request: ");
      //Serial.print("NowAt:");
      Serial.println((char*)buf);
      collect = (char*)buf;
      delay(1000);
    }
  } 
  
  rfidRead();
  ulDistance();
}

void startVehicle() {
  startInitialSpeedTimer(); // 重新启动计时器
  last_stop_time = millis();
  // 启动车辆并设置为初始速度
  analogWrite(enA, initial_speed);
  analogWrite(enB, initial_speed);
  vehicle_stopped = false;
}

void setInitialSpeed(int speed) {
  // 設置固定轉速
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}

void startInitialSpeedTimer() {
  // 開始計時器，用於計算第一個固定速度的執行時間
  initial_speed_start_time = millis();
}

