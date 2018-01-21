#ifndef USRDATA_H
#define USRDATA_H

#include <avr/eeprom.h>
#include <inttypes.h>

#define V1 0x0001

#include "powermeter.h"
#include "tachometer.h"

struct UsrData{
    bool loadedFromEEprom;
    Powermeter::Data powerData;
    Tachometer::Data tachometerData;
    static void wright(UsrData *x);
    static UsrData *build(uint16_t memoryOffset);
private:
    UsrData();
    static UsrData *read(uint16_t memoryOffset);
    static uint16_t version;
    uint16_t memoryOffset;
};


#endif // USRDATA_H
