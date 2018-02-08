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
    usrdata.h \
    src/1602-AAF/inputlistener.h \
    src/1602-AAF/rotaryencoder.h \
    src/1602-AAF/ui_base.h \
    src/1602-AAF/ui_menu_base.h \
    src/1602-AAF/ui_usriotester.h \
    src/1602-AAF/vector.h \
    src/1602-AAF/ui_valueeditor.h

DISTFILES += \
    NSA-eBike-HUD.files \
    NSA-eBike-HUD.includes \
    NSA-eBike-HUD.ino
