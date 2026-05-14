#include <Arduino.h>

void setNO2() {
  Serial.begin(9600);
  DDRD = B11111111;
}

void NO2_main() {
  for(int i = 0; i < 256; i++) {
    PORTD = i;
    delay(500);
    Serial.println(analogRead(A0));
  }
}