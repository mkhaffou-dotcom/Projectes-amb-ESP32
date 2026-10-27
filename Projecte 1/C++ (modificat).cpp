// Modificacio: senyal SOS en codi morse
const int ledPin = 2;

Projectes ESP32 amb Wokwi - Mohamed - ICA1101 Pàgina 4
const int SHORT_MS = 200;
const int LONG_MS = 600;
const int GAP_MS = 200;

void pulse(int ms) {
    digitalWrite(ledPin, HIGH);
    delay(ms);
    digitalWrite(ledPin, LOW);
    delay(GAP_MS);
}

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    Serial.println("SOS");
    for (int i = 0; i < 3; i++) pulse(SHORT_MS); // S
    for (int i = 0; i < 3; i++) pulse(LONG_MS); // O
    for (int i = 0; i < 3; i++) pulse(SHORT_MS); // S
    delay(1500);
}
