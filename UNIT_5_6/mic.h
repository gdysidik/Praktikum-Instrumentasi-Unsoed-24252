// Pin untuk sensor mikrofon FC-04
#define MIC_PIN 2

// Konfigurasi deteksi frekuensi
#define SAMPLE_RATE 5000          // Frekuensi sampling (Hz)
#define SAMPLE_DURATION 100       // Durasi sampling (ms)
#define TARGET_FREQUENCY 440      // Frekuensi target (A4 = 440Hz)
#define TOLERANCE 20              // Toleransi frekuensi (Hz)

// Variabel untuk analisis frekuensi
unsigned int sampling_period_us;
unsigned long microseconds;
byte peak_count = 0;
bool last_state = false;
bool current_state = false;
unsigned long last_peak_time = 0;
unsigned long current_peak_time = 0;
float frequency = 0;

void set_mic() {
  Serial.begin(115200);
  sampling_period_us = round(1000000 * (1.0 / SAMPLE_RATE));
  
  Serial.println("Frekuensi Detector dengan Mikrofon FC-04");
  Serial.print("Target Frekuensi: ");
  Serial.print(TARGET_FREQUENCY);
  Serial.println(" Hz");
}

void run_mic() {
  // 1. Ambil sampel audio
  int samples[SAMPLE_DURATION * 1000 / sampling_period_us];
  unsigned long start_time = millis();
  
  for (int i = 0; i < sizeof(samples)/sizeof(int); i++) {
    microseconds = micros();
    samples[i] = analogRead(MIC_PIN);
    
    // Tunggu sampai periode sampling selesai
    while (micros() < (microseconds + sampling_period_us)) {
      // Tunggu
    }
  }
  
  // 2. Hitung frekuensi dominan dengan zero-crossing
  peak_count = 0;
  last_state = (samples[0] > 512);
  
  for (int i = 1; i < sizeof(samples)/sizeof(int); i++) {
    current_state = (samples[i] > 512);
    
    if (current_state != last_state) {
      peak_count++;
      last_state = current_state;
      
      if (peak_count == 1) {
        last_peak_time = i * sampling_period_us;
      } else if (peak_count == 2) {
        current_peak_time = i * sampling_period_us;
        break;
      }
    }
  }
  
  // 3. Hitung frekuensi jika terdeteksi
  if (peak_count >= 2) {
    frequency = 1000000.0 / (2 * (current_peak_time - last_peak_time));
    
    // 4. Bandingkan dengan frekuensi target
    Serial.print("Frekuensi Terdeteksi: ");
    Serial.print(frequency);
    Serial.print(" Hz | ");
    
    if (abs(frequency - TARGET_FREQUENCY) <= TOLERANCE) {
      Serial.println("COCOK dengan target!");
      // Tambahkan aksi yang diinginkan ketika frekuensi cocok
      digitalWrite(LED_BUILTIN, HIGH); // Nyala LED built-in
    } else {
      Serial.println("tidak cocok dengan target");
      digitalWrite(LED_BUILTIN, LOW); // Matikan LED built-in
    }
  } else {
    Serial.println("Tidak ada sinyal terdeteksi");
  }
  
  delay(200); // Jeda antara pengukuran
}