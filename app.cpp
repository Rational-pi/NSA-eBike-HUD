#include "app.h"
#include <Arduino.h>
#include "usrdata.h"

#define LED_PIN     13
#define DELAY_MS    200

App::App()
{
    init();// Initialize Arduino Librairies
    pinMode(LED_PIN, OUTPUT);
    Serial.begin(9600);
}

void App::run()
{
    UsrData *ee=UsrData::build();
    ee->num+=1;
    UsrData::wright(ee);
    while (true){

        for (unsigned int t=0; t<sizeof(ee->num); t++)
            Serial.write(((char*)&ee->num)[t]);
    }
}
