#include<Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include <SPI.h>


Servo esc;
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

int PinM = 8;//Esc en D8
int PinP = A0;//Potentiometre en A0


void setup() {
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 display.clearDisplay();

 esc.attach(PinM);

 Serial.begin(9600);

}

void loop() {
  
  int val;
  
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(25,10);
  
  val = analogRead(PinP);
  val = map(val, 0, 1023,0,50);
  
  esc.write(val);
  display.print(val);
  display.display();
  delay(20);

}
