QT += core gui widgets multimedia

TARGET = QSimpleGuitar
TEMPLATE = app

SOURCES += \
    src/mainwindow.cpp \
    src/main.cpp

HEADERS += \
    src/mainwindow.h

FORMS += \
    data/mainwindow.ui

OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = src
RCC_DIR = src

RESOURCES += \
    res.qrc

TRANSLATIONS += \
	po/ru_RU.ts

RC_FILE = QSimpleGuitar.rc

LIBS+=-L%QTDIR%/plugins/imageformats
