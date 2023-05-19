 
void setup() {
  Serial.begin(9600);
while (!Serial){}
Serial.print("Entrez votre phrase :");

  
  }

void loop() {
  
if (Serial.available() )
{    
      Serial.print((char)Serial.read()); //caster 
}
else
{
}
}
