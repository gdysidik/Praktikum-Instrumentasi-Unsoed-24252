#include "Arduino.h"

#define VRX_PIN  A1 
#define VRY_PIN  A0 
#define SW 1

int xValue = 0; 
int yValue = 0; 
int SW_val = 0;

void set_joyStick() {
  Serial.begin(9600) ;
}

void run_joyStick() {
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);
  SW_val = digitalRead(SW);

  Serial.print("SW pin = ");
  Serial.print(SW_val);
  Serial.print(", x = ");
  Serial.print(xValue);
  Serial.print(", y = ");
  Serial.println(yValue);
  delay(200);
}