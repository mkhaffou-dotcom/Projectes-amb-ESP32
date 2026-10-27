// Modificacio: commutacio amb flanc + comptador de pulsacions
const int buttonPin = 4;
const int ledPin = 2;

bool ledState = false;
int lastButton = HIGH;
int pressCount = 0;

void setup() {
    Serial.begin(115200);
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int current = digitalRead(buttonPin);

    if (lastButton == HIGH && current == LOW) { // flanc de baixada
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        pressCount++;
        Serial.printf("Pulsacions: %d | LED %s\n", pressCount, ledState ? "ON" : "OFF");
        delay(30); // antirebot
    }
    lastButton = current;
}
