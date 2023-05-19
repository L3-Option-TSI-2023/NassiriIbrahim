 const int period = 1000;
 const float cycle = 0.7;
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(11, OUTPUT);
   
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(11, HIGH);   
  delay(cycle*period);                       
  digitalWrite(11, LOW);    
  delay( period-(cycle*period));  
                     
}
