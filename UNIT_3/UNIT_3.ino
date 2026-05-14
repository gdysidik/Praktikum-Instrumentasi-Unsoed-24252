#include "sensor_dht11.h"
#include "sensor_ds18b20.h"
#include "sensor_lm35.h"

void setup() {
  dht_set();
  lm35_set();
  ds_set();
}

void loop() {
  lm35_main();
}
