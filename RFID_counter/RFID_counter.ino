#include <SPI.h>
#include <MFRC522.h>  // 引用程式庫

#define SS_PIN 53  // 晶片選擇腳位 mega53 uno10
#define RST_PIN 5  // 讀卡機的重製腳位 mega5 un9
//SCK 13,MOSI 11,MISO 12 (uno)
//SCK 52,MOSI 51,MISO 50 (Mega)
MFRC522 mfrc522(SS_PIN, RST_PIN);  // 創建MFRC522對象

#define MAX_CARDS 4  // 最大不同卡號數量

String cardIDs[MAX_CARDS] = { "E0DD9218", "CC6F3BD5", "8054E119", "E0EAA718" };  // 定義四個卡號ID
String cardNames[MAX_CARDS] = { "1", "2", "3", "4" };        // 對應卡號名稱
int cardCounts[MAX_CARDS] = { 0 };                                               // 每個卡號的計數器

void setup() {
  Serial.begin(9600);            // 初始化串口通訊
  SPI.begin();                   // 初始化SPI
  mfrc522.PCD_Init();            // 初始化MFRC522
  Serial.println("請放置卡片");  // 提示請放置卡片
}

void loop() {
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {  // 偵測是否有新卡片並讀取ID
    String cardID = "";                                                    // 獲取RFID卡號
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");  // 將每個字節ID轉為字串
      cardID += String(mfrc522.uid.uidByte[i], HEX);
    }
    cardID.toUpperCase();  // 將卡號轉為大寫

    Serial.print("偵測卡片ID: ");  //輸出偵測到的卡面ID
    Serial.println(cardID);

    bool found = false;
    for (int i = 0; i < MAX_CARDS; i++) {  // 檢查卡號是否已存在於陣列中
      if (cardID == cardIDs[i]) {          //如果找到匹配的卡號
        Serial.print(cardNames[i]);        //輸出對應卡號名稱
        Serial.print(": ");
        cardCounts[i]++;                // 將對應的計數器加一
        Serial.println(cardCounts[i]);  //輸出卡號計數器
        found = true;                   //標記找到匹配卡號
        break;
      }
    }
    mfrc522.PICC_HaltA();  // 停止讀卡器
  }
}