void tracing(String collect) {
  data[0] = digitalRead(sensor1);  //讀取個傳感器值
  data[1] = digitalRead(sensor2);
  data[2] = digitalRead(sensor3);
  data[3] = digitalRead(sensor4);
  data[4] = digitalRead(sensor5);
  sensorvalue=data[0]*16+data[1]*8+data[2]*4+data[3]*2+data[4]*1;
  //Serial.println(sensor);
  // 檢查是否需要改變速度
  if (millis() - initial_speed_start_time > initial_speed_duration) {
    // 已經過了一段時間，改變馬達速度
    setInitialSpeed(fixed_speed);
  }
  // 檢查車輛是否停止
  if (vehicle_stopped) {
    // 如果停止了，检查是否需要重新启动
    if (sensorvalue==27) {
      //11011
      startVehicle();
    }
    else {
      stop();
    }
  }
  switch(sensorvalue){
    //只有中間測到黑線:11011
    case 27:
      Forward(80);
      //Serial.println("Forward");
      break;
    //車輛右偏:10111
    case 23:
      AdjustLeft(170,170);
      //Serial.println("Adjustleft");
      break;
    //極右偏:01111
    case 15:
      AdjustLeft(190,190);
      //Serial.println("Adjustleft");
      break;
    //右轉:11100
    case 28:
      BigTurnRight(210,190);
      break;
    //車輛左偏:11101
    case 29:
      AdjustRight(170,170);
      //Serial.println("Adjustright");
      break;
    //車輛小左偏:11001
    case 25:
      AdjustRight(170,170);
      //Serial.println("Adjustright");
      break;
    //車輛小右偏:10011
    case 19:
      AdjustLeft(170,170);
      //Serial.println("Adjustleft");
      break;
    //極左偏:11110
    case 30:
      AdjustRight(190,190);
      //Serial.println("Adjustright");
      break;
    //左轉:00111
    case 7:
      BigTurnLeft(190,210);
      break;
    //停止:11111 
    case 31:
      stop();
      break;
    //減速:00000
    case 0:
      Forward(70);
      break;

    default:
      stop();
      break;
  }
}
