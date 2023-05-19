const int potentiometerPin = A0;
const int ledPins[] = {8, 2, 3, 7, 4, 6, 5};
const int ledCount = 7;
int fadeSpeed = 50; // Temps en millisecondes pour passer de 0 à la luminosité maximale

void setup() {
  // Configure les broches des LEDs en sortie
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Lecture de la valeur du potentiomètre
  int potentiometerValue = analogRead(potentiometerPin);

  // Allume chaque LED une par une avec fading
  for (int i = 0; i < ledCount; i++) {
    // Vérifie si la LED doit être allumée
    if (potentiometerValue >= i * 146 && potentiometerValue < (i + 1) * 146) {
      // Calcul de la valeur de luminosité pour la LED actuelle
      int brightness = map(potentiometerValue - i * 146, 0, 146, 0, 255);
      // Allume la LED à la nouvelle luminosité
      analogWrite(ledPins[i], brightness);
      // Éteint la LED précédente
      if (i > 0) {
        analogWrite(ledPins[i - 1], 0);
      }
      // Pause pour l'étape de fading suivante
      delay(fadeSpeed);
    }
  }
}
