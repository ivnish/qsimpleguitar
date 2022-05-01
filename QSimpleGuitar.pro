QT += core gui widgets multimedia

TARGET = qsimpleguitar
TEMPLATE = app

SOURCES += \
  src/mainwindow.cpp \
  src/main.cpp

HEADERS += src/mainwindow.h

FORMS += data/mainwindow.ui

OBJECTS_DIR = build
MOC_DIR = build
UI_DIR = src
RCC_DIR = src

RESOURCES += res.qrc

TRANSLATIONS += po/ru_RU.ts

share.path = /usr/share/qsimpleguitar
share.files += \
  data/*.wav \
  data/*.png \
  data/gitara_icon_64.ico \
  po/*.qm

mainmenu.path = /usr/share/applications
mainmenu.files = data/*.desktop

target.path = /usr/bin

INSTALLS += target share mainmenu
