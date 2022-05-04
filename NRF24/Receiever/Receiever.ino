
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // CE, CSN

const byte address[6] = "00001";
int LED = 3;
byte val;

//This function will only set the value to  0 if the connection is lost...
void resetData() 
{
  val = 0;  
}

void setup() {
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);//il lit
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.startListening();
}

unsigned long lastRecvTime = 0;
void recvData()
{
  while ( radio.available() )
  {
    radio.read(&val, sizeof(val));
    lastRecvTime = millis(); //here we receive the data
  }
}

void loop() {
  recvData();
  unsigned long now = millis();
  //Here we check if we've lost signal, if we did we reset the values 
  if ( now - lastRecvTime > 5000 ) {
  // Signal lost?
    Serial.println("lost");
    resetData();
  }
  Serial.println(val);
  digitalWrite(LED, val);
}
