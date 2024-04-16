const byte trigPin1 = 12;  // 右邊超音波 觸發腳Trig
const byte echoPin1 = 11;  // 右邊超音波 接收腳 Echo
int distance1;             // 距離 cm

const byte trigPin2 = 9;  // 左邊超音波 觸發腳Trig
const byte echoPin2 = 8;  // 左邊超音波 接收腳 Echo
int distance2;            // 距離 cm

 const byte trigPin3 = 6;  // 左邊超音波 觸發腳Trig
 const byte echoPin3 = 5;  // 左邊超音波 接收腳 Echo
 int distance3;            // 距離 cm

unsigned long ping1() {
  digitalWrite(trigPin1, HIGH);  // 觸發腳位設定為高電位
  delayMicroseconds(10);         // 持續10微秒
  digitalWrite(trigPin1, LOW);
  return (pulseIn(echoPin1, HIGH) / 58.2);  // 換算成 cm 並傳回
}

unsigned long ping2() {
  digitalWrite(trigPin2, HIGH);  // 觸發腳位設定為高電位
  delayMicroseconds(10);         // 持續10微秒
  digitalWrite(trigPin2, LOW);
  return (pulseIn(echoPin2, HIGH) / 58.2);  // 換算成 cm 並傳回
}

 unsigned long ping3() {
   digitalWrite(trigPin3, HIGH);  // 觸發腳位設定為高電位
   delayMicroseconds(10);         // 持續10微秒
   digitalWrite(trigPin3, LOW);
   return (pulseIn(echoPin3, HIGH) / 58.2);  // 換算成 cm 並傳回
 }

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);

  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);

   pinMode(trigPin3, OUTPUT);
   pinMode(echoPin3, INPUT);

  Serial.begin(9600);
}

void loop() {

  distance1 = ping1();  // 更新距離值
  distance2 = ping2();
  distance3 = ping3();


  Serial.print("Distance1: ");  // 輸出距離到串口
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance2: ");
  Serial.print(distance2);
  Serial.println(" cm");
  Serial.print("Distance3: ");
  Serial.print(distance3);
  Serial.println(" cm");

  delay(1000);  // 延遲1000毫秒再次測量距離
}
