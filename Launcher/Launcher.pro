#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T17:30:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Launcher
TEMPLATE = app
#选择库的位置
#LIBS += -L../widget -lwidget
LIBS += -L../UserInterface -lUserInterface

SOURCES += main.cpp\
    MainWidget/MainWidget.cpp


HEADERS  += \
    MainWidget/MainWidget.h

#unix:!mac:QMAKE_LFLAGS += -Wl,--rpath=your_path

RESOURCES += \
    Resource.qrc
