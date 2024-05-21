void tracing(String collect) {
  data[0] = digitalRead(sensor1);  //讀取個傳感器值
  data[1] = digitalRead(sensor2);
  data[2] = digitalRead(sensor3);
  data[3] = digitalRead(sensor4);
  data[4] = digitalRead(sensor5);
  // 檢查是否需要改變速度
  if (millis() - initial_speed_start_time > initial_speed_duration) {
    // 已經過了一段時間，改變馬達速度
    setInitialSpeed(fixed_speed);
  }
  // 檢查車輛是否停止
  if (vehicle_stopped) {
    // 如果停止了，检查是否需要重新启动
    if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==1) {
      startVehicle();
    }
    else {
      stop();
    }
  }
  //只有中間測到黑線
  if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==1) {  
    Forward();
    Serial.println("Forward");
  }
  //車輛右偏
  else if(data[0]==1 && data[1]==0 && data[2]==1 && data[3]==1 && data[4]==1){ 
    AdjustLeft(170,170);
    Serial.println("Adjustleft");
  }
  //左轉
  else if(data[0]==0 && data[1]==0 && data[2]==1 && data[3]==1 && data[4]==1){ 
    BigTurnLeft();
    Serial.println("TurnLeft");
  }
  //車輛左偏
  else if(data[0]==1 && data[1]==1 && data[2]==1 && data[3]==0 && data[4]==1){ 
    AdjustRight(170,170);
    Serial.println("Adjustright");
  }
  //右轉
  else if(data[0]==1 && data[1]==1 && data[2]==1 && data[3]==0 && data[4]==0){ 
    BigTurnRight();
    Serial.println("TurnRight");
  }
  else if(data[0]==1 && data[1]==1 && data[2]==1 && data[3]==1 && data[4]==1){
    stop();
  }
  else if(data[0]==0 && data[1]==0 && data[2]==0 && data[3]==0 && data[4]==0){
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
