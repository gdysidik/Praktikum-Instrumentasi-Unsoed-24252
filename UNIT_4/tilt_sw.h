#include "Arduino.h"

#define tilt_sw 1
#define led 13

void set_tilt_sw() {
  pinMode(led, OUTPUT);
  pinMode(tilt_sw, INPUT);
  digitalWrite(led, 1);
}

void run_tilt_sw() {
  int val;
  val = digitalRead(tilt_sw);
  if (val == HIGH) {
    digitalWrite(led, 1);
  } else {
    digitalWrite(led, 0);
  }
}