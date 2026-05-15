#include "Arduino.h"

#define reed_sw 1
#define led 13

void set_reed_sw() {
  pinMode(led, OUTPUT);
  pinMode(reed_sw, INPUT);
  digitalWrite(led,1);
}

void run_reed_sw() {
  digitalWrite(led, digitalRead(reed_sw));
}