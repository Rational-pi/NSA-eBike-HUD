#ifndef POWERMETER_H
#define POWERMETER_H
#include "inttypes.h"


#include "usrdatausr_base.h"

struct Powermeter: public UsrDataUsr_base
{
    struct Data{
        float currentReadRatio;
        float voltageReadRatio;
        float maxPower;
        float powerCounted;
    };
    Powermeter(uint8_t voltagePin, uint8_t currentPin, UsrData *data);
    ~Powermeter();
    void read();
private:
    Data data;
    unsigned long lastMills;
    uint8_t voltagePin;
    uint8_t currentPin;
    float voltageReed;
    float currentReed;
};

#endif // POWERMETER_H
