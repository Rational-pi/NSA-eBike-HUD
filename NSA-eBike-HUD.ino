#include "appimpl.h"
#include "src/1602-AAF/ui_menu_base.h"
#include "src/1602-AAF/ui_usriotester.h"
AppImpl *app;
void setup() {
    app=new AppImpl(12, 11, 10, 9, 8, 7);
}

void loop() {
    app->run();
}
