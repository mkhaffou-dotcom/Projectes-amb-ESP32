#include <DHT.h>
#define DHTPIN 14
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    Serial.begin(115200);
    Serial.println("Hello, ESP32!");
    dht.begin();
}

void loop() {
    delay(2000);
    float temperature = dht.readTemperature();

    // check for nan (not a number): not connected or failed
    if (isnan(temperature)) {
        Serial.println("Failed to read from DHT sensor.");
        return;
}

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
}
