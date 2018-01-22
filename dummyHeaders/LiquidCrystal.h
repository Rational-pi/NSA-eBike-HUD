#ifndef LCDUMMY
#define LCDUMMY

#include "Arduino.h"

class LiquidCrystal
{
public:
    LiquidCrystal(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3){}
    void begin(uint8_t x, uint8_t y){}
    void setCursor(uint8_t,uint8_t){}
    void print(int){}
    void print(char){}
    void print(char[]){}
    void print(double ,int=2){}
    void clear(){}

};

#endif // LCDUMMY
