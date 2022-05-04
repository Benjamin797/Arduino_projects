

#include<Servo.h>


Servo servo1;//base
Servo servo2;//épaule
//Servo servo3;//coude
//Servo servo4;//poignée
//Servo servo5;//rot.poignée
//Servo servo6;//pince

int Pos1 = 0;
int Pos2 = 100;



void initialisation()
{
  //initialisation du robot
 

  servo1.attach(30);//D30
  servo2.attach(31);//D31

  
  servo1.write(Pos1);
  servo2.write(Pos2);

  
 
}


void sweep(int Pinit, int Pfin, Servo servo, int sec)
{
  for(Pinit = Pinit; Pinit<=Pfin; Pinit++)
  {
    servo.write(Pinit);
    delay(sec);
  }
  for(Pinit=Pfin; Pinit>=Pinit; Pinit--)
  {
    servo.write(Pinit);
    delay(sec);
  }
}
void setup() 
{
  Serial.begin(9600);
  
  initialisation();
}

void loop() {
  // put your main code here, to run repeatedly:

sweep(Pos1, 180, servo1, 30);
 
//    for(Pos1 = 0; Pos1<=180; Pos1++)
//  {
//    servo1.write(Pos1);
//    delay(25);
//  }
//  for(Pos1=180; Pos1>=0; Pos1--)
//  {
//    servo1.write(Pos1);
//    delay(25);
//  }
  
  



}
