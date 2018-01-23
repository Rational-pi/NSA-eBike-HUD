#include "app.h"
#include <Arduino.h>
#include "usrdata.h"
#include "rotaryencoder.h"

App::App(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
    lcd(rs,enable,d0,d1,d2,d3)
{
    init(); /* Initialize Arduino Librairies */
    lcd.begin(16, 2); // Enables the LCD

}

void App::welcomeAnimation(uint8_t charDelay)
{
    char text[] ="eBike-HUD by";
    delay(charDelay);
    for (int i = 0; i < sizeof(text)-1; ++i) {
        lcd.setCursor(i+2,0);
        lcd.print(text[i]);
        delay(charDelay);
    }
    char text2[]="Nicolas SALMIERI";
    delay(charDelay);
    for (int i = 0; i < sizeof(text2)-1; ++i) {
        lcd.setCursor(i,1);
        lcd.print(text2[i]);
        delay(charDelay);
    }delay(500);
}



void App::run()
{
    welcomeAnimation(50);
    /*APP*/{
        UsrData *data;
        Powermeter *pm;
        Tachometer *tm;
        while (false) {

            data=UsrData::build(0);/*give you the property*/ /* new UsrData(); */
            pm=new Powermeter(7,0,data);
            tm=new Tachometer(data);

            while (/*PowerON*/true){
                /*UPDATE STATE*/
            }UsrData::wright(data);

            delete data;
            delete pm;
            delete tm;

            while (/*PowerOFF*/false){
                delay(200);
            }
        }
    }


    RotaryENcoder::initRotary(lcd);
    int count=0;
    float read=analogRead(7);
    float ratio=45.3653174f/1024;
    uint8_t state;
    Serial.begin(9600);
    while (true){
        Serial.println(RotaryENcoder::getPose());
    }
}
