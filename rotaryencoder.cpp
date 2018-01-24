#include "rotaryencoder.h"

namespace RotaryENcoder {
LiquidCrystal *lcd;
uint8_t state;
int16_t pose;
uint8_t lastCLK=0x01;

void CBintEncoder(){
    state=PIND;
    /*false pulses are always the same clk as before, so we escape them*/
    if((state>>2&0x01)==lastCLK)return;
    lastCLK=state>>2&0x01;

    switch (state&0x14) {
    case 4:/*CW*/
        pose++;
        break;
    case 20:/*CCW*/
        pose--;
        break;
    }
}

}



void RotaryENcoder::initRotary(LiquidCrystal &lcd)
{
    RotaryENcoder::lcd=&lcd;
    pose=0;
    pinMode(1, INPUT);
    pinMode(2, INPUT);
    pinMode(4, INPUT);
    attachInterrupt(0/*digital pin 2*//*CLK*/, CBintEncoder, CHANGE);
}

int RotaryENcoder::getPose()
{
    return pose;
}
