long portPotentiometre= 0;
float valeurPotentiometre;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  valeurPotentiometre= analogRead(portPotentiometre);
  valeurPotentiometre=valeurPotentiometre*4.97/1023;
  Serial.print(valeurPotentiometre);
  Serial.println(" V");
  delay(1);

}
