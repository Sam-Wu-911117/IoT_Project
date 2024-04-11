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

//大左轉
void BigTurnLeft() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, turn_speed);
  Serial.println("left");
}

//右轉
void BigTurnRight() {
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
