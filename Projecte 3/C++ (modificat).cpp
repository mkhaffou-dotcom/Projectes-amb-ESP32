// Modificacio: humitat + LED d'alarma
// libraries.txt a Wokwi: DHT sensor library
#include <DHT.h>
#define DHTPIN 14
#define DHTTYPE DHT22
#define ALARM_PIN 2

const float LIMIT = 30.0; // graus C

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    pinMode(ALARM_PIN, OUTPUT);
    dht.begin();
}

void loop() {
    delay(2000);
    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h)) {
        Serial.println("Error de lectura del sensor");
        return;
    }
        Serial.printf("Temperatura: %.1f C | Humitat: %.1f %%\n", t, h);
        digitalWrite(ALARM_PIN, t > LIMIT ? HIGH : LOW);
}
