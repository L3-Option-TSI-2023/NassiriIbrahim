const int ledPin1 = 47;

void setup() {
  pinMode(ledPin1, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float tension_num = 0;
  static float tension_prec = 0;
  tension_num = analogRead(A0) * (5.0 / 1023);
  if (tension_num != tension_prec) {
    Serial.println(tension_num);
    tension_prec = tension_num;
    int dutyCycle = map(tension_num, 0, 5, 0, 255);
    int delayTime = map(dutyCycle, 0, 255, 1000, 50);
    analogWrite(ledPin1, dutyCycle);
    digitalWrite(ledPin1, HIGH);
    delay(delayTime);
    digitalWrite(ledPin1, LOW);
    delay(delayTime);
  }
}
