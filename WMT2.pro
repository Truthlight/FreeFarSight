#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T01:44:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WMT2
TEMPLATE = app


SOURCES += main.cpp\
    mainwidget.cpp \
    process.cpp \
    widgetchooseprocess.cpp \
    objectmanager.cpp \
    memory.cpp \
    player.cpp \
    commentator.cpp \
    camera.cpp \
    movie.cpp \
    render.cpp \
    time.cpp \
    widgettitlebar.cpp \
    widgetbutton.cpp \
    design.cpp \
    widgetmb.cpp \
    light.cpp \
    qlabelclickable.cpp \
    uitabgeneral.cpp \
    uitababout.cpp \
    uitabspectate.cpp \
    uitablight.cpp \
    slowmo.cpp \
    dbclightparams.cpp \
    widgettitlebar2.cpp \
    colorpicker.cpp \
    colorsquarish.cpp \
    widgetmbdialog.cpp \
    hotkeysthread.cpp \
    widgetmbdialog2.cpp \
    uihotkeys.cpp \
    screenshot.cpp

HEADERS  += mainwidget.h \
    process.h \
    widgetchooseprocess.h \
    objectmanager.h \
    memory.h \
    Offsets.h \
    player.h \
    commentator.h \
    camera.h \
    movie.h \
    render.h \
    time.h \
    widgettitlebar.h \
    widgetbutton.h \
    design.h \
    widgetmb.h \
    light.h \
    qlabelclickable.h \
    uitabgeneral.h \
    uitababout.h \
    uitabspectate.h \
    uitablight.h \
    slowmo.h \
    dbclightparams.h \
    qspinboxbis.h \
    widgettitlebar2.h \
    colorpicker.h \
    colorsquarish.h \
    qspinboxbis.h \
    widgetmbdialog.h \
    hotkeysthread.h \
    widgetmbdialog2.h \
    uihotkeys.h \
    screenshot.h

FORMS

DEFINES -= UNICODE DEFINES += _MBCS

RESOURCES += \
    Icones.qrc

RC_FILE = FreeFarSight.rc
