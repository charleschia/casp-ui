#-------------------------------------------------
#
# Project created by QtCreator 2016-12-23T09:07:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CASP-UI
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    modparas.cpp \
    settings.cpp \
    bondcons.cpp

HEADERS  += dialog.h \
    modparas.h \
    settings.h \
    bondcons.h

FORMS += \
    modparas.ui \
    settings.ui \
    bondcons.ui

RESOURCES += \
    CASP.qrc

OTHER_FILES += \
    images/update.png \
    images/query.png \
    images/config.png
