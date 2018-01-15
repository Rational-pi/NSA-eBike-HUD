#include "powermeter.h"
#include "Arduino.h"
#include "usrdata.h"
Powermeter::Powermeter(uint8_t voltagePin, uint8_t currentPin, UsrData *data):
    UsrDataUsr_base(data),
    voltagePin(voltagePin),
    currentPin(currentPin),
    lastMills(millis())
{
    if(data->loadedFromEEprom){
        this->data=data->powerData;
    }
}

Powermeter::~Powermeter()
{
    ParentusrData->powerData=data;
}

void Powermeter::read(){
    voltageReed=data.voltageReadRatio*analogRead(voltagePin);
    currentReed=data.currentReadRatio*analogRead(currentPin);
    unsigned long tmp=lastMills;
    data.powerCounted+=((lastMills=millis())-tmp)*voltageReed*currentReed/1000;//dt(s)*I*U
}
