const int PressurePin[4] = {A0,A1,A2,A3};
const int numSensors = 4;
int sensorValues[numSensors]; 

// 定義壓力感測器的量程 (0.1kg ~ 10kg)
const float minPressure = 0.1; // 最小壓力（kg）
const float maxPressure = 10.0; // 最大壓力（kg）

void setup() {
  Serial.begin(9600);
  pinMode(PressurePin[0],INPUT);
  pinMode(PressurePin[1],INPUT);
  pinMode(PressurePin[2],INPUT);
  pinMode(PressurePin[3],INPUT);
}

void loop() {
  
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
    delay(1000);
  }
}
