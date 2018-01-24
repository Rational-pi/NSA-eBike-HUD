#include "ui_base.h"

Ui_Base::Ui_Base(App *app):InputListener(app){}

void Ui_Base::render()
{
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    app->lcd.print("UI");
    app->lcd.setCursor(0,1);
    app->lcd.print("NOT IMPLEMENTED");
}
