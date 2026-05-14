#include "Arduino.h"
#include <MQ2.h>

//change this with the pin that you use
int mq2_pin = A2;
int lpg, co, smoke;

MQ2 mq2(mq2_pin);

void mq2_set() {
  Serial.begin(9600);
  mq2.begin();
}

void mq2_main() {
  /*read the values from the sensor, it returns
  *an array which contains 3 values.
  * 1 = LPG in ppm
  * 2 = CO in ppm
  * 3 = SMOKE in ppm
  */
  // float* values = mq2.read(true);  //set it false if you don't want to print the values in the Serial

  lpg = mq2.readLPG();
  co = mq2.readCO();
  smoke = mq2.readSmoke();
  Serial.print("LPG: ");
  Serial.println(lpg);
  Serial.print("CO: ");
  Serial.println(co);
  Serial.print("SMOKE: ");
  Serial.println(smoke);
  delay(500);
}