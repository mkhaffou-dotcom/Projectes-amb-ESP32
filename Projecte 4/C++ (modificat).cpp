// Modificacio: percentatge de brillantor pel monitor serie
const int potPin = 34;
const int ledPin = 16;

const int freq = 1000;
const int ledChannel = 0;
const int resolution = 12; // 0 - 4095

int potValue = 0;

void setup() {
    ledcSetup(ledChannel, freq, resolution);
    ledcAttachPin(ledPin, ledChannel);
    Serial.begin(115200);
    delay(500);
}

void loop() {
    potValue = analogRead(potPin);
    ledcWrite(ledChannel, potValue);

    int percent = potValue * 100 / 4095;
    Serial.printf("Lectura: %d | Brillantor: %d %%\n", potValue, percent);
    delay(200);
}
