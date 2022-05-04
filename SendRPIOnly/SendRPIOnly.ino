#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

#include <SPI.h>

RF24 radio(9, 10); //Ce et Csn pins

const uint64_t pipe[] = {0xF0F0F0F0E1LL , 0xE8E8F0F0E1LL};


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.setChannel(0x76);
  
  radio.setPALevel(RF24_PA_MAX);
  
  radio.openWritingPipe(pipe[1]);
 
  radio.enableDynamicPayloads();
  radio.powerUp();

}

void loop() {
  
  const char text[] = "Hello World!";
  Serial.println("envoyé");
  radio.write(&text, sizeof(text));
 
  delay(1000);
}
