#include <TimerOne.h>

const int Pin_Inter = 2; 
volatile int Compteur = 0; 



void setup() {
  Serial.begin(115200); 
  attachInterrupt(digitalPinToInterrupt(Pin_Inter), countTics, FALLING);
  Timer1.initialize(10000);
  Timer1.attachInterrupt(calculeVitesse);


}


void loop() {

    while (Compteur < 990) {
 
  }

  Compteur=0;


}
void countTics() {


  Compteur++;
  Serial.println(Compteur);

}
void calculeVitesse() {
  float vitesse = (float)((Compteur/990.0)/0.00025); 
  
  Serial.println(vitesse);

}
