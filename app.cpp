#include "app.h"
#include <Arduino.h>
#include "usrdata.h"

App::App()
{
    init(); /* Initialize Arduino Librairies */
}

void App::run()
{
    UsrData *data;
    Powermeter *pm;
    Tachometer *tm;
    Display *dip;

    while (true) {

        data=UsrData::build(0);/*give you the property*/ /* new UsrData(); */
        pm=new Powermeter(0,0,data);
        tm=new Tachometer(data);
        dip=new Display(pm,tm,data);

        while (/*PowerON*/true){
            /*UPDATE STATE*/
        }UsrData::wright(data);

        delete data;
        delete pm;
        delete tm;
        delete dip;

        while (/*PowerOFF*/false){
            delay(200);
        }
    }
}
