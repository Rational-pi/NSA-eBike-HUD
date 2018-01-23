INCLUDEPATH += $$PWD/ArduinoHeaders

SOURCES +=rotaryencoder.cpp \
    ui_base.cpp \
    usrdatausr_base.cpp \
    app.cpp \
    powermeter.cpp \
    tachometer.cpp \
    usrdata.cpp \
    main.cpp \
HEADERS +=rotaryencoder.h \
    ui_base.h \
    usrdatausr_base.h \
    app.h \
    powermeter.h \
    tachometer.h \
    usrdata.h

DISTFILES += \
    NSA-eBike-HUD.files \
    NSA-eBike-HUD.includes
