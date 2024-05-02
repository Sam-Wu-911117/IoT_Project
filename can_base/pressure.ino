void pressure(String rfid){
  Ser.print("NowAt");
  Ser.print(":");
  Ser.println(rfid);

  sensorValues[0] = analogRead(PressurePin[0]);
  sensorValues[1] = analogRead(PressurePin[1]);
  sensorValues[2] = analogRead(PressurePin[2]);
  sensorValues[3] = analogRead(PressurePin[3]);

  weight[0]=(sensorValues[0]/1023)*9.9;
  weight[1]=(sensorValues[1]/1023)*9.9;
  weight[2]=(sensorValues[2]/1023)*9.9;
  weight[3]=(sensorValues[3]/1023)*9.9;

  percentage[0]=198*weight[0];
  percentage[1]=198*weight[1];
  percentage[2]=198*weight[2];
  percentage[3]=198*weight[3];

  Serial.print(sensorValues[0]);
  Serial.print(" Pressure0 ");
  Serial.print(int(percentage[0]));
  Serial.print(" % ");

  Serial.print(" Pressure1 ");
  Serial.print(int(percentage[1]));
  Serial.print(" % ");

  Serial.print(" Pressure2 ");
  Serial.print(int(percentage[2]));
  Serial.print(" % ");

  Serial.print(" Pressure3 ");
  Serial.print(int(percentage[3]));
  Serial.print(" % ");

  Ser.print("Pressure0");
  Ser.print(":");
  Ser.println(int(percentage[0]));
  
  Ser.print("Pressure1");
  Ser.print(":");
  Ser.println(int(percentage[1]));

  Ser.print("Pressure2");
  Ser.print(":");
  Ser.println(int(percentage[2]));

  Ser.print("Pressure3");
  Ser.print(":");
  Ser.println(int(percentage[3]));

  if(sensorValues[0]>sensorValues[1] && sensorValues[0]>sensorValues[2] && sensorValues[0]>sensorValues[3]){
    Serial.println("maxpin : A0");
  }
  else if(sensorValues[1]>sensorValues[0]  && sensorValues[1]>sensorValues[2] && sensorValues[1]>sensorValues[3]){
    Serial.println("maxpin : A1");
  }
  else if(sensorValues[2]>sensorValues[0]  && sensorValues[2]>sensorValues[1] && sensorValues[2]>sensorValues[3]){
    Serial.println("maxpin : A2");
  }
  else if(sensorValues[3]>sensorValues[0]  && sensorValues[3]>sensorValues[1] && sensorValues[3]>sensorValues[2]){
    Serial.println("maxpin : A3");
  }
  delay(1000);
}