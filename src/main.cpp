#include <QtWidgets/QApplication>
#include <QTranslator>
#include <QLocale>
#include "mainwindow.h"

QString szPathToRes;         // Path to resource directory
QString appVersion = "0.3";  // Current app version

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setApplicationName("QSimpleGuitar");
  a.setApplicationVersion(appVersion);
  a.setWindowIcon(QIcon(":/data/gitara_icon_64.ico"));

  #ifdef Q_OS_LINUX
    // In UNIX path to res
    szPathToRes = "/usr/share/qsimpleguitar";
  #elif defined Q_OS_WIN32
    // In windows res are in "data" directory near binary
    szPathToRes = a.applicationDirPath() + "/data";
  #endif

  // Translate interface
  QTranslator translator;
  // Path to translate file
  #ifdef Q_OS_LINUX
    translator.load(QLocale::system().name(), szPathToRes);
  #elif defined Q_OS_WIN32
    translator.load("ru_RU", szPathToRes);
  #endif
  a.installTranslator(&translator);

  // Create main window
  MainWindow w;
  w.setWindowTitle("QSimpleGuitar " + appVersion);
  w.show();

  return a.exec();
}
