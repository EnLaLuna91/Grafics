#-------------------------------------------------
#
# Project created by QtCreator 2012-02-07T16:04:09
#
#-------------------------------------------------

QT       += core gui opengl
QT       += widgets

TARGET = practica1
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    Common.cpp \
    llumdireccional.cpp \
    objecte.cpp \
    cara.cpp \
    llumspotlight.cpp \
    readfile.cpp \
    llum.cpp \
    material.cpp \
    mon.cpp \
    llumpuntual.cpp

HEADERS  += mainwindow.h \
    vec.h \
    mat.h \
    glwidget.h \
    Common.h \
    llumdireccional.h \
    llumspotlight.h \
    objecte.h \
    cara.h \
    readfile.h \
    plabase.h \
    llum.h \
    material.h \
    mon.h \
    llumpuntual.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += resources.qrc

DISTFILES +=
