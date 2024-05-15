//前進
void Forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, fixed_speed);
  analogWrite(enB, fixed_speed);
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
// void TurnLeft() {
//   digitalWrite(in1, HIGH);
//   digitalWrite(in2, LOW);
//   digitalWrite(in3, HIGH);
//   digitalWrite(in4, LOW);
//   analogWrite(enA, 0);
//   analogWrite(enB, turn_speed);
// }
//右轉
// void TurnRight() {
//   digitalWrite(in1, LOW);
//   digitalWrite(in2, HIGH);
//   digitalWrite(in3, LOW);
//   digitalWrite(in4, HIGH);
//   analogWrite(enA, turn_speed);
//   analogWrite(enB, 0);
// }

//大左轉
void BigTurnLeft() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, turn_speed_n);
  analogWrite(enB, turn_speed);
}

//大右轉
void BigTurnRight() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, turn_speed);
  analogWrite(enB, turn_speed_n);
}

//停止
void stop() {
  // 停止車輛並將速度設置為零
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  Serial.println("stop");
  setInitialSpeed(0); // 將速度設置為零
  //startInitialSpeedTimer(); // 重新啟動計時器以準備下一次起步
  vehicle_stopped = true;
}

//找垃圾桶小左轉
void SmallTurnLeft() {
  // 計算PWM寬度，將角度映射到PWM的值（0~255）
  int pwmValue = map(360, 0, 360, 0, 255);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // 控制馬達轉到目標角度
  analogWrite(enA, 0);
  analogWrite(enB, pwmValue);
  Serial.println("Small left");
  delay(1000);
}

//找垃圾桶小右轉
void SmallTurnRight() {
  // 計算PWM寬度，將角度映射到PWM的值（0~255）
  int pwmValue = map(360, 0, 360, 0, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  // 控制馬達轉到目標角度
  analogWrite(enA, pwmValue);
  analogWrite(enB, 0);
  Serial.println("Small right");
  delay(1000);
}
//偏右校正
void AdjustLeft(int Aspeed,int Bspeed) { 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, Aspeed);
  analogWrite(enB, Bspeed);
}
//偏左校正
void AdjustRight(int Aspeed,int Bspeed) { 
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, Aspeed);
  analogWrite(enB, Bspeed);
}
