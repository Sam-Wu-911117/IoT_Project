/*const int sensorPin[] = {A0, A1};  // 感測器引腳
const int numSensors = 2;  // 感測器數量

int sensorValues[numSensors];  // 用於存儲感測器值的數組

// 定義壓力感測器的量程 (0.1kg ~ 10kg)
const float minPressure = 0.1; // 最小壓力（kg）
const float maxPressure = 10.0; // 最大壓力（kg）

void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numSensors; i++) {
    sensorValues[i] = analogRead(sensorPin[i]);
    delay(10);
  }

  for (int i = 0; i < numSensors; i++) {
    float pressure = map(sensorValues[i], 0, 1023, minPressure, maxPressure);

    // 找出最大的感測器引腳
    int maxPin;
    if (A0 > A1 && A0 > A2 ) {
      maxPin = A0;
    }
    else if (A1 > A0 && A1 > A2 ) {
      maxPin = A1;
    }
    /*if(A2>A0 && A2>A1 && A2>A3){
      maxPin=A2;
      }
      if(A3>A0 && A3>A1 && A3>A2){
      maxPin=A3;
      }

    if (pressure <= 93) {
      float percentage = pressure * (100 / 93);
      //Serial.print("感測器 ");
      //Serial.print(maxPin);
      //Serial.print("Pressure Percentage: ");
      //Serial.print(percentage);
      //Serial.println("%");

      Serial.print("最大感測器 ");
      Serial.println(maxPin);
      Serial.print("Pressure Percentage: ");
      Serial.print(percentage);
      Serial.println("%");

    }
    else
    {
      Serial.println("Pressure out of range!");
    }
    delay(1000);
  }
}*/



//2
const int pressureSensorPin1 = A0; // 感測器引腳
const int pressureSensorPin2 = A1; // 感測器引腳

const int numSensors = 2;  // 感測器數量

int sensorValues[numSensors];  // 用於存儲感測器值的數組

// 定義壓力感測器的量程 (0.1kg ~ 10kg)
const float minPressure = 0.1; // 最小壓力（kg）
const float maxPressure = 10.0; // 最大壓力（kg）
int sensorValue1=0;
int sensorValue2=0;
float pressure1=0;
float pressure2=0;
void setup() {
  Serial.begin(9600);
  pinMode(pressureSensorPin1,INPUT);
  pinMode(pressureSensorPin2,INPUT);
}

void loop() {
  sensorValue1= analogRead(pressureSensorPin1);
  delay(10);
  sensorValue2 = analogRead(pressureSensorPin2);
  
  pressure1=map(sensorValues1, 0, 1023, minPressure, maxPressure);//PR=0~1023-->Kg=0.1~10

  for (int i = 0; i < numSensors; i++) {
    float pressure[i] = map(sensorValues[i], 0, 1023, minPressure, maxPressure);//PR=0~1023-->Kg=0.1~10

    // 找出最大的感測器引腳

    if (pressure[0] > pressure[1] ) {
      sensorPin[0];
    }
    else if (pressure[1] > pressure[0] ) {
      sensorPin[1];
    }
    /*if(A2>A0 && A2>A1 && A2>A3){
      maxPin=A2;
      }
      if(A3>A0 && A3>A1 && A3>A2){
      maxPin=A3;
      }*/

    if (pressure <= 93) {
      float percentage = pressure * (100 / 93);
      //Serial.print("感測器 ");
      //Serial.print(maxPin);
      //Serial.print("Pressure Percentage: ");
      //Serial.print(percentage);
      //Serial.println("%");

      Serial.print("最大感測器 ");
      Serial.println(maxPin);
      Serial.print("Pressure Percentage: ");
      Serial.print(percentage);
      Serial.println("%");

    }
    else
    {
      Serial.println("Pressure out of range!");
    }
    delay(1000);
  }
}
