#-------------------------------------------------
#
# Project created by QtCreator 2011-05-01T11:34:36
#
#-------------------------------------------------

QT       += core gui

TARGET = src/QSimpleGuitar-win
TEMPLATE = app

SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp

HEADERS  += \
    src/mainwindow.h

FORMS    += \
    data/mainwindow.ui

OBJECTS_DIR = src
MOC_DIR = src
UI_DIR = src
RCC_DIR = src

RESOURCES += \
    res.qrc

TRANSLATIONS += \
	po/ru_RU.ts

RC_FILE = QSimpleGuitar.rc

LIBS+=-L%QTDIR%/plugins/imageformats

QTPLUGIN = qico
