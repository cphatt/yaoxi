#-------------------------------------------------
#
# Project created by QtCreator 2017-12-19T17:27:36
#
#-------------------------------------------------

QT       -= gui

TARGET = widget
TEMPLATE = lib
CONFIG += staticlib
DEFINES += WIDGET_LIBRARY
#DESTDIR += ../bin
SOURCES += widget.cpp \
    customlabel.cpp

HEADERS += widget.h\
        widget_global.h \
    customlabel.h

target.path = /usr/lib
INSTALLS += target

#unix:!mac:QMAKE_LFLAGS += -Wl,--rpath=your_path
