#include "rotaryencoder.h"

namespace RotaryENcoder {
LiquidCrystal *lcd;
uint8_t last=0;
uint8_t SW, DT, CLK;
int16_t pose;

void CBintEncoder(){
    uint8_t val= PIND&0x05;
    if (val==4&&last==1)/*CW*/pose+=1;/*1>4*/
    if (val==5&&last==0)/*CCW*/pose-=1;/*0>5*/
    if (val&0x04==0x00) last=val;

    lcd->clear();
    lcd->setCursor(0,0);
    lcd->print(val);
    lcd->setCursor(0,1);
    lcd->print(pose);
}

}



void RotaryENcoder::initRotary(LiquidCrystal &lcd)
{
    RotaryENcoder::lcd=&lcd;
    DT=0;
    SW=1;
    CLK=2;
    pose=0;
    pinMode(DT, INPUT);
    pinMode(SW, INPUT);
    pinMode(CLK, INPUT);
    attachInterrupt(0/*digital pin 2*//*CLK*/, CBintEncoder, CHANGE);
}

int RotaryENcoder::getPose()
{
    return pose;
}
