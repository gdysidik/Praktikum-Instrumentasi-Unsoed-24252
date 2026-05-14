#include "sensor_air.h"
#include "sensor_api.h"
#include "sensor_mq2.h"

void setup() {
  air_set();
  api_set();
  mq2_set();
}

void loop() {
  mq2_main();
}