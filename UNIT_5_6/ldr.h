int LDR = A0; //deklarasi LDR pada pin A5 Arduino


void set_ldr()

{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT); //deklarasi LED sebagai output

}


void run_ldr()

{

  int cahaya = analogRead(LDR); //membaca nilai ADC LDR

  //jika nilai ADC > 800 maka
  Serial.println(cahaya);

  if (cahaya > 200)

  {

   digitalWrite(LED_BUILTIN, HIGH); // LED_BUILTIN menyala

  }

  else //atau

  {

   digitalWrite(LED_BUILTIN, LOW); // LED mati

  }
  delay(100);
}