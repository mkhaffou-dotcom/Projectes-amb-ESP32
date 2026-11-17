////////////////Basic wifi Network test//////////////////
//Based in BasicHttpClient ESP32 board example //////////////
#include <WiFi.h>
#include <HTTPClient.h>

String message="";

void setup() {

    Serial.begin(115200);
    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    //Conect to wifi network
    WiFi.begin("Wokwi-GUEST", "");  //Wifi_Network, Wifi_Password ******CHANGE

    //Wait until connection
    while((WiFi.status() != WL_CONNECTED)) {
      delay(500);
      Serial.print(".");
    }
    
     Serial.println("Wifi conected");
    
}

void loop() {
    // wait for WiFi connection
    if((WiFi.status() == WL_CONNECTED)) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        
        // configure traged server and url
        message="http://example.com/index.html";  // Request Message Domain/page/request
        http.begin(message); //HTTP

        
        // start connection and send HTTP header, return error code
        int httpCode = http.GET();
        Serial.print("[HTTP] GET...\n");
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
        http.end();
    }

    delay(5000);
}