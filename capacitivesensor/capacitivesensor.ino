#include <CapacitiveSensor.h>
CapacitiveSensor Sensor1 = CapacitiveSensor(4, 6);
CapacitiveSensor Sensor2 = CapacitiveSensor(8, 10);
long val1;
long val2;
int pos = 0;
int led1 = 14;
int led2 = 15;
int threshold = 200;
#define led 13
void setup(){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}
  
void loop(){
  val1 = Sensor1.capacitiveSensor(30);
  val2 = Sensor2.capacitiveSensor(30);
  Serial.print(val1);Serial.print(" ");
  Serial.print("\t");Serial.print(val2);
  Serial.print(" ");Serial.print("\t");
  Serial.println();delay(2);
  if (val1 >= threshold ){
    digitalWrite(led, HIGH);
    digitalWrite(led1, HIGH);
    //pos = 1;
    delay(50);
    }
  else {
       digitalWrite(led1, LOW);
      
    }
//  else if (val1 >= threshold  && pos == 1){
//    digitalWrite(led, LOW);
//    digitalWrite(led1, LOW);
//    pos = 0;
//    delay(500);
//    }
  if (val2 >= threshold ){
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    //pos = 1;
    delay(50);
    }
    else {
       digitalWrite(led2, LOW);
      
    }
//  else if (val2 >= 100 && pos == 1){
//    digitalWrite(led, LOW);
//    digitalWrite(led2, LOW);
//    pos = 0;
//    delay(500);
//    }
  delay(10);}
