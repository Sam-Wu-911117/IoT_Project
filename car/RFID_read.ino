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
      if (cardID == cardIDs[i]) {          //如果找到匹配的卡號
        Serial.print(cardNames[i]);        //輸出對應卡號名稱
        if (Ser.available()) {
          Ser.print(String(cardNames[i]));
          delay(1000);
        }
        Serial.print(": ");
        cardCounts[i]++;                // 將對應的計數器加一
        Serial.println(cardCounts[i]);  //輸出卡號計數器
        found = true;                   //標記找到匹配卡號
        break;
      }
    }
  }
}