const int sensor_IR = 2;

void set_IR()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); 
  pinMode(sensor_IR, INPUT);
}

void run_IR()
{
  int hasil = digitalRead(sensor_IR);
  if(hasil == LOW)
  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("0");
  }
  if(hasil == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("1");
  }
  delay(250);
}