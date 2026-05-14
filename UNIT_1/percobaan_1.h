#include <Arduino.h>

#define pot A1
#define LED 13

void setNO1() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
}

void NO1_main(){
  float al = analogRead(pot);;
  Serial.println(al);
  if (al >= 537)
    digitalWrite (LED, 1);
  else 
    digitalWrite (LED , 0);
  delay(500);
}