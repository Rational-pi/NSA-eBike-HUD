INCLUDEPATH += \
    $$PWD/src/1602-AAF \
    $$PWD/../ArduinoHeaders


SOURCES += \
    usrdatausr_base.cpp \
    powermeter.cpp \
    tachometer.cpp \
    usrdata.cpp \
    src/1602-AAF/app.cpp \
    appimpl.cpp \
    src/1602-AAF/inputlistener.cpp \
    src/1602-AAF/rotaryencoder.cpp \
    src/1602-AAF/ui_base.cpp \
    src/1602-AAF/ui_menu_base.cpp \
    src/1602-AAF/ui_usriotester.cpp

HEADERS += \
    usrdatausr_base.h \
    powermeter.h \
    tachometer.h \
    appimpl.h \
    usrdata.h

DISTFILES += \
    NSA-eBike-HUD.files \
    NSA-eBike-HUD.includes
