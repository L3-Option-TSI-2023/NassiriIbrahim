<h1 align="center";">Rapport du Projet</h1>

<h2>I - Description de cahier  de charge </h2>
  
on prend le robot montée comme ci dessous et en appliquant le cahier de charge :
                    
<p align="center">
  <img src="https://github.com/L3-Option-TSI-2023/NassiriIbrahim/blob/main/WhatsApp%20Image%202023-05-20%20%C3%A0%2017.27.06.jpg" alt="le Robot">
</p>
                    

                          
- lorsque le robot tourne à droite ou à gauche, il met le clignotant c'est à dire qu'il doit y
avoir deux leds jaunes (une droite et une gauche) qui clignoteront un peu avant de tourner puis
s'arrêteront à la fin du virage.
- Quand le robot ralentit, alors trois leds rouges s'éclairent.
- Il doit aussi y avoir un potentiomètre permettant de régler la vitesse de déplacement qui sera
affiché sur la première ligne de l'écran LCD. Sur la seconde ligne seront affichées les vitesses
des roues droite et gauche
- Le démarrage sera fait en appuyant sur un bouton poussoir.
                 
<h2>II - Explication du code </h2> 
                    
afin d'assembler la partie materiel et logiciel on a utilisé la carte programable Arduino arduino
atmega 2560 qui se programme avec le langage Arduino qui est a peu pres identique au langage C++
dans cette partie on va explique le code ligne par ligne 
                    
<h3>1 -Bloc Bibliotheques </h3>  

#include <LiquidCrystal.h> // une bibliotheque qui nous donne l'acces a l'utilisation de la LCD
                   
<h3>2 -Bloc declaration </h3>                     

const int rs = 26, en = 27, d4 = 24, d5 = 22, d6 = 25, d7 = 23;
                    
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // ces broches sont declarés sur les pines 26 ,27 ,
24 , 22 , 25 , 23 respectivement  Ensuite, un objet lcd de type LiquidCrystal est créé en
utilisant ces broches.

const int brocheENA = 7;
                    
const int brocheIN1 = 8;
                    
const int brocheIN2 = 9;
                    
const int brocheENB = 12;
                    
const int brocheIN3 = 10;
                    
const int brocheIN4 = 11; // ces declarations ces pour les broches de modules L298N afin de
controler les moteurs 
                    
const int brochePotentiometre = A0; // la pin de declaration de potentiometre
                    
const int brocheBouton = 20; // la pin de declaration de bouton poussoir

const int ledDroite = 35;
                    
const int ledGauche = 33;
                    
const int ledRouge1 = 31;
                    
const int ledRouge2 = 30;
                    
const int ledRouge3 = 32;// la declaration des 5 leds utilisés 

float diametreRoue = 0.065;       // declaration d'un nombre flottant en metre pour le diametre
des roues
                    
float distanceEntreRoues = 0.113; // declaration d'un nombre flottant en metre pour la distance
entre les roues

int buttonstate = 0 ; // Cette ligne déclare et initialise la variable buttonstate de type
entier avec la valeur 0   
                    
<h3>2 -Bloc Fonction </h3>                     
                    
void avancer(float vitesse) {
                    
  int vitesseD = vitesse * 255;
                    
  int vitesseG = vitesse * 255;
                    
  digitalWrite(brocheIN1, HIGH);
                    
  digitalWrite(brocheIN2, LOW);
                    
  digitalWrite(brocheIN3, HIGH);
                    
  digitalWrite(brocheIN4, LOW);
                    
  analogWrite(brocheENA, vitesseD = 172);
                    
  analogWrite(brocheENB, vitesseG = 180);
                    
} // Cette fonction avancer permet de faire avancer le robot à une vitesse donnée. Les variables vitesseD et vitesseG sont calculées en multipliant la vitesse par 255. Les broches de contrôle des moteurs sont configurées pour faire tourner les roues dans le sens avant. Les valeurs des variables vitesseD et vitesseG sont utilisées pour régler la vitesse des moteurs à l'aide de la fonction analogWrite

void Stop() {
                    
  int vitesseD = 0;
                    
  int vitesseG = 0;
                    
  digitalWrite(brocheIN1, LOW);
                    
  digitalWrite(brocheIN2, LOW);
                    
  digitalWrite(brocheIN3, LOW);
                    
  digitalWrite(brocheIN4, LOW);
                    
  analogWrite(brocheENA, vitesseD = 0);
                    
  analogWrite(brocheENB, vitesseG = 0);
                    
} // La fonction Stop arrête le mouvement du robot. Les variables vitesseD et vitesseG sont mises à zéro. Les broches de contrôle des moteurs sont configurées
pour arrêter les roues en mettant toutes les broches à l'état bas.

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
                 
} // Cette fonction afficherVitesse affiche les valeurs de la vitesse générale du robot, de la vitesse de la roue droite (vitesseD) et de la vitesse de la roue
gauche (vitesseG) sur l'écran LCD.

void clignoter(int led, int duree) {
                 
  pinMode(led, OUTPUT);
                 
  for (int i = 0; i < duree / 200; i++) {
                 
  digitalWrite(led, HIGH);
                 
  delay(100);
                 
  digitalWrite(led, LOW);
                 
  delay(100);
                 
  }
} // La fonction clignoter fait clignoter une LED spécifiée (led) pendant une durée donnée (duree). La broche de la LED est configurée en tant que sortie, puis la
LED est allumée et éteinte alternativement en utilisant la fonction digitalWrite et des délais (delay) pour créer l'effet de clignotement.

void tournerDroite() {
                 
  clignoter(ledDroite, 700);
                 
  digitalWrite(brocheIN1, LOW);
                 
  digitalWrite(brocheIN2, HIGH);
                 
  digitalWrite(brocheIN3, HIGH);
                 
  digitalWrite(brocheIN4, LOW);
                 
  delay(500);
                 
} // La fonction tournerDroite fait clignoter une LED spécifique (ledDroite), puis configure les broches des moteurs pour faire tourner le robot vers la droite.
Un délai de 500 millisecondes est ajouté pour donner une pause après le mouvement.

void tournerGauche() {
                 
  clignoter(ledGauche, 700);
                 
  digitalWrite(brocheIN1, HIGH);
                 
  digitalWrite(brocheIN2, LOW);
                 
  digitalWrite(brocheIN3, LOW);
                 
  digitalWrite(brocheIN4, HIGH);
                 
  delay(500);
                 
} // de meme La fonction tournerGauche fait clignoter une LED spécifique (ledGauche), puis configure les broches des moteurs pour faire tourner le robot vers la
gauche. Un délai de 500 millisecondes est ajouté pour donner une pause après le mouvement.

void allumerLedsRouges() {
                 
  digitalWrite(ledRouge1, HIGH);
                 
  digitalWrite(ledRouge2, HIGH);
                 
  digitalWrite(ledRouge3, HIGH);
} 

void eteindreLedsRouges() {
                 
  digitalWrite(ledRouge1, LOW);
                 
  digitalWrite(ledRouge2, LOW);
                 
  digitalWrite(ledRouge3, LOW);
                 
} // Les fonctions allumerLedsRouges et eteindreLedsRouges permettent respectivement d'allumer
et d'éteindre toutes les LED rouges en modifiant l'état des broches
correspondantes.
                 
<h3>3 -Bloc Setup </h3>                 

La fonction Setup est une fonction spécifique d'Arduino qui n'est exécutée qu'une
seule fois au démarrage du programme. Il est utilisé pour initialiser les paramètres de
microcontrôleur, configurer les broches d'E/S et effectuer d'autres initialisations
nécessaires.
                 
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
} // La ligne pinMode d'une broche de configuration définit le mode de fonctionnement de la broche. La broche spécifiée est configurée comme une sortie (OUTPUT)
ou une entrée (INPUT). pinPinButton est configuré avec INPUT_PULLUP, qui active la résistance pull-up interne de la broche.
Utilisez ensuite pinMode pour configurer les broches de la LED et de l'écran LCD en tant que sorties.
Enfin, appelez la fonction begin sur l'objet lcd pour initialiser l'écran LCD à une configuration de 16 colonnes et 2 lignes.
                 

<h3>3 -Bloc Loop </h3> 
                 
La fonction loop est exécutée en boucle continuellement après l'exécution de la fonction setup.
C'est ici que le comportement principal du programme se trouve.                
                 
void loop() {
                 
int valeurPotentiometre = analogRead(brochePotentiometre);
                 
float vitesse = map(valeurPotentiometre, 0, 1023, 0, 5) / 5.0;
                 
float vitesseD = vitesse * (diametreRoue / 2) / (distanceEntreRoues / 2);
                 
float vitesseG = vitesse * (diametreRoue / 2) / (distanceEntreRoues / 2);

 afficherVitesse(vitesse, vitesseD, vitesseG); // Affiche la vitesse sur l'écran LCD

 buttonstate = digitalRead(brocheBouton);
  
//La première ligne de code lit la valeur du potentiomètre à l'aide de la fonction analogRead et la stocke dans la variable valeurPotentiometre.

Ensuite, la vitesse est calculée à partir de la valeur du potentiomètre à l'aide de la fonction map. La valeur du potentiomètre, qui est comprise entre 0 et 1023,
est mappée sur une plage de 0 à 5, représentant la vitesse maximale. La vitesse est ensuite normalisée en divisant par 5.0.

Les variables vitesseD et vitesseG sont calculées en utilisant la vitesse, le diamètre de la roue et la distance entre les roues du robot. Ces variables
représentent la vitesse respective des roues droite et gauche.

La fonction afficherVitesse est appelée pour afficher la vitesse, la vitesse de la roue droite et la vitesse de la roue gauche sur l'écran LCD.

La variable buttonstate est mise à jour en lisant l'état du bouton connecté à la broche brocheBouton à l'aide de digitalRead
                 
   if(buttonstate == LOW){
                 
  avancer(vitesse);
                 
  delay(5852); 
                 
  tournerDroite();
                 
  avancer(vitesse);
                 
  delay(953); 

  tournerDroite();
                 
  avancer(vitesse);
                 
  delay(1209); 

  tournerDroite();
                 
  avancer(vitesse);
                 
  delay(1840); 
                 

  tournerGauche();
                 
  avancer(vitesse);
                 
  delay(3700); 

  tournerGauche();
                 
  avancer(vitesse);
                 
  delay(750);

  allumerLedsRouges();
  Stop();
}
}  // Ensuite, on vérifie si le bouton est enfoncé (buttonstate == LOW). Si c'est le cas, les instructions à l'intérieur du bloc if sont exécutées.

La fonction avancer est appelée avec la vitesse actuelle pour faire avancer le robot.
Un délai de 5852 millisecondes est ajouté pour parcourir une distance de 1.5 mètre et on utilisant la regle de trois on applique ca sur un 1.1 m qui nous donne
3700 et ainsi de suite selon le circuit qu'on va voir sur le chapitre suivant 
La fonction tournerDroite est appelée pour effectuer un virage vers la droite 
La fonction tournerGauche est appelée pour effectuer un virage vers la gauche 
                 
<h2>III - Forme finale </h2>                 
                 
apres qu'on a utilisé et suivre ces demarches on aura un resultat comme ci dessous :
                 
<p align="center">
  <iframe width="300" height="250" src="https://github.com/L3-Option-TSI-2023/NassiriIbrahim/blob/main/Ma%20vid%C3%A9o.mp4" frameborder="0" allowfullscreen></iframe>
</p>



                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
                 
