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

//void findcan(){
//  i=0;
//  if(n.isupper=true){
//    while(redratio<80){
//      STurnLeft();
//      i+=1
//    }
//    Stop();
//    break;
//  }
//  if(n.isupper=false){
//    while(greenratio<80){
//      STurnRight();
//      i+=1
//    }
//    Stop();
//    sketch();
//    break;
//  }
//}
//
//
//
//void goback(){
//  if(n.isupper=true){
//    for(;i>=0;i--){
//      BSTurnLeft();
//    }
//    Back();
//    if(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
//      Stop();
//      Tracing();
//    }
//    break;
//  if(n.isupper=false){
//    for(;i>=0;i--){
//      BSTurnRight();
//    }
//    Back();
//    if(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
//      Stop();
//      Tracing();
//    }
//    break;

    

/*
void goback(){
  if(n.isupper=true){
    while(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
      BSTurnLeft();
    }
    Back();
    if(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
      Stop();
      Tracing();
    }
    break;
    i=0;
  }

  if(n.isupper=false){
    while(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
      BSTurnRight();
    }
    Back();
    if(data[0]!=1 && data[1]!=1 && data[2]!=0 && data[3]!=1 && data[4]!=1){
      Stop();
      Tracing();
    }
    break;
    i=0;
  }
}
*/
