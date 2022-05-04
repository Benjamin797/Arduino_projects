#include<Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>

#define OLED_RESET 4

Servo esc;
Servo servo; 
Adafruit_SSD1306 display(OLED_RESET);

//oled: sda = A4
//      scl= A5
int PinESC = 8;//Esc en D8
int PinP1 = A0;//Potentiometre en A0
int PinServo = 6;//Servomoteurs en D6
int led = 9;//led en D9
int inter = 7;//interrupteur en D7

int PositionDuServo;
int lecture;
int val;

void setup() {
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.clearDisplay();
 pinMode(led,OUTPUT);
 pinMode(inter,INPUT);

 esc.attach(PinESC);
 servo.attach(PinServo);
 servo.write(PositionDuServo);
 Serial.begin(9600);
}

void loop() {
 Oled();
 servomoteur();
 RS_Motor();
  


}

void servomoteur(){
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

void Oled(){
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(25,10);
  
}

void RS_Motor(){
  val = analogRead(PinP1);
  val = map(val, 0, 1023,0, 100);
  esc.write(val);
  
  display.println(val);
  display.display();
  delay(15);

 }


