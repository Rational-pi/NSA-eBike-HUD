#ifndef UI_BASE_H
#define UI_BASE_H

#include "inputlistener.h"

struct Ui_Base : public InputListener
{
    Ui_Base();
    void compute();
    void render();
};

#endif // UI_BASE_H
