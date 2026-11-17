/*
Projecte: Panell de codi amb KeyPad 4x4
Descripció: Valida un codi PIN introduït amb el teclat matricial.
  - Dígits i lletres: s'afegeixen al codi
  - #: valida el codi
  - *: esborra el que s'ha escrit
Placa: ESP32
Data: 12/11/2026
*/
#include <Keypad.h>

const uint8_t ROWS = 4;
const uint8_t COLS = 4;

char keys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

uint8_t rowPins[ROWS] = { 19, 18, 5, 17 };
uint8_t colPins[COLS] = { 16, 4, 2, 15 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Pins dels LEDs
const int LED_VERD = 23;
const int LED_VERMELL = 22;

// Paràmetres configurables
const String CODI_CORRECTE = "1234";
const int MAX_INTENTS = 3;
const int MAX_LONGITUD = 8;

String codiIntroduit = "";
int intentsFallits = 0;

// Accés correcte: encén el LED verd 2 segons
void accesCorrecte() {
  Serial.println("Codi correcte: accés concedit");
  intentsFallits = 0;
  digitalWrite(LED_VERD, HIGH);
  delay(2000);
  digitalWrite(LED_VERD, LOW);
}

// Accés denegat: parpelleja el LED vermell i, si hi ha massa
// intents fallits, bloqueja el teclat 5 segons
void accesDenegat() {
  intentsFallits++;
  Serial.print("Codi incorrecte. Intents fallits: ");
  Serial.println(intentsFallits);
  digitalWrite(LED_VERMELL, HIGH);
  delay(500);
  digitalWrite(LED_VERMELL, LOW);

  if (intentsFallits >= MAX_INTENTS) {
    Serial.println("Massa intents: teclat bloquejat 5 segons");
    digitalWrite(LED_VERMELL, HIGH);
    delay(5000);
    digitalWrite(LED_VERMELL, LOW);
    intentsFallits = 0;
    Serial.println("Teclat desbloquejat");
  }
}

// Compara el codi introduït amb el correcte
void validarCodi() {
  Serial.println();
  if (codiIntroduit == CODI_CORRECTE) {
    accesCorrecte();
  } else {
    accesDenegat();
  }
  codiIntroduit = "";
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_VERD, OUTPUT);
  pinMode(LED_VERMELL, OUTPUT);
  Serial.println("Introdueix el codi i prem # per validar (* per esborrar)");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == '#') {
      validarCodi();
    } else if (key == '*') {
      codiIntroduit = "";
      Serial.println();
      Serial.println("Codi esborrat");
    } else if (codiIntroduit.length() < MAX_LONGITUD) {
      codiIntroduit += key;
      Serial.print("*");   // no mostrem el codi real
    }
  }
}