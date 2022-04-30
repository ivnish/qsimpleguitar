/***************************************************************
 * Name:      mainwindow.cpp
 * Author:    Andrey Ivnitsky (ivnitsky.a@gmail.com)
 * Created:   01.05.2011
 * Copyright: (c) Andrey Ivnitsky, 2011-2013
 * License:   GPLv3
 **************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#ifdef Q_OS_LINUX
#include <phonon/phonon>
#endif

/*****************************************************************************************/

QTimer *timer;						// Timer to repeat notes
QString pathToSound;                // Path to sound files for slot
extern QString szPathToRes;			// The path to res directory
#ifdef Q_OS_LINUX
Phonon::MediaObject *mediaObject;	// Player. Use in UNIX
#endif
/*****************************************************************************************/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Output the guitar image. It is strange that Qt is used to display an image Label widget,
    // instead of Image widget, as in other toolkits. It's a little confusing
	ui->label_2->setPixmap(QPixmap(szPathToRes+"/gitara.png"));

    // Create a timer to repeat notes
	timer = new QTimer(this);
    // Connect the timer in the slot PlaySound
    connect(timer, SIGNAL(timeout()), this, SLOT(PlaySound()));

    #ifdef Q_OS_LINUX
    // Create a player. Due to the fact that since there have cut Ubuntu 10.10
    // old audio subsystem, instead of QSound::play has to use
    // Phonon. In windows QSound::play works */
	mediaObject = Phonon::createPlayer(Phonon::NoCategory, Phonon::MediaSource(""));
	#endif
}
/*****************************************************************************************/

MainWindow::~MainWindow()
{
    delete ui;
}
/*****************************************************************************************/

void MainWindow::PlaySound()
{
    #ifdef Q_OS_LINUX
        // choose a note
        mediaObject->setCurrentSource(pathToSound);
        mediaObject->play();
    #elif defined Q_OS_WIN32
		QSound::play(pathToSound);
    #endif
}
/*****************************************************************************************/

void MainWindow::restartImg()
{
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara.png"));
}
/*****************************************************************************************/

void MainWindow::PlayAndCheckTimer(const QString pTS)
{
    pathToSound = pTS;
    PlaySound();		// Play note

    // If checked "Repeat"
	if (ui->checkBox->isChecked())
	{
        // Check whether the timer is running
		if (timer->isActive())
            timer->stop(); // and if so, stop it
        // And then start again, because the user can change the time
		timer->start(ui->spinBox->value()*1000);
	}
    else // And if you repeat off
    {
        if (timer->isActive())	// it is necessary to check whether the timer was not active
            timer->stop();		// and turn it off

        // Return the picture of the guitar without strings
        QTimer::singleShot(2000, this, SLOT(restartImg()));
    }
}
/*****************************************************************************************/

void MainWindow::on_pushButton_clicked()
{
    // Play E
	PlayAndCheckTimer(szPathToRes+"/E1.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara6.png"));
}
/*****************************************************************************************/

void MainWindow::on_pushButton_2_clicked()
{
    // Play H
	PlayAndCheckTimer(szPathToRes+"/H1.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara5.png"));
}
/*****************************************************************************************/

void MainWindow::on_pushButton_3_clicked()
{
    // Play G
	PlayAndCheckTimer(szPathToRes+"/G1.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara4.png"));
}
/*****************************************************************************************/

void MainWindow::on_pushButton_4_clicked()
{
    // Play D
	PlayAndCheckTimer(szPathToRes+"/D1.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara3.png"));
}
/*****************************************************************************************/

void MainWindow::on_pushButton_5_clicked()
{
    // Play A
	PlayAndCheckTimer(szPathToRes+"/A1.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara2.png"));
}
/*****************************************************************************************/

void MainWindow::on_pushButton_6_clicked()
{
    // Play E
	PlayAndCheckTimer(szPathToRes+"/E2.wav");
    ui->label_2->setPixmap( QPixmap(szPathToRes+"/gitara1.png"));
}
/*****************************************************************************************/

// Repeat checkbox click
void MainWindow::on_checkBox_clicked()
{
    // if user uncheck Repeat checkbox
    if ( ! ui->checkBox->isChecked())
    {
        if (timer->isActive())	// it is necessary to check whether the timer was not active
            timer->stop();		// and turn it off
        restartImg();           // Return the picture of the guitar without strings
    }
}
/*****************************************************************************************/

void MainWindow::on_actionQuit_triggered()
{
    close();
}
/*****************************************************************************************/

void MainWindow::on_actionAbout_triggered()
{
    QString szAbout;
    szAbout.append("<h2>QSimpleGuitar 0.2</h2>");
    szAbout.append(tr("<p>Based on Qt "));
    szAbout.append(qVersion());
    szAbout.append("</p>");
    szAbout.append(tr("<p>Build on "));
    szAbout.append(__DATE__);
    szAbout.append(tr(" at "));
    szAbout.append(__TIME__);
    szAbout.append("<br></p>");
    szAbout.append(tr("<p>Copyright (c) Andrey Ivnitsky, 2011-2013. All rights reserved.</p>"));

    QMessageBox::about(this, tr("About QSimpleGuitar 0.2"),szAbout);
}
/*****************************************************************************************/
