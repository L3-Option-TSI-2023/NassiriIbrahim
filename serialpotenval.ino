void setup() {
  Serial.begin(9600); 
}

void loop() {
  float tension_num = 0;
  static float tension_prec = 0; // valeur précédente de tension
  tension_num = analogRead(0) * (5.0 / 1023);
  if (tension_num != tension_prec) { // si la tension a changé
    Serial.println(tension_num); // afficher la nouvelle valeur
    tension_prec = tension_num; // mettre à jour la valeur précédente
  }
  delay(500); 
}
