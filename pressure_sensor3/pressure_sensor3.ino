const int sensorPin = A0;  // 感測器引脚
float sensorValue;           // 感測器值
float weight;
float percentage;

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);  // 讀取感測器值
  weight=(sensorValue/1023)*9.9;
  /*Max=10kg-->1023
    min=0.1kg-->0
   */
  
  if(weight>=0.1 && weight<=0.15){
    percentage=198*weight;
    Serial.print("Pressure Percentage: ");
    Serial.print(percentage);
    Serial.println("%");
    Serial.println(sensorValue);

  }
  else if(weight==0){
    Serial.println("0%");
  }
  else{
    Serial.println("Pressure out of range!");
  }
  
  delay(500);
  }
