
#include <Servo.h>

Servo servo6;
Servo servo5;
Servo servo4;
Servo servo3;
Servo servo2;
Servo servo1;

int Pin6 = 5;
int Pin5 = 4;
int Pin4 = 3;
int Pin3 = 40;
int Pin2 = 31;
int Pin1 = 30;


int val_6;
int val_5;
int val_4;
int val_3;
int val_2;
int val_1;

int Pos6 = 0;
int Pos5 = 90;
int Pos4 = 90;
int Pos3 = 160;
int Pos2 = 120;
int Pos1 = 90;

bool Previous;
bool Current;

void Initi()
{
  Serial.begin(9600);
  servo6.attach(Pin6);
  servo6.write(Pos6);

  servo5.attach(Pin5);
  servo5.write(Pos5);

  servo4.attach(Pin4);
  servo4.write(Pos4);

  servo3.attach(Pin3);
  servo3.write(Pos3);

  servo2.attach(Pin2);
  servo2.write(Pos2);

  servo1.attach(Pin1);
  servo1.write(Pos1);
  
}
void ReceiveData(){
  
    val_6 = Serial.parseInt();
    val_5 = Serial.parseInt();
    val_4 = Serial.parseInt();
    val_1 = Serial.parseInt();
    val_3 = Serial.parseInt();
    val_2 = Serial.parseInt();
    Serial.read();
}
void Pince(){
  
   
    if (val_6<50){
      servo6.write(0);
      Current = 1;
      
    }
  
    
    if (val_6>50){
      servo6.write(180);
      Current = 0;
      
    }
  
}

void Servos (int val,Servo servo, int fromLow, int fromHigh, int toLow, int toHigh, int Pos){
  val = map(val,fromLow,fromHigh,toLow,toHigh);
  servo.write(val);
  //Pos = val;
  
}


void setup() {
  // put your setup code here, to run once:
  Initi();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() == '\n') {
      ReceiveData();

      Servos(val_5,servo5,-80,80,0,180,Pos5);
      Servos(val_4,servo4,-25,25,40,110,Pos4);
      Servos(val_3,servo3,600,200,180,100,Pos3);
      Servos(val_2,servo2,15,60,120,30,Pos2);
      Servos(val_1,servo1,600,1200,0,180,Pos1);
      Pince();
      
      
  } 
}
