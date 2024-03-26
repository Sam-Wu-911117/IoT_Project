const int sensorPin = A0;  // 感測器引脚
int sensorValue;           // 感測器值
//const int motorPin = 9;  // 假設馬達連接到數字引腳9

void setup() {
  Serial.begin(9600);  
}

void loop() {
  sensorValue = analogRead(sensorPin);  // 讀取感測器值
  int percentage = map(sensorValue, 0, 1023, 0, 100);  // (把 value 從0到1023的範圍轉換成從1到100的範圍)
  Serial.print("Pressure Percentage: ");
  Serial.print(percentage);
  Serial.println("%");

  delay(500);
   if (percentage>1)  
  {
    Serial.println("出動");
    //analogWrite(motorPin, 255);  // 使用PWM全速運轉，根據需要調整速度
  }
  else
  {
    Serial.println("靜止");
    //analogWrite(motorPin, 0);  // 停止馬達
    }
}
