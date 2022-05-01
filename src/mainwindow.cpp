#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QMessageBox>
#include <QMediaPlayer>

QTimer *timer;               // Timer to repeat notes
QString pathToSound;         // Path to sound files for slot
extern QString szPathToRes;  // The path to resource directory
extern QString appVersion;   // Current app version
QMediaPlayer *player;        // Player. Use in Linux

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  // Output the guitar image. It is strange that Qt is used to display an image Label widget,
  // instead of Image widget, as in other toolkits. It's a little confusing
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara.png"));

  // Create a timer to repeat notes
  timer = new QTimer(this);
  // Connect the timer in the slot PlayGuitarSound
  connect(timer, SIGNAL(timeout()), this, SLOT(PlayGuitarSound()));

  // Create a player
  player = new QMediaPlayer;
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::PlayGuitarSound() {
  // choose a note
  player->setMedia(QUrl::fromLocalFile(pathToSound));
  player->play();
}

void MainWindow::restartImg() {
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara.png"));
}

void MainWindow::PlayAndCheckTimer(const QString pTS) {
  pathToSound = pTS;
  PlayGuitarSound();  // Play note

  // If checked "Repeat"
  if (ui->checkBox->isChecked()) {
    // Check whether the timer is running
    if (timer->isActive()) {
      timer->stop(); // and if so, stop it
    }
    // And then start again, because the user can change the time
    timer->start(ui->spinBox->value() * 1000);
  }
  // And if you repeat off
  else {
    // it is necessary to check whether the timer was not active
    if (timer->isActive()) {
      timer->stop();  // and turn it off
    }

    // Return the picture of the guitar without strings
    QTimer::singleShot(2000, this, SLOT(restartImg()));
  }
}

void MainWindow::on_pushButton_clicked() {
  // Play E
  PlayAndCheckTimer(szPathToRes + "/E1.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara6.png"));
}

void MainWindow::on_pushButton_2_clicked() {
  // Play H
  PlayAndCheckTimer(szPathToRes + "/H1.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara5.png"));
}

void MainWindow::on_pushButton_3_clicked() {
  // Play G
  PlayAndCheckTimer(szPathToRes + "/G1.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara4.png"));
}

void MainWindow::on_pushButton_4_clicked() {
  // Play D
  PlayAndCheckTimer(szPathToRes + "/D1.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara3.png"));
}

void MainWindow::on_pushButton_5_clicked() {
  // Play A
  PlayAndCheckTimer(szPathToRes + "/A1.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara2.png"));
}

void MainWindow::on_pushButton_6_clicked() {
  // Play E
  PlayAndCheckTimer(szPathToRes + "/E2.wav");
  ui->label_2->setPixmap(QPixmap(szPathToRes + "/gitara1.png"));
}

// Repeat checkbox click
void MainWindow::on_checkBox_clicked() {
  // if user uncheck Repeat checkbox
  if (!ui->checkBox->isChecked()) {
    // it is necessary to check whether the timer was not active
    if (timer->isActive()) {
      timer->stop();  // and turn it off
    }
    restartImg();  // Return the picture of the guitar without strings
  }
}

void MainWindow::on_actionQuit_triggered() {
  close();
}

void MainWindow::on_actionAbout_triggered() {
  QString szAbout;
  szAbout.append("<h2>QSimpleGuitar ");
  szAbout.append(appVersion);
  szAbout.append("</h2>");
  szAbout.append(tr("<p>Based on Qt "));
  szAbout.append(qVersion());
  szAbout.append("</p>");
  szAbout.append(tr("<p>Build on "));
  szAbout.append(__DATE__);
  szAbout.append(tr(" at "));
  szAbout.append(__TIME__);
  szAbout.append("<br></p>");
  szAbout.append(tr("<p>Copyright (c) Andrei Ivnitskii, 2011-2022. All rights reserved.</p>"));

  QMessageBox::about(this, tr("About QSimpleGuitar"), szAbout);
}
