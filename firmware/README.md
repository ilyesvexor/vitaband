Firmware scaffold for ESP32 (Arduino core)

Files:
- main.cpp: example sketch that advertises a BLE service providing mock HR/SpO2 and HRV values.
- ble_service.h / ble_service.cpp: BLE helper to create service and notify characteristics.

Build:
1. Install Arduino core for ESP32 in Arduino IDE or use PlatformIO.
2. Open firmware/main.cpp, choose your ESP32 board and upload.

Notes: This is a prototype scaffold and sends simulated sensor values. Replace with actual sensor reading code (MAX30102, BME680) in production.
