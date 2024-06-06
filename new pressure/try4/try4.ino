const int fsrPin1 = A0;  // 第一個 FSR402 連接到模擬輸入 A0
const int fsrPin2 = A1;  // 第二個 FSR402 連接到模擬輸入 A1
int fsrValueBefore1 = 0;
int fsrValueBefore2 = 0;
int fsrValueAfter1 = 0;
int fsrValueAfter2 = 0;

void setup() {
  Serial.begin(9600); // 初始化串行通訊
  pinMode(fsrPin1,INPUT);
  pinMode(fsrPin2,INPUT);
}

void loop() {
  // 讀取第一個壓力感測器在壓力之前的值
  fsrValueBefore1 = analogRead(fsrPin1);
  Serial.print("第一個壓力感測器壓之前的壓力值: ");
  Serial.println(fsrValueBefore1);

  // 讀取第二個壓力感測器在壓力之前的值
  fsrValueBefore2 = analogRead(fsrPin2);
  Serial.print("第二個壓力感測器壓之前的壓力值: ");
  Serial.println(fsrValueBefore2);

  // 模擬施加壓力，可以用延時來模擬
  delay(4000); // 等待4秒鐘施加壓力

  // 讀取第一個壓力感測器在壓力之後的值
  fsrValueAfter1 = analogRead(fsrPin1);
  Serial.print("第一個壓力感測器壓之後的壓力值: ");
  Serial.println(fsrValueAfter1);

  // 讀取第二個壓力感測器在壓力之後的值
  fsrValueAfter2 = analogRead(fsrPin2);
  Serial.print("第二個壓力感測器壓之後的壓力值: ");
  Serial.println(fsrValueAfter2);

  // 計算第一個壓力感測器的壓力變化量
  int deltaPressure1 = abs(fsrValueAfter1 - fsrValueBefore1);
  Serial.print("第一個壓力感測器壓力變化量: ");
  Serial.println(deltaPressure1);

  // 計算第二個壓力感測器的壓力變化量
  int deltaPressure2 = abs(fsrValueAfter2 - fsrValueBefore2);
  Serial.print("第二個壓力感測器壓力變化量: ");
  Serial.println(deltaPressure2);

  // 如果任一個壓力感測器的壓力變化量超過103，列印 "收垃圾" 訊息
  if (deltaPressure1 > 144 || deltaPressure2 > 270) {
    Serial.println("收垃圾");
  }

  // 停止一段時間再進行下一次測量
  delay(8000); //8秒鐘
}
