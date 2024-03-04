unsigned long ping1() {
    digitalWrite(trigPin1, HIGH); // 觸發腳位設定為高電位
    delayMicroseconds(10); // 持續10微秒
    digitalWrite(trigPin1, LOW);
    return (pulseIn(echoPin1, HIGH) / 58.2); // 換算成 cm 並傳回
}

unsigned long ping2() {
    digitalWrite(trigPin2, HIGH); // 觸發腳位設定為高電位
    delayMicroseconds(10); // 持續10微秒
    digitalWrite(trigPin2, LOW);
    return (pulseIn(echoPin2, HIGH) / 58.2); // 換算成 cm 並傳回
}

unsigned long ping3() {
    digitalWrite(trigPin3, HIGH); // 觸發腳位設定為高電位
    delayMicroseconds(10); // 持續10微秒
    digitalWrite(trigPin3, LOW);
    return (pulseIn(echoPin3, HIGH) / 58.2); // 換算成 cm 並傳回
}