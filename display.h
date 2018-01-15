#ifndef DISPLAY_H
#define DISPLAY_H

#include "usrdatausr_base.h"

struct Powermeter;
struct Tachometer;
struct Display : public UsrDataUsr_base
{
    struct Data{
    };
    Display(Powermeter *pm,Tachometer *tm,UsrData* data);
    ~Display();
private:
    Data data;
};

#endif // DISPLAY_H
