#include <Servo.h>

Servo servo0;//base
Servo servo1;//coude
Servo servo2;//epaule
Servo servo3;//poignée
Servo servo4;//rot.poignée
Servo servo5;//pince

int Pos0=30;
int Pos2=55;
int Pos1=90;//declare sa position initale
int Pos5=180;
int Pinservo1 = 42;
int Pinservo2 = 31;
int Pinservo0 = 30;
int Pinservo5 = 35;
int n = 70;
int i;
//int PinPot = 1;// en A1



void setup() {
  // put your setup code here, to run once:
  servo1.attach(Pinservo1);
  servo2.attach(Pinservo2);
  servo0.attach(Pinservo0);
  servo5.attach(Pinservo5);
  
  servo1.write(Pos1);
  servo2.write(Pos2);
  servo0.write(Pos0);
  servo5.write(Pos5);

}

void loop() {
  // put your main code here, to run repeatedly:

   for(i=0; i<= n; i++){
     servo1.write(Pos1+i);
     servo2.write(Pos2+i);
    
     delay(30);
  }
  Pos1+=n;
  Pos2+=n;

 

  for(i=0; i<= n; i++){
     servo1.write(Pos1-i);
     servo2.write(Pos2-i);
     
     delay(30);
  }
  Pos1-=n;
  Pos2-=n;


  /*
  PositionDuServo = analogRead(PinPot);
  PositionDuServo= map(PositionDuServo, 0, 1023, 0, 180);//produit en croix
  MonServo.write(PositionDuServo);
  delay(15);
  */
}
