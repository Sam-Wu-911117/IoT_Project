void tracing(String collect) {
//  int data[5];
//  data[0] = digitalRead(sensor1);  //讀取個傳感器值
//  data[1] = digitalRead(sensor2);
//  data[2] = digitalRead(sensor3);
//  data[3] = digitalRead(sensor4);
//  data[4] = digitalRead(sensor5);
//  Serial.print("senor1= ");
//  Serial.print(data[0]);
//  Serial.print(" senor2= ");
//  Serial.print(data[1]);
//  Serial.print(" senor3= ");
//  Serial.print(data[2]);
//  Serial.print(" senor4= ");
//  Serial.print(data[3]);
//  Serial.print(" senor5= ");
//  Serial.println(data[4]);

   // 檢查是否需要改變速度
  if (millis() - initial_speed_start_time > initial_speed_duration) {
    // 已經過了一段時間，改變馬達速度
    setInitialSpeed(fixed_speed);
  }
  // 检查车辆是否停止
  if (vehicle_stopped) {
    // 如果停止了，检查是否需要重新启动
    if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==1) {
      startVehicle();
    }
    else {
      stop();
    }
  }

  if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==1) {  //只有中間測到黑線
    //Serial.println("Forward");
    Forward();
  }
  else if (data[0]==0 && data[1]==0 && data[2]==0 && data[3]==1 && data[4]==1){  //左邊檢測到黑線
    //Serial.println("TurnLeft");
    TurnLeft();
  }
  else if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0) {  //右邊檢測到黑線
    //Serial.println("TurnRight");
    TurnRight();
  }
  else if (data[0]==0 && data[1]==0 && data[2]==0 && data[3]==1 ) {  //左邊檢測到黑線
    //Serial.println("BigTurnLeft");
    BigTurnLeft();
  }
  else if (data[1]==1 && data[2]==1 && data[3]==0 && data[4]==0) {  //右邊檢測到黑線
    //Serial.println("BigTurnRight"); 
    BigTurnRight();
  }
  // else if(data[1]==0 && data[2]==1 && data[3]==1 && data[4]==1){ //車輛左偏
  //   SmallTurnRight();
  // }
  // else if(data[1]==1 && data[2]==1 && data[3]==0 && data[4]==1){ //車輛右偏
  //   SmallTurnLeft();
  // }
  else{
    stop();
  }


//  switch (collect){
//    case  "A1":
//      tracing();
//      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
//        TurnRight();
//      }
//      break;
//    case "A2":
//      tracing();
//      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0){
//        TurnRight();
//      }
//      else if (data[0]==0 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
//        TurnRight();
//      }
//      break;
//    case  "B1":
//      tracing();
//      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0){
//        TurnRight();
//      }
//      else if (data[0]==0 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
//        TurnLeft();
//      }
//      break;
//    case  "B2":
//      tracing();
//      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
//        TurnLeft();
//      }
//      break;
//  }
}
