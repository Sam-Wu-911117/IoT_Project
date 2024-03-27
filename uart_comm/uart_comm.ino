#include <SoftwareSerial.h>
#include <SPI.h>
#include <MFRC522.h>  // 引用程式庫
#include <RH_RF95.h>

//softwareserial for LoRa
const byte RX = A0; //LoRa TX 
const byte TX = A1; //LoRa RX 
SoftwareSerial Lora(RX,TX);
RH_RF95<SoftwareSerial> rf95(Lora);

// const byte rxPin = A4; //gpio14
// const byte txPin = A5; //gpio15
// SoftwareSerial Ser(rxPin, txPin);

#define SS_PIN 10  // SDA
#define RST_PIN 9  //  RST
//SCK 13
//MOSI 11
//MISO 12
char *reference;
MFRC522 mfrc522(SS_PIN, RST_PIN);  // 創建MFRC522對象
const int MAX_CARDS = 4;  // 最大不同卡號數量
struct Card {
  String cardIDs;
  String cardNames;
};

Card cards[] = {
  { "E0DD9218" ,"num1" },{ "CC6F3BD5" ,"num2" },{ "8054E119" ,"num3" },{ "E0EAA718" ,"num4" }
};

//String cardIDs[MAX_CARDS] = { "E0DD9218", "CC6F3BD5", "8054E119", "E0EAA718" };  // 定義四個卡號ID
//String cardNames[MAX_CARDS] = { "num1", "num2", "num3", "num4" }; // 對應卡號名稱
int cardCounts[MAX_CARDS] = { 0,0,0,0 };

void setup() {
  SPI.begin();        // 初始化SPI
  mfrc522.PCD_Init(); // 初始化MFRC522
  rf95.setFrequency(433.0);
  // pinMode(rxPin, INPUT);
  // pinMode(txPin, OUTPUT);
  if (!rf95.init()) {
    Serial.println("init failed");
    while (1);
  }
  rf95.setFrequency(433.0);
  //Ser.begin(9600);
  Serial.begin(9600);           
  Serial.println("請放置卡片");  // 提示請放置卡片
  //while (!Ser) {}
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
      if (cardID == cards[i].cardIDs) {          //如果找到匹配的卡號
        Serial.print(cards[i].cardNames);        //輸出對應卡號名稱
        // if(Ser.available()){
        //   Ser.print(String(cardNames[i]));
        //   delay(1000);
        //   }
        //LoRa 送出 
        uint8_t cardName[i] = cards[i].cardNames;
        rf95.send(cardName,sizeof(cardName));
        rf95.waitPacketSent();

        // 等待回覆
        uint8_t buf[RH_RF95_MAX_MESSAGE_LEN];
        uint8_t len = sizeof(buf);
        if (rf95.waitAvailableTimeout(3000)) {
          if (rf95.recv(buf, &len)) {     //接收回覆
            Serial.print("got reply: ");
            Serial.println((char*)buf);
          } 
          else {
            Serial.println("recv failed");
          }
        } 
        else {
          Serial.println("No reply, is rf95_server running?");
        }
        delay(1000);
        Serial.print(": ");
        cardCounts[i]++;                // 將對應的計數器加一
        Serial.println(cardCounts[i]);  //輸出卡號計數器
        found = true;                   //標記找到匹配卡號
        break;
      }
    }
  }
  mfrc522.PICC_HaltA();  // 停止讀卡器
}