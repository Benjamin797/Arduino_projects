#ifndef COMMANDE_H_INCLUDED
#define COMMANDE_H_INCLUDED

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>


#define BATTERIE_PIN  A0 //Port analogique récupérant la tension de la batterie
#define MOTEURLEVI_PIN 2 //Pin du premier moteur de levitation
#define MOTEURGUID_PIN 6 //Pin du premier moteur de guidage
#define SERVO1_PIN 0//pin servo1
#define SERVO2_PIN 1//pin servo2
#define BatterieSeuil 3 //Seuil d'arrêt : 3% 
#define TensionMin 0//V
#define TensionMax 5//V
#define SERVO_FREQ 50//fréquence PWM
#define PULSEMIN  1000 // pulse length min en µs
#define PULSEMAX  2000 // pulse length max en µs
#define SERVOMIN 0//degré min du servo
#define SERVOMAX 180//degré max du servo
#define ANGLE_INIT 90//angle d'init et d'arret d'urgence
#define KVMOTEUR 1200//Kv
#define ALIMENTATION 15//V

typedef enum{//caractérisation du moteur brushless pour SetSpeed()
  LEVI,//levitation
  GUID,//guidage
}MODE_MOTEUR;

void SetServo(float angle, int pas);//args:float angle voulu,int pas d'incrementation (entre 1 et 10,permet de varier la vitesse du servo)
float AngleToPulse(float val);
void BatteryLevel();
void SetSpeed(MODE_MOTEUR mode, float Speed, int pas);//args:MODE_MOTEUR mode (LEVI ou GUID), float Speed (pourcentage de vitesse max (qui est en µs)), int pas (pas d'incrementation pour accélération ou déccélération progressive)
void Setup();
void Abort();

float GetVitesseReel();
float GetPositionAngulaire();
float GetLevelPercentage();

#endif // COMMANDE_H_INCLUDED
