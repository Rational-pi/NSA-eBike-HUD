#ifndef APP_H
#define APP_H
#define UI_MAX_DEPTH 10

#include "LiquidCrystal.h"


class Ui_Base;

class App
{
    Ui_Base *UiArray[UI_MAX_DEPTH];
    uint8_t UiID;
    void welcomeAnimation(uint8_t charDelay);
public:
    void openSubUI(Ui_Base *subUi);
    App(uint8_t rs, uint8_t enable,
        uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3);
    void run();
    LiquidCrystal lcd;
};

#endif // APP_H
