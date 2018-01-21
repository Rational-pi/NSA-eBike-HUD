#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H

#include <Arduino.h>
#include "LiquidCrystal.h"

namespace RotaryENcoder {

void initRotary();

int getPose();

}


#endif // ROTARYENCODER_H
