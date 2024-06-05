void pressure(){
 
  sensorValues[0] = analogRead(PressurePin[0]);
  sensorValues[1] = analogRead(PressurePin[1]);


  weight[0]=(sensorValues[0]/1023)*9.9;
  weight[1]=(sensorValues[1]/1023)*9.9;

  percentage[0]=198*weight[0];
  percentage[1]=198*weight[1];

  Serial.print(sensorValues[0]);
  Serial.print(" Pressure0 ");
  Serial.print(int(percentage[0]));
  Serial.print(" % ");

  Serial.print(" Pressure1 ");
  Serial.print(int(percentage[1]));
  Serial.print(" % ");

  Ser.print("Pressure0");
  Ser.print(":");
  Ser.println(int(percentage[0]));
  
  Ser.print("Pressure1");
  Ser.print(":");
  Ser.println(int(percentage[1]));

  if(sensorValues[0]>sensorValues[1]){
    Serial.println("maxpin : A0");
    command="A1";
  }
  else if(sensorValues[1]>sensorValues[0]){
    Serial.println("maxpin : A1");
    command="A2";
  }
  
  strcpy(cmd,command.c_str());
  rf95.send((uint8_t*)cmd,strlen(cmd));
  rf95.waitPacketSent();
  delay(1000);
}