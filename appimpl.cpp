#include "appimpl.h"
#include "src/1602-AAF/ui_menu_base.h"

bool AppImpl::AppOnMode(){return true;}

Ui_Base *AppImpl::AppInit(){
    auto retUi_Base=[](App* a){return new Ui_Base(a);};
    Ui_Menu_Base* ui=new Ui_Menu_Base(this);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    return ui;
}

void AppImpl::AppLoop(){}

void AppImpl::AppDelete(){}
