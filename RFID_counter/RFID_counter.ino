#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 mfrc522(SS_PIN, RST_PIN);                                               // 創建MFRC522對象

#define MAX_CARDS 4                                                             // 最大不同卡號數量

String cardIDs[MAX_CARDS] = {"E0DD9218", "CC6F3BD5", "8054E119", "E0EAA718"};
String cardNames[MAX_CARDS] = {"卡號一", "卡號二", "卡號三", "卡號四"};           // 不同卡號的類別
int cardCounts[MAX_CARDS] = {0};                                                // 每個卡號的計數器

void setup() {
  Serial.begin(9600);                                                           // 初始化串口通訊
  SPI.begin();                                                                  // 初始化SPI
  mfrc522.PCD_Init();                                                           // 初始化MFRC522

  Serial.println("請放置卡片");
  
}

void loop() {
   if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {      // 尋找新的RFID標籤
    String cardID = "";                                                         // 獲取RFID卡號
    for (byte i = 0; i < mfrc522.uid.size; i++) {
      cardID += String(mfrc522.uid.uidByte[i] < 0x10 ? "0" : "");
      cardID += String(mfrc522.uid.uidByte[i], HEX);
    }
    cardID.toUpperCase();                                                       // 將卡號轉換為大寫

    Serial.print("偵測卡片ID: ");
    Serial.println(cardID);

    bool found = false; 
    for (int i = 0; i < MAX_CARDS; i++) {                                       // 檢查卡號是否已存在於陣列中
      if (cardID == cardIDs[i]) {
        Serial.print(cardNames[i]);
        Serial.print(": ");
        cardCounts[i]++;                                                        // 將對應的計數器加一
        Serial.println(cardCounts[i]);
        found = true;
        break;
      }
    }


    mfrc522.PICC_HaltA();                                                       // 停止標籤
  }
}