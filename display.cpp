#include "display.h"
#include "usrdata.h"

Display::Display(Powermeter *pm,Tachometer *tm,UsrData* data):
    UsrDataUsr_base(data)
{
    if(data->loadedFromEEprom){
        this->data=data->displayData;
    }
}

Display::~Display()
{
    ParentusrData->displayData=data;
}
