#ifndef AIGUILLAGE_H_INCLUDED
#define AIGUILLAGE_H_INCLUDED
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define DIMc 4
#define DIMl 3

#define SERVOMIN  150 
#define SERVOMAX  600


class aiguillage{
  private :

 
  int pos_servo[DIMl][DIMc]; //tableau ligne 1: butée debut, ligne 2: butée fin, ligne 3: derniere position colonne: servo

  int type;
  char ID[2] = "ab";
  int Etat;
  int IDInteger;
  

  public : 

  aiguillage();
  void init(Adafruit_PWMServoDriver pwm);
  void recup();
  void sweep(int pos[DIMl][DIMc], Adafruit_PWMServoDriver pwm);
  void Bouge(int Etat, int pos[DIMl][DIMc], int servo, Adafruit_PWMServoDriver pwm);
  void aiguiller(Adafruit_PWMServoDriver pwm);
  friend class feux;
  int getType();
  int AngleToPulse(int val);
  
  
};

#endif // AIGUILLAGE_H_INCLUDED
