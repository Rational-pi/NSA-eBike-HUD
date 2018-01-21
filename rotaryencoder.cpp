#include "rotaryencoder.h"

namespace RotaryENcoder {
uint8_t SW, DT, CLK;
int16_t pose;

void CBintEncoder(){
    uint8_t DtEnterState=digitalRead(DT);
    while (!digitalRead(DT) || !digitalRead(CLK)) {
    }
    pose+=DtEnterState?1:-1;
}
}



void RotaryENcoder::initRotary()
{
    DT=0;
    SW=1;
    CLK=2;
    pose=0;
    pinMode(DT, INPUT);
    pinMode(SW, INPUT);
    pinMode(CLK, INPUT);
    attachInterrupt(0, CBintEncoder, LOW);
}

int RotaryENcoder::getPose()
{
    return pose;
}
