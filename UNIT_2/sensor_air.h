#include "Arduino.h"

const int sensorPin_air = A0;
int sensorValue_air;

void air_set() {
  Serial.begin(9600);
}

void air_main() {
  sensorValue_air = analogRead(sensorPin_air);
  Serial.println(sensorValue_air);
  delay(500);
}