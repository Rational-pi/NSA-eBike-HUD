#include "ui_usriotester.h"

UI_usrIOtester::UI_usrIOtester(App *app):
    Ui_Base(app),
    count(0),
    toogle(false),
    changed(true)
{

}

void UI_usrIOtester::render(){
    if (!changed)return;
    app->lcd.clear();
    app->lcd.setCursor(0,0);
    app->lcd.print("42 to Pose  :");
    app->lcd.setCursor(13,0);
    app->lcd.print(count);
    app->lcd.setCursor(0,1);
    app->lcd.print("Exit  Switch:");
    app->lcd.setCursor(13,1);
    app->lcd.print(toogle);
    changed=false;
}

void UI_usrIOtester::HandleClick(){
    changed=true;
    toogle=!toogle;
}

void UI_usrIOtester::HandleDelta(int8_t delta){
    changed=true;
    count+=delta;
}

void UI_usrIOtester::compute()
{
    if (count==42){
        app->openSubUI(new Ui_Base(app));
    }
}
