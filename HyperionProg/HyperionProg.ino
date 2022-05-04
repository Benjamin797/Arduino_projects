//Benjamin FONDU 
//Concours Hyperion system design
#include "Commande.h"



void setup() {
  Serial.begin(9600);
  Setup();
  Serial.println(GetPositionAngulaire());//on affiche l'angle des servos
  Serial.println(GetVitesseReel());//on affiche la vitesse des moteurs
  Serial.println(GetLevelPercentage());//on affiche le niveau de batterie
}
void loop() {
  //test de certaines fonctions 
  BatteryLevel();
  SetServo(10,5);//10° a la vitesse 5
  Serial.println(GetPositionAngulaire());
  delay(1000);
  SetServo(70,2);
  Serial.println(GetPositionAngulaire());
  delay(1000);
  SetServo(130,8);
  Serial.println(GetPositionAngulaire());
  delay(1000);
  SetSpeed(LEVI,20,1);//20% de vitesse max avec un pas de 1 : lentement
  Serial.println(GetVitesseReel());//on affiche la vitesse des moteurs
  SetSpeed(GUID,30,3);
 
  
}
