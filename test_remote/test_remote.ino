// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
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
#define SERVO_FREQ 50
#define PULSEMIN  1000 // pulse length min en µs
#define PULSEMAX  2000 // pulse length max en µs
#define SERVOMIN 0//degré min du servo
#define SERVOMAX 180//degré max du servo
#define ANGLE_INIT 90
#define NB_SPEED 10

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();



typedef enum{
  LEVI,
  GUID,
}MODE_MOTEUR;

bool urgence = false;
bool Exit = false;
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 10
#define REMOTEXY_SERIAL_TX 11
#define REMOTEXY_SERIAL_SPEED 9600


// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,34,0,52,0,11,8,0,
  1,0,71,8,23,23,49,31,65,66,
  79,82,84,0,67,4,6,6,26,7,
  177,26,11,67,4,6,15,26,7,177,
  26,11,67,4,6,24,26,7,177,26,
  11,66,130,7,36,24,19,177,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t button_1; // =1 if button pressed, else =0 

    // output variables
  char text_1[11];  // string UTF8 end zero 
  char text_2[11];  // string UTF8 end zero 
  char text_3[11];  // string UTF8 end zero 
  int8_t level_1; // =0..100 level position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define PIN_BUTTON_1 13

int level = 0;
void setup() 
{
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(SERVO_FREQ);
  RemoteXY_Init (); 
  pinMode (PIN_BUTTON_1, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  SetServo(ANGLE_INIT,10);//float angle voulu,int pas d'incrementation (entre 1 et NBSPEED,permet de varier la vitesse du servo)
  //SetSpeed(LEVI,0,10);
  //SetSpeed(GUID,0,10);
  delay(5000);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  //digitalWrite(PIN_BUTTON_1, (RemoteXY.button_1==0)?LOW:HIGH);
  
  //SetServo(180,10);
  //SetServo(0,10);
//  sprintf(RemoteXY.text_1,"%d",level);
//  RemoteXY.level_1 = level;
//  level +=1;
//  if (level==100)
//    level = 0;
  
  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay() 


}


void SetServo(float angle, int pas){
  
static float angle_prev = AngleToPulse(0);
angle = AngleToPulse(angle);
if (angle_prev<angle){
  while((angle_prev<angle) & (urgence == false)){
    if(digitalRead(PIN_BUTTON_1)==1) {urgence=true;}
    else{
    pwm.writeMicroseconds(SERVO1_PIN,angle_prev);
    pwm.writeMicroseconds(SERVO2_PIN,angle_prev);  
    BatteryLevel();
    angle_prev+=pas;
    }
  }
   
}else{
  while((angle_prev>angle) & urgence == false ){
    if(digitalRead(PIN_BUTTON_1)==1) {urgence=true;}
    else{
    pwm.writeMicroseconds(SERVO1_PIN,angle_prev);
    pwm.writeMicroseconds(SERVO2_PIN,angle_prev); 
    BatteryLevel();
    angle_prev-=pas;  
    } 
  }
}
if(angle_prev != angle){
  Abort();
}else{
  angle_prev = angle;
}

}

float AngleToPulse(float val){
  
 return (float)map(val,SERVOMIN , SERVOMAX, PULSEMIN, PULSEMAX);
}

void BatteryLevel(){
  //float getLevel = analogRead(BATTERIE_PIN);//récupere la tension (entre 0 et 1023)
  static float getLevel = 1023;
  float minValue = 1023*TensionMin/5;//conversion Tension Min sur 10 bits
  float maxValue = 1023*TensionMax/5;//conversion Tension Max sur 10 bits
 
  float getLevel_percentage = (getLevel - minValue)/(maxValue - minValue)*100; //get level en pourcentage (diff actuelle/diff max)
  Serial.println(getLevel_percentage);
  if (getLevel_percentage > 100){
    getLevel_percentage = 100;
    
  }
  else if (getLevel_percentage <= BatterieSeuil & Exit == false) {//Exit permet de n'activer qu'une fois la fonction Abort(), sinon imbrication des Abort() lors de SetServo
    urgence=true;//permet de sortir des boucles while de SetServo et SetSpeed des que le seuil minimum est franchi
  }else{
    getLevel-=1;
    
  }
  
}

void SetSpeed(MODE_MOTEUR mode, float Speed, int pas){
  static float vitesse_prev = PULSEMIN;
  static float vitesse = (Speed/100+1)*PULSEMIN;
  int num;
  
if(mode == LEVI){
  num = MOTEURLEVI_PIN;
}
if(mode == GUID){
  num = MOTEURGUID_PIN;
}

if (vitesse_prev<vitesse){
while((vitesse_prev<vitesse) & (urgence == false)){
   pwm.writeMicroseconds(num,vitesse_prev);
   pwm.writeMicroseconds(num+1,vitesse_prev);
   pwm.writeMicroseconds(num+2,vitesse_prev);
   pwm.writeMicroseconds(num+3,vitesse_prev);
   BatteryLevel();
   vitesse_prev+=pas;
}
}else{
  while((vitesse_prev>vitesse) & (urgence == false)){
   pwm.writeMicroseconds(num,vitesse_prev);
   pwm.writeMicroseconds(num+1,vitesse_prev);
   pwm.writeMicroseconds(num+2,vitesse_prev);
   pwm.writeMicroseconds(num+3,vitesse_prev);
   BatteryLevel();
   vitesse_prev-=pas;
   
  }
}
 if(vitesse_prev != vitesse){
  Abort();
 }else{
  vitesse_prev = vitesse;
 } 
}
void Abort() {
 Exit = true;
 Serial.println("Abort");
 while(true){
    urgence=false;
     SetSpeed(LEVI,0,10);
     SetSpeed(GUID,0,10);
     SetServo(90,10);
    
} 
}


//void SetServo(float angle, unsigned long pas){
//  
//  static float angle_prev = 0;
//  static unsigned long startTime = 0;
//  unsigned long currentTime = millis();
//if(digitalRead(LED_BUILTIN)==LOW){ 
//  if(currentTime - startTime >=(NBSPEED+1-pas)){
//    startTime = currentTime;
//    if(angle_prev<angle){
//    pwm.writeMicroseconds(SERVO1_PIN,AngleToPulse(angle_prev));
//    pwm.writeMicroseconds(SERVO2_PIN,AngleToPulse(angle_prev));
//    angle_prev++;
//    }else{
//      pwm.writeMicroseconds(SERVO1_PIN,AngleToPulse(angle_prev));
//      pwm.writeMicroseconds(SERVO2_PIN,AngleToPulse(angle_prev));
//      angle_prev--;
//    }
//    if(angle_prev == angle) {
//    angle_prev = angle;
//    
//    }
//  } 
//  }
//}
