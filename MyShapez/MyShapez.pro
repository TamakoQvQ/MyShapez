QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    belt.cpp \
    belt_turn.cpp \
    bluemineral.cpp \
    building.cpp \
    buildingcards.cpp \
    cutter.cpp \
    deliverycenter.cpp \
    gamewindow.cpp \
    goods.cpp \
    main.cpp \
    map.cpp \
    miner.cpp \
    mineral.cpp \
    redmineral.cpp \
    rotater.cpp \
    selectbox.cpp \
    shop.cpp \
    startwindow.cpp \
    trash.cpp

HEADERS += \
    belt.h \
    belt_turn.h \
    bluemineral.h \
    building.h \
    buildingcards.h \
    cutter.h \
    deliverycenter.h \
    gamewindow.h \
    goods.h \
    map.h \
    miner.h \
    mineral.h \
    redmineral.h \
    rotater.h \
    selectbox.h \
    shop.h \
    startwindow.h \
    trash.h

FORMS += \
    shop.ui \
    startwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Picture.qrc
