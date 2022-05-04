#include "Capt.h"
#include "Arduino.h"

Capt::Capt(){

}

void Capt::task_ILS1(){
  static unsigned long previousMillisILS01 = 0;
  static byte DebutILS01 = LOW;
  unsigned long currentMillisILS01 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS01)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS01 == LOW) {
        // Garde en memoire la valeur actuelle de millis()
          previousMillisILS01 = currentMillisILS01;
          DebutILS01 = HIGH;
          Serial.println("ILS01 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS01 - previousMillisILS01 >= INTERVAL_ILS) {
        if (DebutILS01 == HIGH) {
         DebutILS01 = LOW;
          Serial.println("ILS01 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}

//======================================================================================
void Capt::task_ILS2() {
  static unsigned long previousMillisILS02 = 0;
  static byte DebutILS02 = LOW;
  unsigned long currentMillisILS02 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS02)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS02 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisILS02 = currentMillisILS02;
          DebutILS02 = HIGH;
          Serial.println("ILS02 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS02 - previousMillisILS02 >= INTERVAL_ILS) {
        if (DebutILS02 == HIGH) {
         DebutILS02 = LOW;
          Serial.println("ILS02 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}

//======================================================================================
void Capt::task_ILS3() {
  static unsigned long previousMillisILS03 = 0;
  static byte DebutILS03 = LOW;
  unsigned long currentMillisILS03 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS03)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS03 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisILS03 = currentMillisILS03;
          DebutILS03 = HIGH;
          Serial.println("ILS03 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS03 - previousMillisILS03 >= INTERVAL_ILS) {
        if (DebutILS03 == HIGH) {
         DebutILS03 = LOW;
          Serial.println("ILS03 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}

//======================================================================================
void Capt::task_ILS4() {
  static unsigned long previousMillisILS04 = 0;
  static byte DebutILS04 = LOW;
  unsigned long currentMillisILS04 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS04)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS04 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisILS04 = currentMillisILS04;
          DebutILS04 = HIGH;
          Serial.println("ILS04 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS04 - previousMillisILS04 >= INTERVAL_ILS) {
        if (DebutILS04 == HIGH) {
         DebutILS04 = LOW;
          Serial.println("ILS04 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}

//======================================================================================
void Capt::task_ILS5() {
  static unsigned long previousMillisILS05 = 0;
  static byte DebutILS05 = LOW;
  unsigned long currentMillisILS05 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS05)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS05 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisILS05 = currentMillisILS05;
          DebutILS05 = HIGH;
          Serial.println("ILS05 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS05 - previousMillisILS05 >= INTERVAL_ILS) {
        if (DebutILS05 == HIGH) {
         DebutILS05 = LOW;
          Serial.println("ILS05 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}


//======================================================================================
void Capt::task_ILS6() {
  static unsigned long previousMillisILS06 = 0;
  static byte DebutILS06 = LOW;
  unsigned long currentMillisILS06 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (LOW == digitalRead(ILS06)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutILS06 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisILS06 = currentMillisILS06;
          DebutILS06 = HIGH;
          Serial.println("ILS06 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisILS06 - previousMillisILS06 >= INTERVAL_ILS) {
        if (DebutILS06 == HIGH) {
         DebutILS06 = LOW;
          Serial.println("ILS06 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}

//======================================================================================


void Capt::task_IR01() {
  static unsigned long previousMillisIR01 = 0;
  static byte DebutIR01 = LOW;
  unsigned long currentMillisIR01 = millis();
   // si etat de ils2 est diff�rent de celui pr�c�dent
  if (HIGH == digitalRead(IR01)) {
         // initialise les valeurs pour l'intervall de pause
         if (DebutIR01 == LOW) {
        // Garde en m�moire la valeur actuelle de millis()
          previousMillisIR01 = currentMillisIR01;
          DebutIR01 = HIGH;
          Serial.println("CIR01 1");      /// ajouter le nom du capteur :   <  IL02 + 1  >
          }
   }
  else {
      if(currentMillisIR01 - previousMillisIR01 >= INTERVAL_IR) {
        if (DebutIR01 == HIGH) {
         DebutIR01 = LOW;
          Serial.println("CIR01 0");      /// ajouter le nom du capteur :   <  IL02 + 0
          }
      }
  }
}
