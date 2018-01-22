#include "app.h"
App *app;
void setup() {
  app=new App(12, 11, 10, 9, 8, 7);
}

void loop() {
  app->run();
}
