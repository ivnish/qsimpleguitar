#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  void PlayAndCheckTimer(const QString pathToSound);

private:
  Ui::MainWindow *ui;

private slots:
  void on_pushButton_6_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_clicked();
  void on_checkBox_clicked();
  void PlaySound();
  void restartImg();
  void on_actionQuit_triggered();
  void on_actionAbout_triggered();
};

#endif // MAINWINDOW_H
