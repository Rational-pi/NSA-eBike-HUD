#include "appimpl.h"
#include "AppLibNSA/ui_usriotester.h"
AppImpl *app;
void setup() {
  app=new AppImpl(12, 11, 10, 9, 8, 7);
}

void loop() {
  app->run(new UI_usrIOtester(app));
}
