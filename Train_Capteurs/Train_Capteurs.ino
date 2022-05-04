#include "Capt.h"
#include "aiguillage.h"
#include "feux.h"

Capt capteur; //déclaration de l'objet capteur
aiguillage Aiguille; // déclaration de l'objet Aiguille
feux Led;// éeclaration de l'objet led
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); //déclaration de la carte pwm


void setup() {
  
  Serial.begin(9600);
  Aiguille.init(pwm);
  Led.init_f(Aiguille, pwm);
  
}

void loop() {
 
  //Capteurs ILS et IR
  capteur.task_ILS1();
  capteur.task_ILS2();
  capteur.task_ILS3();
  capteur.task_ILS4();
  capteur.task_ILS5();
  capteur.task_ILS6();
  capteur.task_IR01();
  
  if(Serial.available()>0){
    Aiguille.recup(); //recupère la trame
     if(Aiguille.getType() == 97){   // verifie qu'il s'agit d'un aiguillage (97 = a en ASCII)
        Aiguille.aiguiller(pwm);   // aiguillage
     }
     if(Aiguille.getType() == 102){  //verifie qu'il s'agit d'un feux (102 = f en ACSII)
        Led.commande(Aiguille, pwm); //feux
     }
  }



 

  
  
}
