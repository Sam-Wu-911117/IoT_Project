void rfidRead() {
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
        //LoRa 送出 
        char cardName[RH_RF95_MAX_MESSAGE_LEN];
        strcpy(cardName, cards[i].cardNames.c_str());
        rf95.send((uint8_t*)cardName, strlen(cardName));
        rf95.waitPacketSent();
        
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