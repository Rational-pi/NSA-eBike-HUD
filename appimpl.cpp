#include "appimpl.h"
#include "src/1602-AAF/ui_menu_base.h"
#include "src/1602-AAF/ui_valueeditor.h"

bool AppImpl::AppOnMode(){return true;}

Ui_Base *AppImpl::AppInit(){
    Ui_Menu_Base* ui=new Ui_Menu_Base(this);
    return ui
            ->addItem("valEditTest",EditorBuilder(AppImpl,val))
            ->addItem("uiFactoryTest",BaseBuilder);
}

void AppImpl::AppLoop(){}

void AppImpl::AppDelete(){}
