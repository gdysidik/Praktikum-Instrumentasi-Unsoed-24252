#include "Arduino.h"

#define mercury_sw 1
#define led 13

void set_mercury_sw() {
  pinMode(led, OUTPUT);
  pinMode(mercury_sw, INPUT);
  digitalWrite(led, 1);
}

void run_mercury_sw() {
  int val;
  val = digitalRead(mercury_sw);
  if (val == HIGH) {
    digitalWrite(led, 1);
  } else {
    digitalWrite(led, 0);
  }
}