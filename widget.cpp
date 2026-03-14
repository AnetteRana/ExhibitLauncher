#include "widget.h"

// these to run another .exe
#include <QCoreApplication>
#include <QDir>

#include "./ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->showFullScreen();

    // temp way to quit fullscreen. Should be removed before deployment
    QShortcut *quitShortcut = new QShortcut(QKeySequence("Ctrl+R"), this);
    connect(quitShortcut, &QShortcut::activated, this, &QWidget::close);
}

Widget::~Widget()
{
    delete ui;
}

// the not really a VR game
void Widget::on_pushButton_1_pressed()
{
    // make sure not to open multiple!
    if (myRunningGame) {
        qDebug() << "Game already running";
        return;
    }


    QString gamePath = "C:/Users/Rana/Documents/GitHub/ExhibitLauncher/Games/GjennfunnetFortid/EscapeAnno.exe";
    myRunningGame = new QProcess(this);

    // set to delete after closing. pointer ready to point again!
    connect(myRunningGame, &QProcess::finished,this,[this](int,QProcess::ExitStatus){
        qDebug() << "Game closed";
        myRunningGame->deleteLater();
        myRunningGame = nullptr;
    });

    // actually start game
    myRunningGame->start(gamePath);

    genericButton(1);
}

// Unmasked Hamar (soda collecting)
void Widget::on_pushButton_2_pressed()
{
    // make sure not to open multiple! (potential issue if game somehow ends up behind menu)
    if (myRunningGame) {
        qDebug() << "Game already running";
        return;
    }

    QString gamePath = "C:/Users/Rana/Documents/GitHub/ExhibitLauncher/Games/HamarUnmasked/UnmaskedHamar.exe";
    myRunningGame = new QProcess(this);

    // set to delete after closing. pointer ready to point again!
    connect(myRunningGame, &QProcess::finished,this,[this](int,QProcess::ExitStatus){
        qDebug() << "Game closed";
        myRunningGame->deleteLater();
        myRunningGame = nullptr;
    });


    // actually start game
    myRunningGame->start(gamePath);

    genericButton(2);
}

// Loom Game
void Widget::on_pushButton_3_pressed()
{
    // make sure not to open multiple! (potential issue if game somehow ends up behind menu)
    if (myRunningGame) {
        qDebug() << "Game already running";
        return;
    }

    QString gamePath = "C:/Users/Rana/Documents/GitHub/ExhibitLauncher/Games/LoomGame/LoomGame.exe";
    myRunningGame = new QProcess(this);

    // set to delete after closing. pointer ready to point again!
    connect(myRunningGame, &QProcess::finished,this,[this](int,QProcess::ExitStatus){
        qDebug() << "Game closed";
        myRunningGame->deleteLater();
        myRunningGame = nullptr;
    });


    // actually start game
    myRunningGame->start(gamePath);


    genericButton(3);
}

void Widget::on_pushButton_4_pressed()
{
    genericButton(4);
}

void Widget::genericButton(int myInt)
{
    qDebug() << "hello im button: " << myInt;
}

