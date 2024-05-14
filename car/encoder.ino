//unsigned int count=0;//圈數
//int counterPin = 2;//編碼器接腳
//unsigned int Encoder_O;// 當前編碼器信號
//const byte IA = 7; // 馬達的正轉接腳
//const byte EA = 6;// 馬達的 pwm 接腳
//int Encoder;
//void setup() {
// Serial.begin(9600);
// pinMode(counterPin, INPUT);
// attachInterrupt(digitalPinToInterrupt(counterPin),blink,CHANGE);
// count = 0;
// Encoder = 0;
//}
//void sketch() {
//  if(count<10000){
//    analogWrite(EA, 150); // 馬達 的 PWM 輸出
//    digitalWrite(IA, HIGH); //
//    Serial.print(Encoder); 
//    Serial.print(";");
//    Serial.println(count);
//  }
//  else if(){
//    analogWrite(EA, 0); // 馬達 的 PWM 輸出
//    count=0;
//    Encoder = 0;
//  }
// }

//void backsketch() {
//  if(count<10000){
//    analogWrite(EA, 150); // 馬達 的 PWM 輸出
//    digitalWrite(IA, LOW); //
//    Serial.print(Encoder); 
//    Serial.print(";");
//    Serial.println(count);
//  }
//  else if(){
//    analogWrite(EA, 0); // 馬達 的 PWM 輸出
//    count=0;
//    Encoder = 0;
//  }
// }
//void blink(){
//  if(digitalRead(2) == HIGH){
//  Encoder=Encoder+1;
//  if(Encoder == 2000){
//  count=count+1;
//  Encoder = 0;
//  }
//}
//}
