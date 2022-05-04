#include <Servo.h>

Servo Servo1;  
Servo Servo2;
Servo Servo3;
Servo Servo4;

int pos1_servo1 = 22;
int pos2_servo1 = 57;  

int pos1_servo2 = 15;
int pos2_servo2 = 50;

int type;
char ID[2] = "ab";
int Etat;
int IDInteger;
int pos = 0;

void recup(){
  
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

//  Serial.println(type);
//  Serial.println(ID);
//  Serial.println(Etat);
}

void sweep(int pos1, int pos2){
  for (pos = pos1; pos <= pos2; pos += 1) { 
    Servo1.write(pos);       
    delay(30);                      
  }
  for (pos = pos2; pos >= pos1; pos -= 1) { 
    Servo1.write(pos);              
    delay(30);                       
  }
}
void Bouge(Servo s, int Etat, int pos1, int pos2){
  //ecrire dans serial monitor 1 pour aller tout droit, 2 pour tourner
 
    if(Etat==1 & pos1 != pos){//aller tout droit
    
    for (pos = pos2; pos >= pos1; pos -= 1) { 
    s.write(pos);              
    delay(35);                       
    }
    //Serial.println("- tout droit");
    pos = pos1;
    }
    if(Etat==2 & pos2 != pos){//tourner
   
    for (pos = pos1; pos <= pos2; pos += 1) { 
    s.write(pos);       
    delay(35);                      
    }
    //Serial.println("- tourne");
    pos = pos2;
    }
  
 
}

void aiguillage(){
  if(Serial.available()>0){
  recup();
  if(type == 97){             // verifie qu'il s'agit d'un aiguillage (97 = a en code ASCII)
    //Serial.print("type : aiguillage - ");
    
    switch (IDInteger){
    
    case 01: //aiguillage 1
    //Serial.print("n° 1 ");
    Bouge(Servo1, Etat, pos1_servo1, pos2_servo1);
    break;
  
    case 02: //aiguillage 2
    //Serial.print("n° 2 ");
    Bouge(Servo2, Etat, pos1_servo2, pos2_servo2);
    break;

    case 03: //aiguillage 3
    //Serial.print("n° 3 ");
    Bouge(Servo3, Etat,pos1_servo2, pos2_servo2);
    break;

    case 04: //aiguillage 4
    //Serial.print("n° 4 ");
    Bouge(Servo4, Etat,pos1_servo2, pos2_servo2);
    break;
  };

 }
}
}

void init_aiguillage(){
  Servo1.attach(9);  
  Servo1.write(pos1_servo1);
  Servo2.attach(8);  
  Servo2.write(pos1_servo2);
  pos = pos1_servo1;
}
void setup() {
  Serial.begin(9600);
  init_aiguillage();
  
}

void loop() {
 aiguillage();
}
