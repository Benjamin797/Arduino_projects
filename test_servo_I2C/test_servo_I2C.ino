#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVOMIN  150 
#define SERVOMAX  600


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60); 


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0 ) {
    int val = Serial.parseInt();

    map(val,0, 180, 150, 600);
    pwm.setPWM(0, 0, val);
    
    Serial.println(val);
  }
  
  

  

}
