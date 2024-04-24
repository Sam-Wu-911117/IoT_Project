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
  Serial.println(sensorValue);

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


/*int PR;
float weight;
double pressure;
float pressurepercentage;

void setup() {
  Serial.begin(9600);

}

void loop() {
  PR=analogRead(A0);
  //max 10kg
  //min 0.1kg
  weight=((float)PR/1024)*9.9;  //weight=((float)PR/1023)*9.9;
  //pressure=((weight/1.2668)*100);   //0.635*0.635*3.14=1.2668cm2=0.00012668m2 
  Serial.println(weight);
  //Serial.println(PR); 
  delay(300);
  
  if (weight>0.75)  
  {
    Serial.println("出動");
  }
  else
  {
    Serial.println("靜止");
    }
}*/
