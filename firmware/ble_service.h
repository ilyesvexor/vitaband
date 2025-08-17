#pragma once
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

class BleService {
public:
  void begin();
  void notifyVitals(int hr, int spo2, int hrv);
private:
  BLEServer *pServer = nullptr;
  BLECharacteristic *pChar = nullptr;
};
