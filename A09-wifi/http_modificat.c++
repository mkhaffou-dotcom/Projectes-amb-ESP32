/*
Projecte: HTTP GET amb ESP32 (modificat)
Descripció: Es connecta a la xarxa Wi-Fi de Wokwi i fa una petició HTTP GET
a example.com cada 10 segons. Mostra el codi de resposta, la mida de la
resposta i el nombre de peticions fetes. Afegeix una capçalera User-Agent
pròpia per poder identificar la petició amb Wireshark.
Placa: ESP32
*/
#include <WiFi.h>
#include <HTTPClient.h>

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASS = "";
const char* URL_PETICIO = "http://example.com/";
const unsigned long INTERVAL = 10000; // temps entre peticions (ms)

int comptadorPeticions = 0;

// Connecta a la xarxa Wi-Fi i mostra la IP assignada
void connectarWifi() {
  Serial.print("Connectant a la xarxa Wi-Fi");
  WiFi.begin(WIFI_SSID, WIFI_PASS, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Wi-Fi connectada. IP: ");
  Serial.println(WiFi.localIP());
}

// Tradueix el codi de resposta HTTP a un text
const char* descriuCodi(int codi) {
  if (codi == 200) return "OK";
  if (codi == 301 || codi == 302) return "Redireccio";
  if (codi == 404) return "No trobat";
  if (codi < 0) return "Error de connexio";
  return "Altre";
}

// Fa una petició HTTP GET i mostra el resultat pel monitor sèrie
void fesPeticio() {
  HTTPClient http;
  http.begin(URL_PETICIO);
  http.addHeader("User-Agent", "ESP32-Mohamed-ASIX");

  int codi = http.GET();
  comptadorPeticions++;

  Serial.print("Peticio #");
  Serial.print(comptadorPeticions);
  Serial.print(" - Codi HTTP: ");
  Serial.print(codi);
  Serial.print(" (");
  Serial.print(descriuCodi(codi));
  Serial.println(")");

  if (codi > 0) {
    String resposta = http.getString();
    Serial.print("Mida de la resposta (bytes): ");
    Serial.println(resposta.length());
  } else {
    Serial.print("Error: ");
    Serial.println(http.errorToString(codi));
  }
  http.end();
}

void setup() {
  Serial.begin(115200);
  connectarWifi();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    fesPeticio();
  } else {
    Serial.println("Wi-Fi desconnectada");
  }
  delay(INTERVAL);
}