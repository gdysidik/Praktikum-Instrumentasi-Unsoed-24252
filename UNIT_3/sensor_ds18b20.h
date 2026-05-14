#include "Arduino.h"
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensorDS18B20(&oneWire);

void ds_set(void)
{
  Serial.begin(9600);
  sensorDS18B20.begin();
}

void ds_main(void)
{
  sensorDS18B20.requestTemperatures();

  Serial.print("Suhu: ");
  Serial.println(sensorDS18B20.getTempCByIndex(0));
  delay(500);
}