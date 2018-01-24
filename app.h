#ifndef APP_H
#define APP_H

#include "LiquidCrystal.h"

class App
{
    void welcomeAnimation(uint8_t charDelay);
public:
    App(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void run();
    LiquidCrystal lcd;
};

#endif // APP_H
