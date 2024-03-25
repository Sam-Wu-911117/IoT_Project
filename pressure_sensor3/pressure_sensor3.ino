int PR;
float weight;

void setup() {
  Serial.begin(9600);

}

void loop() {
  PR=analogRead(A0);
  //max 10kg
  //min 0.1kg
  weight=((float)PR/1024)*9.9;  //weight=((float)PR/1023)*9.9;
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
}
