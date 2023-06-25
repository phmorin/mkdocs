/*
/ Utilisation de la fonction millis() pour gérer 
/ les feux de carrefour.
/ Philippe Morin - Lycée Jules Verne 
*/

#define feuRougeVoieA 5
#define feuOrangeVoieA 4
#define feuVertVoieA 3

unsigned long departCycle;

void setup() {
  pinMode(feuRougeVoieA, OUTPUT);
  pinMode(feuOrangeVoieA, OUTPUT);
  pinMode(feuVertVoieA, OUTPUT);
 
  departCycle = millis();
}

void loop() {
 
  // Extinction des feux :
  digitalWrite(feuRougeVoieA, LOW);
  digitalWrite(feuOrangeVoieA, LOW);
  digitalWrite(feuVertVoieA, LOW);
 
  // Comparaison du temps passé avec le départ du cycle :
  if (millis() < (departCycle + 3000)) {passageVoieA();}  
  if ((millis() >= (departCycle + 3000)) && (millis() < (departCycle + 4000))) {transitionVoieA(); }
  if ((millis() >= (departCycle + 4000)) && (millis() < (departCycle + 8000))) {arretVoieA();;}
  if (millis() > (departCycle + 8000)) {departCycle = millis();}
}

void passageVoieA() {
  digitalWrite(feuRougeVoieA, LOW);
  digitalWrite(feuOrangeVoieA, LOW);
  digitalWrite(feuVertVoieA, HIGH);
}
void transitionVoieA() {
  digitalWrite(feuRougeVoieA, LOW);
  digitalWrite(feuOrangeVoieA, HIGH);
  digitalWrite(feuVertVoieA, LOW);
}
void arretVoieA() {
  digitalWrite(feuRougeVoieA, HIGH);
  digitalWrite(feuOrangeVoieA, LOW);
  digitalWrite(feuVertVoieA, LOW);
}