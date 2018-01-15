#ifndef TACHOMETER_H
#define TACHOMETER_H

#include "inttypes.h"
#include "usrdatausr_base.h"

struct Tachometer : public UsrDataUsr_base
{
    struct Data{
        float wheelDistance;
        float currentDistance;
    };
    Tachometer(UsrData *data);
    ~Tachometer();
    void tick(uint8_t wheelTurnCount);
    void setDistance(float distance);
private:
    Data data;
};

#endif // TACHOMETER_H
