#ifndef ardudummy
#define ardudummy
#include "inttypes.h"

#define INPUT 0

// interupt modes
#define LOW 0
#define CHANGE 0
#define RISING 0
#define FALLING 0
#define HIGH 0



uint8_t digitalRead(uint8_t DT){return DT;}
void pinMode(uint8_t pin, uint8_t mode){}
void attachInterrupt(uint8_t InPin, void(*)()  , uint8_t mode){}
unsigned long millis(){return 0;}
int analogRead(uint8_t pin){return 0;}
void init(){}
void delay(uint8_t millis){}

#endif ardudummy
