// Karanlık alarmı: LDR + buzzer
// Bağlantılar:
//   5V -> R1 (10k) -> düğüm noktası -> LDR -> GND
//   Düğüm noktası -> A0
//   Buzzer (+) -> D8, Buzzer (-) -> GND
//
// Karanlıkta LDR'nin direnci yükselir, A0'daki değer artar.
// Değer ESIK'i geçince buzzer çalar.

const int LDR_PIN = A0;
const int BUZZER_PIN = 8;
const int ESIK = 600;  // Ortamına göre değiştir (0-1023 arası)

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int deger = analogRead(LDR_PIN);
  Serial.println(deger);  // Seri Monitör'den değeri izleyip ESIK'i ayarla

  if (deger > ESIK) {
    digitalWrite(BUZZER_PIN, HIGH);  // Aktif buzzer için
    // Pasif buzzer kullanıyorsan yukarıdaki satırı silip şunu kullan:
    // tone(BUZZER_PIN, 1000);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
    // Pasif buzzer kullanıyorsan: noTone(BUZZER_PIN);
  }

  delay(100);
}
