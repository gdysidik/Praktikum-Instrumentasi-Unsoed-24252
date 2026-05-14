#include "Arduino.h"

const int lm35_pin = A0;	/* LM35 O/P pin */

void lm35_set() {
  Serial.begin(9600);
}

void lm35_main() {
  int temp_adc_val;
  float temp_val;
  temp_adc_val = analogRead(lm35_pin);	/* Read Temperature */
  temp_val = (temp_adc_val * 4.88);	/* Convert adc value to equivalent voltage */
  temp_val = (temp_val/10);	/* LM35 gives output of 10mv/°C */
  Serial.print("Temperature = ");
  Serial.println(temp_val);
  delay(500);
}