#-------------------------------------------------
#
# Project created by QtCreator 2019-07-03T10:10:09
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    choose.cpp \
        gamedialog.cpp \
    gameover.cpp \
    gameover_d.cpp \
    help.cpp \
        main.cpp \
        mainwindow.cpp \
        myitem.cpp \
        myscene.cpp \
    loc.cpp \
    myscene_sg.cpp \
    rank_ui.cpp \
    singledialog.cpp \
    shape.cpp \
    map.cpp \
    game.cpp \
    player.cpp \
    rank.cpp \
    block.cpp \
    predict.cpp

HEADERS += \
    choose.h \
        gamedialog.h \
    gameover.h \
    gameover_d.h \
    help.h \
        mainwindow.h \
        myitem.h \
        myscene.h \
    block.h \
    const.h \
    loc.h \
    myscene_sg.h \
    rank_ui.h \
    require.h \
    singledialog.h \
    rank.h \
    shape.h \
    map.h \
    player.h \
    game.h \
    predict.h

FORMS += \
        choose.ui \
        gamedialog.ui \
        gameover.ui \
        gameover_d.ui \
        help.ui \
        mainwindow.ui \
        rank_ui.ui \
        singledialog.ui

RC_ICONS = tetris.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    audio.qrc
