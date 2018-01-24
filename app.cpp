#include "app.h"
#include <Arduino.h>
#include "usrdata.h"
#include "rotaryencoder.h"
#include "ui_base.h"
#include "ui_usriotester.h"
#include "ui_base.h"

App::App(uint8_t rs, uint8_t enable, uint8_t d0, uint8_t d1, uint8_t d2, uint8_t d3):
    lcd(rs,enable,d0,d1,d2,d3),
    UiID(0)
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

/// App is the owner of subUi then
void App::openSubUI(Ui_Base *subUi)
{
    if(UiID>=UI_MAX_DEPTH-1)return;
    UiArray[++UiID]=subUi;
}


#define RUNAPP true
#define ONMODE true
void App::run()
{
    /*APP*/{
        welcomeAnimation(50);
        int lastPose,thisPose;
        UiArray[UiID]=new UI_usrIOtester(this);
        //UsrData *data;
        //Powermeter *pm;
        //Tachometer *tm;
        while (RUNAPP) {
            //data=UsrData::build(0);/*give you the property*/ /* new UsrData(); */
            //pm=new Powermeter(7,0,data);
            //tm=new Tachometer(data);
            RotaryENcoder::initRotary();
            lastPose=RotaryENcoder::getPose();

            while (ONMODE){
                //UI navigation
                if(UiArray[UiID]->exitRequested && UiID!=0){
                    delete UiArray[UiID];
                    UiID--;
                }

                //Encoder rotation event emiting
                thisPose=RotaryENcoder::getPose();
                if (thisPose!=lastPose){
                    UiArray[UiID]->HandleDelta(thisPose-lastPose);
                    lastPose=thisPose;
                }

                //Encoder click event emmiting
                if(RotaryENcoder::clicked())UiArray[UiID]->HandleClick();

                //Compute
                UiArray[UiID]->compute();

                //Render
                UiArray[UiID]->render();
            }
            //UsrData::wright(data);
            //delete data;
            //delete pm;
            //delete tm;
            while (!ONMODE){
                delay(200);
            }
        }
    }

    float read=analogRead(7);
    float ratio=45.3653174f/1024;
    while (true){
        lcd.clear();
        lcd.setCursor(10,1);
        lcd.print(ratio*(read=read*0.95f+analogRead(7)*0.05f),3);
        lcd.setCursor(15,1);
        lcd.print("V");
    }
}
