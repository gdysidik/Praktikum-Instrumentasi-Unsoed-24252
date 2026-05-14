#include "Arduino.h"

const int sensorPin_api = A1, led = 13;
int sensorValue_api;

void api_set() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
}

void api_main() {
  sensorValue_api = analogRead(sensorPin_api);
  Serial.println(sensorValue_api);
  if (sensorValue_api <= 1023 && sensorValue_api > 700) {
    digitalWrite(led, 1);
    delay(1000);
    digitalWrite(led, 0);
    delay(1000);
  } else if (sensorValue_api <= 700 && sensorValue_api > 400) {
    digitalWrite(led, 1);
    delay(500);
    digitalWrite(led, 0);
    delay(500);
  } else {
    digitalWrite(led, 1);
    delay(100);
    digitalWrite(led, 0);
    delay(100);
  }
  delay(100);
}