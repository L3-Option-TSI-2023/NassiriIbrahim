int ledPin = 2; 
int fadeAmount =5 ;
int brightness = 0; 

void setup() {
  
  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  analogWrite(ledPin, brightness);
  delay(30); 
}
