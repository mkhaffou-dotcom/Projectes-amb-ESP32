// Blinking LED with ESP32
// Define the pin connected to the LED
const int ledPin = 2;

void setup() {
    // Set the LED pin as an output
    pinMode(ledPin, OUTPUT);
}

void loop() {
    digitalWrite(ledPin, HIGH); // LED on
    delay(1000);
    digitalWrite(ledPin, LOW); // LED off
    delay(1000);
}
