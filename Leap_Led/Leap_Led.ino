int val; int led = 13;           // the pin that the LED is attached to 

int brightness = 0;    // how bright the LED is

int fadeAmount = 5;    // how many points to fade the LED by // the setup routine runs once when                                                            you press reset:

 void setup() 

{   Serial.begin(9600);  

pinMode(led, OUTPUT); } // the loop routine runs over and over again forever:


void loop() 

{    if (Serial.available() == 'n') {      //  Check if there is a new message 

val= Serial.read();      // 1st fragment     
 

if (val<60) {       
digitalWrite(led,LOW);       }     

  if (val>60) {     
    digitalWrite(led,HIGH);       }  }}
