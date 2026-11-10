#define BUTTON_PIN 13 // GPIO21 pin connected to button
#define DEBOUNCE_TIME 50 // debounce time in milliseconds

/*
Projecte: Button amb comptador de pulsacions
Descripció: Llegeix un botó amb debounce per programari i compta
quantes vegades s'ha premut. El resultat es mostra pel monitor sèrie.
Placa: ESP32
Data: 10/11/2026
*/
#define BUTTON_PIN 13 // GPIO13: pin connectat al botó
#define DEBOUNCE_TIME 50 // temps de debounce en mil·lisegons

// Variables per a la lògica de debounce
// Amb INPUT_PULLUP, en repòs el pin val HIGH
int lastSteadyState = HIGH;
int lastFlickerableState = HIGH;
int currentState;
unsigned long lastDebounceTime = 0;

// Nombre de vegades que s'ha premut el botó
int comptador = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.println("Comptador de pulsacions iniciat");
}

// Retorna true una sola vegada cada cop que es prem el botó
bool button() {
  currentState = digitalRead(BUTTON_PIN);

  if (currentState != lastFlickerableState) {
    lastDebounceTime = millis();
    lastFlickerableState = currentState;
}

  if ((millis() - lastDebounceTime) > DEBOUNCE_TIME) {
    if (lastSteadyState != currentState) {
      lastSteadyState = currentState;
      return (currentState == LOW);
    }
  }
  return false;
}

// Mostra el valor del comptador pel monitor sèrie
void mostrarComptador() {
  Serial.print("Botó premut. Total de pulsacions: ");
  Serial.println(comptador);
}

void loop() {
  if (button()) {
    comptador++;
    mostrarComptador();
  }
}