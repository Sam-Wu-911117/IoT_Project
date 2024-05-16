void ulDistance() {
  distance1 = ping1();  // 更新距離值
  distance2 = ping2();
  distance3 = ping3();

  // Serial.print("Distance1: ");  // 輸出距離到串口
  // Serial.print(distance1);
  // Serial.print(" cm ");
  // Serial.print("Distance2: ");
  // Serial.print(distance2);
  // Serial.print(" cm ");
  // Serial.print("Distance3: ");
  // Serial.print(distance3);
  // Serial.println(" cm ");

  // 如果距離小於某個閾值，停止車子
  if (distance1 < 10 || distance2 < 10 || distance3 < 10) {
    stop(); // 停止車子
  }

  delay(1000);  // 延遲1000毫秒再次測量距離
}