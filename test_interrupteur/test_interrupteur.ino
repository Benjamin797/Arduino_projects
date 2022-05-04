#include<Servo.h>
Servo servo; 

int led = 9;
int inter = 7;
int PinServo = 6;//Servomoteurs en D6
int PositionDuServo;
int lecture;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(inter,INPUT);
  servo.attach(PinServo);
  servo.write(PositionDuServo);

}

void loop() {
  // put your main code here, to run repeatedly:
  lecture= digitalRead(inter);
  if(lecture==0){
    digitalWrite(led, LOW);
    PositionDuServo= 0;
    servo.write(PositionDuServo);
  }
  else{
    digitalWrite(led,HIGH);
    PositionDuServo= 180;
    servo.write(PositionDuServo);
    
  }
  delay(15);

}


