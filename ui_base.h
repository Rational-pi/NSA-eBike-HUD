#ifndef UI_BASE_H
#define UI_BASE_H

#include "inputlistener.h"

struct Ui_Base : public InputListener
{
    Ui_Base(App *app);
    virtual void compute();
    virtual void render();
};

#endif // UI_BASE_H
