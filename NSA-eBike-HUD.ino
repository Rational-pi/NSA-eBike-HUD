#include "appimpl.h"
AppImpl *app;
void setup() {
  app=new AppImpl(12, 11, 10, 9, 8, 7);
}

void loop() {
  app->run();
}
