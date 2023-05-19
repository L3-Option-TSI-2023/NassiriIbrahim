

const int Pin_Inter = 2; 
volatile int Compteur = 0; 




void setup() {
  Serial.begin(115200); 
  attachInterrupt(digitalPinToInterrupt(Pin_Inter), countTics, FALLING);



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
