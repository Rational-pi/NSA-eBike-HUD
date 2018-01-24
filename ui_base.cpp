#include "ui_base.h"
#include "Arduino.h"

Ui_Base::Ui_Base(App *app):InputListener(app),needRendering(true){}

void Ui_Base::compute()
{

}

void Ui_Base::render()
{
    if (needRendering){
        app->lcd.clear();
        app->lcd.setCursor(0,0);
        app->lcd.print("UI");
        app->lcd.setCursor(0,1);
        app->lcd.print("NOT IMPLEMENTED");
    }needRendering=false;
}
