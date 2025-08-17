#include "ble_service.h"
#include <Arduino.h>

// UUIDs (example)
#define SERVICE_UUID "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
#define CHAR_UUID    "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"

void BleService::begin(){
  BLEDevice::init("VitaBand-ESP32");
  pServer = BLEDevice::createServer();
  BLEService *pService = pServer->createService(SERVICE_UUID);
  pChar = pService->createCharacteristic(
    CHAR_UUID,
    BLECharacteristic::PROPERTY_NOTIFY
  );
  pChar->addDescriptor(new BLE2902());
  pService->start();
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->start();
  Serial.println("BLE service started, advertising...");
}

void BleService::notifyVitals(int hr, int spo2, int hrv){
  if(!pChar) return;
  char buf[64];
  snprintf(buf, sizeof(buf), "{\"hr\":%d,\"spo2\":%d,\"hrv\":%d}", hr, spo2, hrv);
  pChar->setValue((uint8_t*)buf, strlen(buf));
  pChar->notify();
}
