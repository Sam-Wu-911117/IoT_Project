//1
const int pressureSensorPin = A0;

// 定義壓力感測器的量程 (0.1kg ~ 10kg)
const float minPressure = 0.1; // 最小壓力（kg）
const float maxPressure = 10.0; // 最大壓力（kg）

// 定義你所需的量程 (0.1kg ~ 1kg)
//const float minRequiredPressure = 0.1; // 最小壓力需求（kg）
//const float maxRequiredPressure = 1.0; // 最大壓力需求（kg）

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pressureSensorPin);
  
  float pressure = map(sensorValue, 0, 1023, minPressure, maxPressure); 

  if (pressure<=93){
    float percentage=pressure*(100/93);
    Serial.print("Pressure Percentage: ");
    Serial.print(percentage);
    Serial.println("%");
  }
  else
  {
    Serial.println("Pressure out of range!");
    //Serial.print("Pressure Percentage: ");
    //Serial.print(percentage);
    //Serial.println("%");
    }

  // 計算壓力的百分比
  //float percentage = ((pressure - minRequiredPressure) / (maxRequiredPressure - minRequiredPressure))*100 ; 
  
  delay(1000);
  

  /*if (percentage > 1)
  {
    Serial.println("出動");
    //analogWrite(motorPin, 255);  // 使用PWM全速運轉，根據需要調整速度
  }
  else
  {
    Serial.println("靜止");
    //analogWrite(motorPin, 0);  // 停止馬達
  }*/
}


/*
//2
const int pressureSensorPin = A0;

// 定義壓力感測器的量程 (0.1kg ~ 10kg)
const float minPressure = 0.1; // 最小壓力（kg）
const float maxPressure = 10.0; // 最大壓力（kg）

// 定義你所需的量程 (0.1kg ~ 1kg)
const float minRequiredPressure = 0.1; // 最小壓力需求（kg）
const float maxRequiredPressure = 1.0; // 最大壓力需求（kg）

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(pressureSensorPin);
  
  float pressure = map(sensorValue, 0, 1023, minPressure, maxPressure); 

  if (pressure >= minRequiredPressure && pressure <= maxRequiredPressure) {
    float percentage=pressure*(100/93);
    Serial.print("Pressure Percentage: ");
    Serial.print(percentage);
    Serial.println("%");
  } 
  else {
    Serial.println("Pressure out of range!");
  }
  
  delay(1000);
}*/
