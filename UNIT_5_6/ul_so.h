#include<UltraDistSensor.h>
UltraDistSensor mysensor;
float reading;
void set_ul_so() {
    Serial.begin(9600);
    mysensor.attach(2,3);//Trigger pin , Echo pin
}

void run_ul_so() {
    reading=mysensor.distanceInCm();
    Serial.print("Sensor Reading :");Serial.print(reading);Serial.println(" CM");
    delay(200);
}