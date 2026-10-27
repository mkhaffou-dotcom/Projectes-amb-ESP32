#include <Arduino.h>

// Pin where the push button is connected
const int buttonPin = 4;
// Pin where the LED is connected
const int ledPin = 2;

void setup() {
    // Internal pull-up: not pressed -> HIGH, pressed -> LOW
    pinMode(buttonPin, INPUT_PULLUP);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == LOW) { // Button is pressed
        digitalWrite(ledPin, HIGH); // LED on
    } else {
        digitalWrite(ledPin, LOW); // LED off
    }
}
