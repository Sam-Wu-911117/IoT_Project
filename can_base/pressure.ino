void pressure(){

  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(PressurePin[i]);
    float percentage = map(sensorValues[i], 0, 1023, 0, 100);
    
      Serial.print("Pressure ");
      Serial.print(i);
      Serial.print(" Percentage: ");
      Serial.print(int(percentage));
      Serial.println("%");

      Ser.print("Pressure");
      Ser.print(i);
      Ser.print(":");
      Ser.println(int(percentage));

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
    }
  delay(1000);
}