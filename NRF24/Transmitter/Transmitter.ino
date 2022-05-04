#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int inter = 3;
RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";//adressage

byte val=0;

void setup() {
  Serial.begin(9600);
  pinMode(inter,INPUT);
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.openWritingPipe(address);
  
 
}

void loop() {
   //Serial.println("envoyé");
  val = digitalRead(inter);
  Serial.println(val);
  radio.write(&val, sizeof(val));
 
  
}
