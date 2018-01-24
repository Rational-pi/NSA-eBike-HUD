#ifndef ROTARYENCODER_H
#define ROTARYENCODER_H

#include <Arduino.h>
#include "LiquidCrystal.h"

namespace RotaryENcoder {

void initRotary(LiquidCrystal &lcd);

int getPose();

}


#endif // ROTARYENCODER_H
