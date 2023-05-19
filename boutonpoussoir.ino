int buttonPin = 51;
int led = 53;
int led2 = 49;
int led3=47;
int buttonState = 0;
bool etat = 0;
unsigned long BP = 0;
unsigned long BPD = 0; //suivre la duree d'enfoncement
const unsigned long LPD = 1000;//pour définir la durée de maintien d'un appui long.

void setup() {
  pinMode(led2, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == LOW) {
    BP = millis();
    while (digitalRead(buttonPin) == LOW) { //vérifier si le bouton est toujours maintenu enfoncé et pour mesurer la durée d'enfoncement.
      BPD = millis() - BP;
      if (BPD >= LPD) {
        return; 
      }
    }
    
    if (etat == 0) {
      etat = 1;
      digitalWrite(led, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if (etat == 1)  {
      etat = 0;
      digitalWrite(led, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else { 
   
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      }
    delay(300); // eviter le rebond
  }
}
