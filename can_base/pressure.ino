void pressure(){

  fsrValues1=analogRead(PressurePin[0]);
  //Serial.print(fsrValues1);
  
  deltaValue[0]=abs(fsrValues1-35);
  Serial.print("delta0:");
  Serial.println(deltaValue[0]);

  fsrValues2=analogRead(PressurePin[1]);
  //Serial.print(fsrValuesBefore[1]);
  
  deltaValue[1]=abs(fsrValues2-96);
  Serial.print("delta1:");
  Serial.println(deltaValue[1]);

  if(deltaValue[0]>144){
    command ="A";
    Serial.println("A");
    
  }

  if( deltaValue[1]>270){
    command = "B";
    Serial.println("B");
  }

  strcpy(cmd,command.c_str());
  rf95.send(cmd,sizeof(cmd));
  rf95.waitPacketSent();
  delay(1000);
}
