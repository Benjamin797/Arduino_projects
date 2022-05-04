#ifndef FEUX_H_INCLUDED
#define FEUX_H_INCLUDED
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define DIMl 6
#define DIMc 4

class feux {

  //Etat 1 : rouge, Etat 2 : jaune, Etat 3 : vert, Etat 4 : eteindre feux
  
  private :

  int tab[DIMl][DIMc];

  public : 

  feux();
  void init_f(aiguillage A, Adafruit_PWMServoDriver pwm);
  void commande(aiguillage A, Adafruit_PWMServoDriver pwm);
  void convert_3 (aiguillage A);
  void convert_2 (aiguillage A);
  void Allume(aiguillage A, Adafruit_PWMServoDriver pwm);
  void clignote(aiguillage A, Adafruit_PWMServoDriver pwm);
  void printTab();
};

#endif // FEUX_H_INCLUDED
