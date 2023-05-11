const int TMP_PIN = 0;
const float TMP_MAGIC_NUMBER = 5.0 / 1024 * 100;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temp = TMP_MAGIC_NUMBER * analogRead(TMP_PIN) - 50;
  Serial.print("TMP36:");
  Serial.println(temp);
  delay(1000);
}
