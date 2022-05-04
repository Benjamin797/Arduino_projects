#include "aiguillage.h"
#include "feux.h"
#include "Arduino.h"

feux::feux(){
//init tab
//ID des feux et PrevEtat
for(int i=0 ;i<DIMc;i++){
  tab[0][i] = i+1;
  tab[4][i] = 4;// nb arbitraire pour feu eteint (ici 4)
}
//constante Pin de la PWM
tab[5][0] = 9;
tab[5][1] = 3;
tab[5][2] = 6;
tab[5][3] = 12;
//autres cases (led)
for(int i= 1; i<4;i++){
  for(int j=0; j<4;j++){
    tab[i][j] = 0;
  }
}
}
//=================================================================================
void feux::commande(aiguillage A, Adafruit_PWMServoDriver pwm){
   //selon le feux :
    switch (A.IDInteger){
    
    case 01: //feux 1
    convert_3(A);
    //printTab();
    Allume(A, pwm);
    break;
  
    case 02: //feux 2
    convert_3(A);
    //printTab();
    Allume(A, pwm);
    break;

    case 03: //feux 3
    convert_3(A);
    //printTab();
    Allume(A, pwm);
    //clignote(A, pwm); //passage à niveaux
    break;

    case 04: //feux 4
    convert_3(A);
    //printTab();
    Allume(A, pwm);
    break;
  };
 
  
}

//=================================================================================

void feux::convert_3(aiguillage A){
   //actualiser l'etat des leds dans tab pour le cas d'un feux à 3 couleurs
   if(A.Etat != tab[4][A.IDInteger-1]){// eteindre le feux
    if(A.Etat == 4){
      for(int i=1;i<4;i++){
        tab[i][A.IDInteger-1] = 0;
      }
      tab[4][A.IDInteger-1] = 4;
      
    }else{
      tab[A.Etat][A.IDInteger-1] = 1;
      int PrevEtat = tab[4][A.IDInteger-1];//Etat precedent
      tab[PrevEtat][A.IDInteger-1] = 0;//On actualise à 0 la led precedemment allumée
      tab[4][A.IDInteger-1] = A.Etat;//Actualise l'etat precedent 
    }
      
      
   }
}


//================================================================================
void feux::convert_2(aiguillage A){
    //actualiser l'etat des leds dans tab pour le cas d'un feux à 2 couleurs
      if(A.Etat != 2){
        convert_3(A);
      }
      else{
        A.Etat = 3;
        convert_3(A);
      }
}
//================================================================================
void feux::Allume(aiguillage A, Adafruit_PWMServoDriver pwm){
  //Selon l'etat des leds dans tab, allume ou non la led
  for(int i= 0; i<4;i++){
    for(int j=1; j<4;j++){
      if(tab[j][i]==1){
         pwm.setPWM(j-1+tab[5][i], 0 , 4095);
         
      }
      if(tab[j][i]==0){
         pwm.setPWM(j-1+tab[5][i], 0 , 0);
       
      }
    }
  }  
}
//================================================================================
void feux::init_f(aiguillage A, Adafruit_PWMServoDriver pwm){
    //on eteind tous les feux à l'init
     Allume(A, pwm);
     //printTab();
  
}
//================================================================================
void feux::printTab(){
  for(int i= 0; i<DIMl;i++){
      Serial.println(" ");
    for(int j=0; j<DIMc;j++){
        Serial.print(tab[i][j]);
    }
  }
}
//================================================================================

void feux::clignote(aiguillage A, Adafruit_PWMServoDriver pwm){
  int Pin = A.IDInteger-1;
  while(A.Etat !=4){
      for(int i=0; i<4095; i+=3){
    pwm.setPWM(tab[5][Pin], 0 , i);
   
  }

  for(int i=4095; i>0; i-=3){
    pwm.setPWM(tab[5][Pin], 0 , i);
   
  }
  A.recup();
  Serial.println(A.Etat);
  }
   pwm.setPWM(tab[5][Pin], 0 , 0);

  
}
