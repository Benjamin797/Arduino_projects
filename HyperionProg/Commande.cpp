#include "Commande.h"
#include "Arduino.h"

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();//objet PWM

bool urgence = false;//sert à la detection d'arret d'urgence
bool Exit = false;//sert à n'activer qu'une seule fois la fonction abort()
float getLevel_percentage = 100;//%
float vitesse_reel = 0;//tr/min
float PositionAngulaire = 0;

void SetServo(float angle, int pas){
  
PositionAngulaire = angle; // on met à jour position angulaire qui sera en degré si on veut connaitre l'angle du servo 
static float angle_prev = AngleToPulse(0);//garde la valeur de la précédente position angulaire du servo (en µs)
angle = AngleToPulse(angle);//conversion en µs

if (angle_prev<angle){//cas ou l'angle précédent est inférieur à l'angle voulu
  
  while((angle_prev<angle) & (urgence == false)){//execution tant que l'angle voulu n'est pas atteind ET qu'auncune detection d'arret d'urgence n'est faite
    pwm.writeMicroseconds(SERVO1_PIN,angle_prev);//bouge le servo 1
    pwm.writeMicroseconds(SERVO2_PIN,angle_prev);//bouge le servo 2
    if(Exit == false) {BatteryLevel();}//on vérifie le niveau de batterie, permet l'arret d'urgence même pendant le mouvement d'un servo (agit comme du multitasking)
    //Exit permet de n'activer qu'une fois la fonction Abort(), sinon imbrication des Abort() lors du SetServo et SetSpeed() dans ce dernier
    
    angle_prev+=pas;//incremention de l'angle suivant le pas choisi (notion de vitesse du mouvement, plus le pas est grand,plus le mouvement est rapide)
  }  
    
}else{//cas ou l'angle précédent est supérieur à l'angle voulu
  while((angle_prev>angle) & (urgence == false)){//idem que première boucle
    pwm.writeMicroseconds(SERVO1_PIN,angle_prev);
    pwm.writeMicroseconds(SERVO2_PIN,angle_prev); 
    if(Exit == false) {BatteryLevel();}
    
    angle_prev-=pas;//diminution de l'angle suivant le pas
  }
 }
 if(urgence == true){//sortie de boucle, or si urgence = true, cela signfie qu'un arret d'urgence a été détécté
    Abort();//déclenchement de l'arrêt d'urgence
  
  }else{
    angle_prev = angle;//sinon on actualise l'angle précédent
  }
}


float AngleToPulse(float val){
  //converti les angles (0 à 180) en longueur de pulsation (1000 à 2000µs)
 return (float)map(val,SERVOMIN , SERVOMAX, PULSEMIN, PULSEMAX);
}

void BatteryLevel(){
  float getLevel = analogRead(BATTERIE_PIN);//récupere la tension (entre 0 et 1023)

  float minValue = 1023*TensionMin/5;//conversion Tension Min sur 10 bits
  float maxValue = 1023*TensionMax/5;//conversion Tension Max sur 10 bits
 
  getLevel_percentage = (getLevel - minValue)/(maxValue - minValue)*100; //get level en pourcentage (diff actuelle/diff max)
  
  if (getLevel_percentage > 100){
    getLevel_percentage = 100;//on fixe la valeur max de getLevel_percentage à 100% au cas ou on est > TensionMax
    
  }
  else if (getLevel_percentage <= BatterieSeuil) {
    urgence=true;//permet de sortir des boucles while de SetServo et SetSpeed des que le seuil minimum est franchi
  }
}

void SetSpeed(MODE_MOTEUR mode, float Speed, int pas){
  //même démarche de code que SetServo()
  static float vitesse_prev = PULSEMIN; //garde la valeur de la vitesse précédente (en µs) 
  static float vitesse = (Speed/100+1)*PULSEMIN;//Speed est un pourcentage de vitesse max (qui est en µs), on converti speed en une vitesse en µs
  int num;//représentera les pins des différents moteurs
  
if(mode == LEVI){//distinction des moteurs de lévitation et de guidage
  num = MOTEURLEVI_PIN;//num vaut la pin du premier moteur (que l'on incrémentera)
}
if(mode == GUID){
  num = MOTEURGUID_PIN;
}

if (vitesse_prev<vitesse){//si vitesse précédente inférieure à vitesse voulue
while((vitesse_prev<vitesse) & (urgence == false)){//execution tant que la vitesse voulu n'est pas atteinte ET qu'auncune detection d'arret d'urgence n'est faite
   pwm.writeMicroseconds(num,vitesse_prev);//bouge moteur 1
   pwm.writeMicroseconds(num+1,vitesse_prev);//on incrémente le pin, hypothese : les moteurs LEVI (tout comme les moteurs GUID) sont branchés à la suite
   pwm.writeMicroseconds(num+2,vitesse_prev);
   pwm.writeMicroseconds(num+3,vitesse_prev);
   vitesse_reel = KVMOTEUR*ALIMENTATION*100*(vitesse_prev/PULSEMIN - 1);//permet de connaitre la vitesse du moteur en temps reél (en tr/min)
   if(Exit == false) {BatteryLevel();}//on vérifie le niveau de batterie, permet l'arret d'urgence même pendant le mouvement d'un servo (agit comme du multitasking)
   vitesse_prev+=pas;//incrémentation de la vitesse suivant le pas permettant une accélération progressive
}
}else{//si vitesse précédente supérieure à vitesse voulue
  while((vitesse_prev>vitesse) & (urgence == false)){//idem
   pwm.writeMicroseconds(num,vitesse_prev);
   pwm.writeMicroseconds(num+1,vitesse_prev);
   pwm.writeMicroseconds(num+2,vitesse_prev);
   pwm.writeMicroseconds(num+3,vitesse_prev);
   vitesse_reel = KVMOTEUR*ALIMENTATION*100*(vitesse_prev/PULSEMIN - 1);
   if(Exit == false) {BatteryLevel();}
   vitesse_prev-=pas;//diminution de la vitesse suivant le pas permettant une  déccélération progressive
   
  }
}
 if(urgence == true){//sortie de boucle while, or si urgence = true, cela signfie qu'un arret d'urgence a été détécté 
  Abort();
 }else{
  vitesse_prev = vitesse;//mise à jour de la vitesse 
 }
 
}

void Setup() {
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  SetServo(ANGLE_INIT,10);//init des servos à 90° (a tester)
  SetSpeed(LEVI,0,10);//init des moteur à 0% 
  SetSpeed(GUID,0,10);
  BatteryLevel();//on vérifie une première fois l'état de la batterie
  
}

void Abort() {
 
 while(true){//boucle infinie 
    Exit = true;//Après première execution de Abort(), on ne veut plus l'exectuer, on souhaite rester dedans indéfiniment, Exit permet cela
    digitalWrite(LED_BUILTIN, HIGH);//previent l'utilisateur via la LED que l'arret d'urgence est en cours
    urgence=false;//permet de reutiliser les fonctions SetServo() et SetSpeed()pour juste après
     SetSpeed(LEVI,0,1);//on arrete (0%) les moteurs avec un pas de 1 (très lentement, au choix avec les tests)
     SetSpeed(GUID,0,1);
     SetServo(ANGLE_INIT,5);//remise à la position initiale à vitesse modérée (pas de 5, au choix avec les tests)
    
  } 
}

float GetVitesseReel(){//avoir la vitesse reelle
  return vitesse_reel;
}
float GetPositionAngulaire(){//avoir l'angle des servos
  return PositionAngulaire;
}
float GetLevelPercentage(){//avoir le niveau de batterie
  return getLevel_percentage;
}
