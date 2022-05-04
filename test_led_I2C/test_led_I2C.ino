
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(); 
void setup() {
  // put your setup code here, to run once:

    pwm.begin();
    pwm.setPWMFreq(60); 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<4095; i+=3){
    pwm.setPWM(3, 0 , i);
    //delay(15);
  }

  for(int i=4095; i>0; i-=3){
    pwm.setPWM(3, 0 , i);
    //delay(15);
  }
//    for(int i=3; i<12; i++){
//    pwm.setPWM(i, 0, 4095);
//    delay(100);
//    }
//    for(int i=3; i<12; i++){
//    pwm.setPWM(i, 4095, 0);
//    delay(100);
//    }
//    
}
