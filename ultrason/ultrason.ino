
int pinTrig = 3;//D2
int pinEcho = 2;//D3
int pinLED = 5;//D5
long temps;
float distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho,INPUT);
  pinMode(pinLED, OUTPUT);

  digitalWrite(pinTrig,LOW);
  //digitalWrite(pinLED, HIGH);
 
 

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinTrig,HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig,LOW);
  digitalWrite(pinLED, LOW);
  

  temps= pulseIn (pinEcho,HIGH);//temps que la pin echo attende un retour du signal

  if (temps > 25000)//si distance > 4m 
  {
    Serial.println ("Echec de la mesure");
  }
  else
  {
      
      temps=temps/2;
      distance= (temps*340)/10000.0;
      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");

      if(distance < 20){//LED s'eteint+ servo en marche
       digitalWrite(pinLED, HIGH);
      
      }
  }
  delay(100);
  
}
