#ifndef POWERMETER_H
#define POWERMETER_H
#include "inttypes.h"

class PowerMeter
{
public:
    struct Calib{
        float currentReadRatio;
        float voltageReadRatio;
    }calib;
    PowerMeter(uint8_t voltagePin, uint8_t currentPin);
    void read();
private:
    unsigned long lastMills;
    uint8_t voltagePin;
    uint8_t currentPin;
    float voltageReed;
    float currentReed;
    float power;
};

#endif // POWERMETER_H
