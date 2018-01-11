#include "app.h"
#include <Arduino.h>

#define LED_PIN     13
#define DELAY_MS    200

App::App()
{
    init();// Initialize Arduino Librairies
    pinMode(LED_PIN, OUTPUT);
}

void App::run()
{
    while (true){
        digitalWrite(LED_PIN, HIGH);
        delay(DELAY_MS);
        digitalWrite(LED_PIN, LOW);
        delay(DELAY_MS);
    }
}
