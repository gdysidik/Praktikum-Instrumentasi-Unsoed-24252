#include "Arduino.h"

#define pb 1
#define LED 13

void set_pb() {
  pinMode(pb, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void run_pb() {
  if(!digitalRead(pb)) {
    digitalWrite(LED, 1);
  }
  else {
    digitalWrite(LED, 0);
  }
}