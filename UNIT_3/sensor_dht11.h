#include "Arduino.h"
#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void dht_set() {

  Serial.begin(9600);

  Serial.println("DHT11 test!");

  dht.begin();

}

void dht_main() {
  delay(500);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {

    Serial.println("Failed to read from DHT sensor!");

    return;

  }

  Serial.print("Humidity: ");

  Serial.print(h);

  Serial.print(" %\t");

  Serial.print("Temperature: ");

  Serial.print(t);

  Serial.println(" *C");

}