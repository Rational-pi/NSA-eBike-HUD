#include "tachometer.h"
#include "usrdata.h"

Tachometer::Tachometer(UsrData *data):
    UsrDataUsr_base(data)
{
    if(data->loadedFromEEprom){
        this->data=data->tachometerData;
    }
}

Tachometer::~Tachometer()
{
    ParentusrData->tachometerData=data;
}

void Tachometer::tick(uint8_t wheelTurnCount)
{
    data.currentDistance+=wheelTurnCount*data.wheelDistance;
}

void Tachometer::setDistance(float distance)
{
    data.currentDistance=distance;
}
