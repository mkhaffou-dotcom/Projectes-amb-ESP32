// setting pin numbers
const int potPin = 34; // potentiometer on GPIO 34 (ADC1_CH6)
const int ledPin = 16; // LED on GPIO 16

// setting PWM properties
const int freq = 1000;
const int ledChannel = 0;
const int resolution = 12; // 12-bit resolution (0 - 4095)

int potValue = 0;

void setup() {
    ledcSetup(ledChannel, freq, resolution);
    ledcAttachPin(ledPin, ledChannel);
    Serial.begin(115200);
    delay(500);
}

void loop() {
    potValue = analogRead(potPin);
    ledcWrite(ledChannel, potValue); // change the LED brightness
    Serial.println(potValue);
    delay(500);
}
