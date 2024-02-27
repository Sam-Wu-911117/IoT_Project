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
}

void loop() {
  tracing();
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
