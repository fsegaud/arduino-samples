#include <OneWire.h>
#include <DallasTemperature.h>

const int TMP_PIN = 2;
const int TMP_PRECISION_BITS = 12;

OneWire oneWire(TMP_PIN);
DallasTemperature ds(&oneWire);
DeviceAddress addr;

void setup() {
  Serial.begin(9600);
  ds.begin();
  ds.getAddress(addr, 0);
  ds.setResolution(addr, TMP_PRECISION_BITS);
}

void loop() {
  ds.requestTemperatures();
  float temp = ds.getTempCByIndex(0);
  Serial.print("DS18B20:");
  Serial.println(temp);
  delay(1000);
}
