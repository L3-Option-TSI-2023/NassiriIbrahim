#include <LiquidCrystal.h>

const int rs = 26, en = 27, d4 = 24, d5 = 22, d6 = 25, d7 = 23;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int brocheENA = 7;
const int brocheIN1 = 8;
const int brocheIN2 = 9;
const int brocheENB = 12;
const int brocheIN3 = 10;
const int brocheIN4 = 11;
const int brochePotentiometre = A0;
const int brocheBouton = 20;

const int ledDroite = 35;
const int ledGauche = 33;
const int ledRouge1 = 31;
const int ledRouge2 = 30;
const int ledRouge3 = 32;

float diametreRoue = 0.065;       // en mètres
float distanceEntreRoues = 0.113; // en mètres

int buttonstate = 0 ;

void avancer(float vitesse) {
  int vitesseD = vitesse * 255;
  int vitesseG = vitesse * 255;
  digitalWrite(brocheIN1, HIGH);
  digitalWrite(brocheIN2, LOW);
  digitalWrite(brocheIN3, HIGH);
  digitalWrite(brocheIN4, LOW);
  analogWrite(brocheENA, vitesseD = 172);
  analogWrite(brocheENB, vitesseG = 180);
}

void Stop() {
    int vitesseD = 0;
  int vitesseG = 0;
  digitalWrite(brocheIN1, LOW);
  digitalWrite(brocheIN2, LOW);
  digitalWrite(brocheIN3, LOW);
  digitalWrite(brocheIN4, LOW);
  analogWrite(brocheENA, vitesseD = 0);
  analogWrite(brocheENB, vitesseG = 0);
}

void afficherVitesse(float vitesse, float vitesseD, float vitesseG) {
  lcd.setCursor(0, 0);
  lcd.print("Vitesse:");
  lcd.print(vitesse,2);
  lcd.print("m/s");
  lcd.setCursor(0, 1);
  lcd.print("RD:");
  lcd.print(vitesseD,2);
 
  lcd.print(" ");
  lcd.print("RG:");
  lcd.print(vitesseG,2);
  lcd.print("m/s");
}

void clignoter(int led, int duree) {
  pinMode(led, OUTPUT);
  for (int i = 0; i < duree / 200; i++) {
    digitalWrite(led, HIGH);
    delay(100);
    digitalWrite(led, LOW);
    delay(100);
  }
}

void tournerDroite() {
  clignoter(ledDroite, 700);
  digitalWrite(brocheIN1, LOW);
  digitalWrite(brocheIN2, HIGH);
  digitalWrite(brocheIN3, HIGH);
  digitalWrite(brocheIN4, LOW);
  delay(500);
}

void tournerGauche() {
  clignoter(ledGauche, 700);
  digitalWrite(brocheIN1, HIGH);
  digitalWrite(brocheIN2, LOW);
  digitalWrite(brocheIN3, LOW);
  digitalWrite(brocheIN4, HIGH);
  delay(500);
}

void allumerLedsRouges() {
  digitalWrite(ledRouge1, HIGH);
  digitalWrite(ledRouge2, HIGH);
  digitalWrite(ledRouge3, HIGH);
}

void eteindreLedsRouges() {
  digitalWrite(ledRouge1, LOW);
  digitalWrite(ledRouge2, LOW);
  digitalWrite(ledRouge3, LOW);
}

void setup() {
  pinMode(brocheENA, OUTPUT);
  pinMode(brocheIN1, OUTPUT);
  pinMode(brocheIN2, OUTPUT);
  pinMode(brocheENB, OUTPUT);
  pinMode(brocheIN3, OUTPUT);
  pinMode(brocheIN4, OUTPUT);
  pinMode(brochePotentiometre, INPUT);
  pinMode(brocheBouton, INPUT_PULLUP);

  pinMode(ledDroite, OUTPUT);
  pinMode(ledGauche, OUTPUT);
  pinMode(ledRouge1, OUTPUT);
  pinMode(ledRouge2, OUTPUT);
  pinMode(ledRouge3, OUTPUT);

  lcd.begin(16, 2);
}

void loop() {


   
  int valeurPotentiometre = analogRead(brochePotentiometre);
  float vitesse = map(valeurPotentiometre, 0, 1023, 0, 5) / 5.0;
  float vitesseD = vitesse * (diametreRoue / 2) / (distanceEntreRoues / 2);
  float vitesseG = vitesse * (diametreRoue / 2) / (distanceEntreRoues / 2);

  afficherVitesse(vitesse, vitesseD, vitesseG); // Affiche la vitesse sur l'écran LCD

  buttonstate = digitalRead(brocheBouton);
  

   if(buttonstate == LOW){
  avancer(vitesse);
  delay(5852); // 1 mètre
  tournerDroite();
  avancer(vitesse);
  delay(953); // 0.5 mètre

  tournerDroite();
  avancer(vitesse);
  delay(1209); // 0.5 mètre


  tournerDroite();
  avancer(vitesse);
  delay(1840); // 0.5 mètre

  tournerGauche();
  avancer(vitesse);
  delay(3700); // 0.5 mètre

  tournerGauche();
  avancer(vitesse);
  delay(750); // 0.5 

  allumerLedsRouges();
  Stop();
}
}