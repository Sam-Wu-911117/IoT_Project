void pressure(){
    for (int i = 0; i < numSensors; i++) {
    
    float pressure = map(sensorValues[i], 0, 1023, minPressure, maxPressure);
    sensorValues[i] = analogRead(PressurePin[i]);
    if (pressure<=93){
      
      float percentage=pressure*(100/93);
      Serial.print("Pressure ");
      Serial.print(i);
      Serial.print(" Percentage: ");
      Serial.print(percentage);
      Serial.println("%");
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
    else{
      Serial.println("Pressure out of range!");
    }
  }
}