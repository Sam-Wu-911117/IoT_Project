void pressure(){

  fsrValuesBefore[0]=analogRead(PressurePin[0]);
  Serial.print(fsrValuesBefore[0]);
  fsrValuesAfter[0]=analogRead(PressurePin[0]);

  fsrValuesBefore[1]=analogRead(PressurePin[0]);
  Serial.print(fsrValuesBefore[1]);
  fsrValuesAfter[1]=analogRead(PressurePin[1]);

  deltaValue[0]=fsrValuesAfter[0]-fsrValuesBefore[0];
  deltaValue[1]=fsrValuesAfter[1]-fsrValuesBefore[1];

  if(deltaValue[0] > 21 && deltaValue[0]>deltaValue[1]){
    command="A0";
    Ser.println(0);
  }
  if(deltaValue[0]<21){
    Ser.println(123);
  }
  if(deltaValue[1] > 21 && deltaValue[1]>deltaValue[0]){
    command="A1";
    Ser.println(1);
  }
  if(deltaValue[1]<21){
    Ser.println(456);
  }
  strcpy(cmd,command.c_str());
  rf95.send((uint8_t*)cmd,strlen(cmd));
  rf95.waitPacketSent();
  delay(1000);
}
