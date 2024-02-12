#include <MouseSensorADNS9500.hpp>

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Initialize Mouse Sensor
  mouseInit();
}

void loop() {
  // Read mouse motion
  int16_t dx = 0;
  int16_t dy = 0;
  mouseReadXY(dx, dy);
  Serial.print(dx);
  Serial.print("   ");
  Serial.println(dy);
  delay(100);
}