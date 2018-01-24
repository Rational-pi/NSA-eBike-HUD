#ifndef APPIMPL_H
#define APPIMPL_H
#include "AppLibNSA/app.h"

struct AppImpl:public App
{
    AppImpl(uint8_t rs,
            uint8_t enable,
            uint8_t d0,
            uint8_t d1,
            uint8_t d2,
            uint8_t d3):
        App(rs,enable,d0,d1,d2,d3){}
protected:
    virtual bool AppOnMode();
    virtual void AppInit();
    virtual void AppLoop();
    virtual void AppDelete();
};

#endif // APPIMPL_H
