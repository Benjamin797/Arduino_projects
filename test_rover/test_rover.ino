

//our L298N control pins
const int LeftMotorForward = 7;
const int LeftMotorBackward = 6;
const int RightMotorForward = 4;
const int RightMotorBackward = 5;

//sensor pins
int pinTrig_1 = 28;//D2
int pinEcho_1 = 29;//D3

int pinTrig_2 = 30;//D2
int pinEcho_2 = 31;//D3

int pinTrig_3 = 32;//D2
int pinEcho_3 = 33;//D3


#define maximum_distance 200
boolean goesForward = false;
float distance = 100;
float distanceLeft = 0;
float distanceRight = 0;
long temps;



void moveForward(){

  //if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  //}
}

float readPing(int pinTrig, int pinEcho){
    digitalWrite(pinTrig,HIGH);
    delayMicroseconds(10);
    digitalWrite(pinTrig,LOW);
    
  

    temps= pulseIn (pinEcho,HIGH);//temps que la pin echo attende un retour du signal

    if (temps > 25000)//si distance > 4m 
    {
      return 30;
    }
    else
    {
      
      temps=temps/2;
     
      return (temps*340)/10000.0;
      
  }
 
}




void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}



void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(1000);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}
void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(1000);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  pinMode(pinTrig_1, OUTPUT);
  pinMode(pinEcho_1,INPUT);
  digitalWrite(pinTrig_1,LOW);

  pinMode(pinTrig_2, OUTPUT);
  pinMode(pinEcho_2,INPUT);
  digitalWrite(pinTrig_2,LOW);

  pinMode(pinTrig_3, OUTPUT);
  pinMode(pinEcho_3,INPUT);
  digitalWrite(pinTrig_3,LOW);
 
  readPing(pinTrig_1, pinEcho_1);

}

void loop() {
  // put your main code here, to run repeatedly:
 
  if(distance > 25)
  {
    moveForward();
    distance = readPing(pinTrig_1, pinEcho_1);
//    Serial.print("Distance: ");
//    Serial.print(distance);
//    Serial.println(" cm");
    

  }
  else{
    moveStop();
    moveBackward();
    delay(500);
    moveStop();
    delay(500);
    distance = readPing(pinTrig_1, pinEcho_1);
//    Serial.print("Distance: ");
//    Serial.print(distance);
//    Serial.println(" cm");
    delay(500);
    distanceLeft = readPing(pinTrig_2, pinEcho_2);
//    Serial.print("DistanceLeft: ");
//    Serial.print(distanceLeft);
//    Serial.println(" cm");
    

    if(distanceLeft > distance)
    {
      turnLeft();
      moveStop();
      distance = readPing(pinTrig_1, pinEcho_1);
    }
    else
    {
      turnRight();
      moveStop();
      distance = readPing(pinTrig_1, pinEcho_1);
    }
  }
  
}
