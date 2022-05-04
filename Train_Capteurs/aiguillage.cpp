#include <Servo.h>
#include"aiguillage.h"
#include "Arduino.h"


aiguillage::aiguillage(){

  pos_servo[0][0] = 22;
  pos_servo[0][1] = 57;  

  pos_servo[1][0] = 15;
  pos_servo[1][1] = 50;

  
  
}

//=========================================================================================

void aiguillage::recup(){
  
  String data = Serial.readString();
  int sized = data.length()+1;
  char tab[sized];
  data.toCharArray(tab, sized);

  type = data[2];
  
  ID[0] = data[4];
  ID[1] = data[5];
  IDInteger = atoi(ID);
  char e[2] = "ab";
  e[0] = data[6];
  e[1] = data[7];
  Etat = atoi(e);

  //Serial.println(type);
  //Serial.println(ID);
  //Serial.println(Etat);
}

//==========================================================================================
void aiguillage::sweep(int pos[DIMl][DIMc], Adafruit_PWMServoDriver pwm){
  for (pos[0][2] = pos[0][0]; pos[0][2] <= pos[0][1]; pos[0][2] += 1) { 
    pwm.setPWM(0, 0, AngleToPulse(pos_servo[0][2]));          
    delay(30);                      
  }
  for (pos[0][2] = pos[0][1]; pos[0][2]>= pos[0][0]; pos[0][2] -= 1) { 
    pwm.setPWM(0, 0, AngleToPulse(pos_servo[0][2]));                 
    delay(30);                       
  }
}

//==========================================================================================

void aiguillage::Bouge(int Etat, int pos[DIMl][DIMc], int servo, Adafruit_PWMServoDriver pwm){
  //ecrire dans serial monitor 1 pour aller tout droit, 2 pour tourner
 
    if(Etat==1 & pos[servo-1][0] != pos[servo-1][2]){//aller tout droit
    
    for (pos[servo-1][2] = pos[servo-1][1]; pos[servo-1][2] >= pos[servo-1][0]; pos[servo-1][2] -= 1) { 
    pwm.setPWM(servo-1, 0, AngleToPulse(pos_servo[servo-1][2]));             
    delay(35);                       
    }
    //Serial.println("- tout droit");
    pos[servo-1][2] = pos[servo-1][0];
    }
    if(Etat==2 & pos[servo-1][1] != pos[servo-1][2]){//tourner
   
    for (pos[servo-1][2] = pos[servo-1][0]; pos[servo-1][2] <= pos[servo-1][1]; pos[servo-1][2] += 1) { 
    pwm.setPWM(servo-1, 0, AngleToPulse(pos_servo[servo-1][2]));          
    delay(35);                      
    }
    //Serial.println("- tourne");
    pos[servo-1][2] = pos[servo-1][1];
    }
  
 
}

//==========================================================================================

void aiguillage::aiguiller(Adafruit_PWMServoDriver pwm){
    
    switch (IDInteger){
    
    case 01: //aiguillage 1
    //Serial.print("n° 1 ");
    Bouge(Etat, pos_servo, 1, pwm);
    break;
  
    case 02: //aiguillage 2
    //Serial.print("n° 2 ");
    Bouge(Etat, pos_servo, 2, pwm);
    break;

    case 03: //aiguillage 3
    //Serial.print("n° 3 ");
    Bouge(Etat,pos_servo, 3, pwm);
    break;

    case 04: //aiguillage 4
    //Serial.print("n° 4 ");
    Bouge(Etat,pos_servo, 4,pwm);
    break;
  };

}



//==========================================================================================

void aiguillage::init(Adafruit_PWMServoDriver pwm){

    pwm.begin();
    pwm.setPWMFreq(60); 
    pwm.setPWM(0, 0, AngleToPulse(pos_servo[0][0]));
    pwm.setPWM(1, 0, AngleToPulse(pos_servo[1][0]));

    pos_servo[0][2] = pos_servo[0][0];
    pos_servo[1][2] = pos_servo[1][0];
  
}

//==========================================================================================


int aiguillage::getType(){
  return type;
}


//==========================================================================================

int aiguillage:: AngleToPulse(int val){
 return (int)map(val, 0, 180, SERVOMIN , SERVOMAX);
}
