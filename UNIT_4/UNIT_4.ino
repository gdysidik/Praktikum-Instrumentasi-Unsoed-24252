// #include "pb.h"
#include "mercury_sw.h"
// #include "reed_sw.h"
// #include "shock_sw.h"
#include "joyStick.h"

void setup() {
  set_joyStick();
  // set_mercury_sw();
  // set_pb();
  // set_reed_sw();
  // set_shock_sw();
  // set_tilt_sw();
}

void loop() {
  run_joyStick();
  // run_mercury_sw();
  // run_pb();
  // run_reed_sw();
  // run_shock_sw();
  // run_tilt_sw();
}