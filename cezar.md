const int buttonPin = 51;
const int ledPin1 = 47;
const int ledPin2 = 49;
const int ledPin3 = 53;

int buttonState = 0;
int shift = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  while (true) {
    Serial.println("Entrez une phrase :");

    while (Serial.available() == 0) {
    }

    String phrase = Serial.readStringUntil('\n');

    Serial.println("Entrez le décalage de César :");
    while (Serial.available() == 0) {
    }
    int decalage = Serial.parseInt();

    allumerLed(ledPin1);
    attendreBouton();
    eteindreLed(ledPin1);
    allumerLed(ledPin2);

    String phraseChiffree = chiffrerCesar(phrase, decalage);
    Serial.print("Phrase chiffrée : ");
    Serial.println(phraseChiffree);

    attendreBouton();
    eteindreLed(ledPin2);
    allumerLed(ledPin3);

    String phraseDechiffree = dechiffrerCesar(phraseChiffree, decalage);
    Serial.print("Phrase déchiffrée : ");
    Serial.println(phraseDechiffree);

    attendreBouton();
    eteindreLed(ledPin3);

    Serial.println("si vous Voulez refaire entrer votre nouvelle phrase  ");

    while (Serial.available() == 0) {
    }
    char reponse = Serial.read();
    if (reponse == 'N' || reponse == 'n') {
      break;
    }
  }
}

void attendreBouton() {
  while (digitalRead(buttonPin) == LOW) {
    delay(10);
  }
  
  while (digitalRead(buttonPin) == HIGH) {
    delay(10);
  }
}

void allumerLed(int pin) {
  digitalWrite(pin, HIGH);
}

void eteindreLed(int pin) {
  digitalWrite(pin, LOW);
}

String chiffrerCesar(String phrase, int decalage) {
  String resultat = "";
  for (int i = 0; i < phrase.length(); i++) {
    char c = phrase.charAt(i);
    if (isAscii(c)) {
      c = 33 + (c - 33 + decalage) % 95;
    }
    resultat += c;
  }
  return resultat;
}

String dechiffrerCesar(String phrase, int decalage) {
  String resultat = "";
  for (int i = 0; i < phrase.length(); i++) {
    char c = phrase.charAt(i);
    if (isAscii(c)) {
      c = 33 + (c - 33 - decalage + 95) % 95;
    }
    resultat += c;
  }
  return resultat;
}

bool isAscii(char c) {
  return c >= 33 && c <= 127;
}
