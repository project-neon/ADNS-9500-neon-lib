#include "MouseSensorADNS9500.hpp"

// value ranges from 90 up to 5040cpi
int cpi = 1800;

// converts measures from the sensor to cm, still not validated
float_t CPItoCM(int16_t counts) {
  return 2.54*(counts/((float_t) cpi));
}

// converts measures from the sensor to mm, still not validated
float_t CPItoMM(int16_t counts) {
  return 25.4*(counts/((float_t) cpi));
}

void setup() {
  // Initialize Serial
  Serial.begin(115200);

  // Initialize Mouse Sensor, desired cpi is required as argument
  mouseInit(cpi);
}

void loop() {
  // Read mouse motion
  int16_t dx = 0;
  int16_t dy = 0;

  mouseReadXY(&dx, &dy);

  Serial.print(dx);
  Serial.print("   ");
  Serial.println(dy);
  delay(100);
}