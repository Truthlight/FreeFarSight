#-------------------------------------------------
#
# Project created by QtCreator 2013-09-08T01:44:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WMT2
TEMPLATE = app

LIBS += -luser32

SOURCES += src/main.cpp\
    src/ffs_time.cpp \
    src/mainwidget.cpp \
    src/process.cpp \
    src/widgetchooseprocess.cpp \
    src/objectmanager.cpp \
    src/memory.cpp \
    src/player.cpp \
    src/commentator.cpp \
    src/camera.cpp \
    src/movie.cpp \
    src/render.cpp \
    src/widgettitlebar.cpp \
    src/widgetbutton.cpp \
    src/design.cpp \
    src/widgetmb.cpp \
    src/light.cpp \
    src/qlabelclickable.cpp \
    src/uitabgeneral.cpp \
    src/uitababout.cpp \
    src/uitabspectate.cpp \
    src/uitablight.cpp \
    src/slowmo.cpp \
    src/dbclightparams.cpp \
    src/widgettitlebar2.cpp \
    src/colorpicker.cpp \
    src/colorsquarish.cpp \
    src/widgetmbdialog.cpp \
    src/hotkeysthread.cpp \
    src/widgetmbdialog2.cpp \
    src/uihotkeys.cpp \
    src/screenshot.cpp

HEADERS  += mainwidget.h \
    src/ffs_time.h \
    src/process.h \
    src/widgetchooseprocess.h \
    src/objectmanager.h \
    src/memory.h \
    src/Offsets.h \
    src/player.h \
    src/commentator.h \
    src/camera.h \
    src/movie.h \
    src/render.h \
    src/widgettitlebar.h \
    src/widgetbutton.h \
    src/design.h \
    src/widgetmb.h \
    src/light.h \
    src/qlabelclickable.h \
    src/uitabgeneral.h \
    src/uitababout.h \
    src/uitabspectate.h \
    src/uitablight.h \
    src/slowmo.h \
    src/dbclightparams.h \
    src/qspinboxbis.h \
    src/widgettitlebar2.h \
    src/colorpicker.h \
    src/colorsquarish.h \
    src/qspinboxbis.h \
    src/widgetmbdialog.h \
    src/hotkeysthread.h \
    src/widgetmbdialog2.h \
    src/uihotkeys.h \
    src/screenshot.h

FORMS

DEFINES -= UNICODE DEFINES += _MBCS

RESOURCES += \
    Icones.qrc

RC_FILE = FreeFarSight.rc
