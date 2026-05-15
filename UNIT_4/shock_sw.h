#include "Arduino.h"

#define shock_sw 1
#define led 13

void set_shock_sw() {
  pinMode(led, OUTPUT);
  pinMode(shock_sw, INPUT);
  digitalWrite(led,1);
}

void run_shock_sw() {
  digitalWrite(led, digitalRead(shock_sw));
}