#include "powermeter.h"
#include "Arduino.h"
PowerMeter::PowerMeter(uint8_t voltagePin, uint8_t currentPin):
    voltagePin(voltagePin),
    currentPin(currentPin),
    lastMills(millis())
{
}

void PowerMeter::read(){
    voltageReed=calib.voltageReadRatio*analogRead(voltagePin);
    currentReed=calib.currentReadRatio*analogRead(currentPin);
    unsigned long tmp=lastMills;
    power+=((lastMills=millis())-tmp)*voltageReed*currentReed/1000;//dt(s)*I*U
}
