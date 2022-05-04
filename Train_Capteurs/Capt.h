#ifndef CAPT_H_INCLUDED
#define CAPT_H_INCLUDED

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

class Capt {

  private :
  const unsigned long INTERVAL_ILS = 4000;
  const unsigned long INTERVAL_IR = 4000;
  const int ILS01 = 22;
  const int ILS02 = 24;
  const int ILS03 = 26;
  const int ILS04 = 28;
  const int ILS05 = 30;
  const int ILS06 = 32;

  const int IR01 = 42;


  public :

  Capt();
  void task_ILS1();
  void task_ILS2();
  void task_ILS3();
  void task_ILS4();
  void task_ILS5();
  void task_IR01();
  void task_ILS6();
  
};


#endif // CAPT_H_INCLUDED
