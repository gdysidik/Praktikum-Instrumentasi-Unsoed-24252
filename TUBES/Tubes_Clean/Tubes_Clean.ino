#define ena 15
#define in3 2
#define IR_SENSOR_PIN 16
#define ser 14
#define ledR 13
#define ledG 12
#define ledB 0

#define BLYNK_TEMPLATE_ID "TMPL6rJJKcwSw"
#define BLYNK_TEMPLATE_NAME "TUBES INSTRUMENTASI V2"
#define BLYNK_AUTH_TOKEN "YgefS2EhGbwDRdiD_jNGD2Kr1rX0IJMk"

#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

Servo s;
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int LDR_pin = A0;
const int k = 15;
int counter[] = { 0, 0, 0 };      // R-G-B
bool list_warna[] = { 0, 0, 0 };  // R-G-B
int cek = 0;
int reset_barang = 0;
int on_off = 1;

char ssid[] = "Giganiggas";
char pass[] = "brebes26";

void reset_warna() {
  list_warna[0] = 0;
  list_warna[1] = 0;
  list_warna[2] = 0;
  Blynk.virtualWrite(V4, list_warna[0]);
  Blynk.virtualWrite(V5, list_warna[1]);
  Blynk.virtualWrite(V6, list_warna[2]);
}

void reset_counter() {
  counter[0] = 0;
  counter[1] = 0;
  counter[2] = 0;
  Blynk.virtualWrite(V1, counter[0]);
  Blynk.virtualWrite(V2, counter[1]);
  Blynk.virtualWrite(V3, counter[2]);
}

void tampilLCD(const char* baris1, const char* baris2) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(baris1);
  lcd.setCursor(0, 1);
  lcd.print(baris2);
}

void setup() {
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  s.attach(ser, 500, 2400);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);

  Serial.begin(115200);

  pinMode(IR_SENSOR_PIN, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);

  lcd.print("STARTING...");
  s.write(0);
  delay(3000);

  reset_warna();
  reset_counter();
}

void loop() {
  Blynk.run();

  reset_warna();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Menunggu objek..");

  if (on_off == 0) {
    analogWrite(ena, 0);
    tampilLCD("SISTEM OFF", "Tunggu tombol ON");
    delay(500);
    return;
  } else {
    analogWrite(ena, 90);
  }
  if (reset_barang == 1) {
    reset_counter();
    reset_barang = 0;
  }

  int irStatus = digitalRead(IR_SENSOR_PIN);
  if (irStatus == LOW && cek == 0) {
    analogWrite(ena, 0);
    digitalWrite(in3, 0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Objek Terdeteksi");
    lcd.setCursor(0, 1);
    lcd.print("Analisa warna...");
    delay(500);

    digitalWrite(ledR, 1);
    int ldrValR = analogRead(LDR_pin);
    delay(100);
    digitalWrite(ledR, 0);
    delay(50);
    int ldrVal_mapR = map(ldrValR, 0, 1023, 0, 255);

    digitalWrite(ledG, 1);
    int ldrValG = analogRead(LDR_pin);
    delay(100);
    digitalWrite(ledG, 0);
    delay(50);
    int ldrVal_mapG = map(ldrValG, 0, 1023, 0, 255);

    digitalWrite(ledB, 1);
    int ldrValB = analogRead(LDR_pin);
    delay(100);
    digitalWrite(ledB, 0);
    delay(50);
    int ldrVal_mapB = map(ldrValB, 0, 1023, 0, 255);

    Serial.print(ldrVal_mapR);
    Serial.print("\t");
    Serial.print(ldrVal_mapG);
    Serial.print("\t");
    Serial.println(ldrVal_mapB);

    if (abs(ldrVal_mapR - 93) < k && abs(ldrVal_mapG - 196) < k && abs(ldrVal_mapB - 184) < k) {
      Serial.println(" -> WARNA MERAH!\n");
      tampilLCD("WARNA: MERAH", "Sortir Wadah A");

      list_warna[0] = 1;
      counter[0]++;
      delay(300);
      s.write(30);

      Blynk.virtualWrite(V1, counter[0]);
      Blynk.virtualWrite(V4, list_warna[0]);

    } else if (abs(ldrVal_mapR - 87) < k && abs(ldrVal_mapG - 175) < k && abs(ldrVal_mapB - 200) < k) {
      Serial.println(" -> WARNA HIJAU !\n");
      tampilLCD("WARNA: HIJAU", "Sortir Wadah B");

      list_warna[1] = 1;
      counter[1]++;
      delay(300);
      s.write(90);

      Blynk.virtualWrite(V2, counter[1]);
      Blynk.virtualWrite(V5, list_warna[1]);

    } else if (abs(ldrVal_mapR - 74) < k && abs(ldrVal_mapG - 169) < k && abs(ldrVal_mapB - 195) < k) {
      Serial.println(" -> WARNA BIRU !\n");
      tampilLCD("WARNA: BIRU", "Sortir Wadah C");

      list_warna[2] = 1;
      counter[2]++;
      delay(300);
      s.write(150);

      Blynk.virtualWrite(V3, counter[2]);
      Blynk.virtualWrite(V6, list_warna[2]);

    } else {
      Serial.println("bingung");
      tampilLCD("HMM...", "Ke mana yaa??");

      reset_warna();
      delay(300);
    }

    if (list_warna[0] == 1 || list_warna[1] == 1 || list_warna[2] == 1) {
      cek++;
      delay(2000);
    }
  } else if (cek == 0) {
    analogWrite(ena, 90);
    digitalWrite(in3, 0);
  }

  if (cek != 0) {
    analogWrite(ena, 90);
    digitalWrite(in3, 0);
    cek = 0;
    delay(500);
  }
  delay(200);
}

BLYNK_WRITE(V0) {
  on_off = param.asInt();
}

BLYNK_WRITE(V7) {
  reset_barang = param.asInt();
}