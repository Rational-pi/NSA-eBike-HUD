#include "appimpl.h"
#include "src/1602-AAF/ui_menu_base.h"
#include "src/1602-AAF/ui_usriotester.h"
AppImpl *app;
void setup() {
    app=new AppImpl(12, 11, 10, 9, 8, 7);
}

void loop() {
    auto retUi_Base=[](App* a){return new Ui_Base(a);};
    Ui_Menu_Base* ui=new Ui_Menu_Base(app);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    ui->addItem("uiFactoryTest",retUi_Base);
    app->run(ui);
}
