#include <Arduino.h>
#include "ble_service.h"

BleService bleService;

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("VitaBand ESP32 prototype");
  bleService.begin();
}

unsigned long lastMillis = 0;
float t = 0.0;

void loop() {
  unsigned long now = millis();
  if(now - lastMillis > 1000) {
    lastMillis = now;
    // Simulate HR, SpO2, HRV
    int hr = 60 + (int)(10*sin(t));
    int spo2 = 97 + (int)(2*cos(t*0.6));
    int hrv = 40 + (int)(8*sin(t*0.4));
    t += 0.3;
    bleService.notifyVitals(hr, spo2, hrv);
    Serial.printf("Notify -> HR:%d SpO2:%d HRV:%d\n", hr, spo2, hrv);
  }
  delay(10);
}
