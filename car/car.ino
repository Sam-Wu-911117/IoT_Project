const int in1 = 4;   //控制馬達1正轉
const int in2 = 5;   // 控制馬達1反轉
const int in3 = 6;   // 控制馬達2正轉
const int in4 = 7;   // 控制馬達2反轉
const int enA = 10;  //控制PWM
const int enB = 11;
const int sensor1 = 3;  //循跡傳感器
const int sensor2 = 8;
const int sensor3 = 9;
const int sensor4 = 12;
const int sensor5 = 13;
const byte speed = 80;
const byte turn_speed = 60;

const byte trigPin1 = 19;  // 右邊超音波 觸發腳Trig
const byte echoPin1 = 18;  // 右邊超音波 接收腳 Echo
int distance1;             // 距離 cm

const byte trigPin2 = 17;  // 左邊超音波 觸發腳Trig
const byte echoPin2 = 16;  // 左邊超音波 接收腳 Echo
int distance2;            // 距離 cm

const byte trigPin3 = 15;  // 左邊超音波 觸發腳Trig
const byte echoPin3 = 14;  // 左邊超音波 接收腳 Echo
int distance3;    

// can 1 => a
// can 2 => b => e
// can 3 => b => e
// can 4 => c

void setup() {
  Serial.begin(9600);
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

  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
}

void loop() {
  tracing();

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

//前進
void Forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, speed);
  analogWrite(enB, speed);
  Serial.println("forward");
}

//後退
void Back() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, turn_speed);
  analogWrite(enB, turn_speed);
  Serial.println("back");
}
//左轉
void TurnLeft() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, turn_speed);
  Serial.println("left");
}

//右轉
void TurnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, turn_speed);
  analogWrite(enB, 0);
  Serial.println("right");
}

//停止
void Stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  Serial.println("stop");
}
