void tracing() {
  int data[5];
  data[0] = digitalRead(sensor1);  //讀取個傳感器值
  data[1] = digitalRead(sensor2);
  data[2] = digitalRead(sensor3);
  data[3] = digitalRead(sensor4);
  data[4] = digitalRead(sensor5);
  Serial.print("senor1= ");
  Serial.print(data[0]);
  Serial.print(" senor2= ");
  Serial.print(data[1]);
  Serial.print(" senor3= ");
  Serial.print(data[2]);
  Serial.print(" senor4= ");
  Serial.print(data[3]);
  Serial.print("senor5= ");
  Serial.println(data[4]);

  char n=' ';
  
  if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==1) {  //只有中間測到黑線
    Forward();
  }
   else if (data[0]==0 && data[1]==0 && data[2]==0 && data[3]==1 && data[4]==1){  //左邊檢測到黑線
    TurnLeft();
  }
  else if (data[0]==1 && data[1]==1 && data[2]==1 && data[3]==0 && data[4]==0) {  //右邊檢測到黑線
    TurnRight();
  }
  // else if (data[0]==0 && data[1]==0 && data[2]==0 && data[3]==1 && data[4]==1) {  //左邊檢測到黑線
  //   BigTurnLeft();
  // }
  // else if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0) {  //右邊檢測到黑線
  //   BigTurnRight();
  // }

  else{
    Stop();
  }
  switch (n){
    case  'A':
      tracing();
      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
        TurnRight();
      }
      break;
    case  'B':
      tracing();
      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0){
        TurnRight();
      }
      else if (data[0]==0 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
        TurnRight();
      }
      break;
    case  'C':
      tracing();
      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==0 && data[4]==0){
        TurnRight();
      }
      else if (data[0]==0 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
        TurnLeft();
      }
      break;
    case  'D':
      tracing();
      if (data[0]==1 && data[1]==1 && data[2]==0 && data[3]==1 && data[4]==0){
        TurnLeft();
      }
      break;
  }
}
