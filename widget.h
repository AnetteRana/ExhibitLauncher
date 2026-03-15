#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess> // to run other programz
#include <QTimer> // for input timer checking

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:

    // buttons:
    void on_pushButton_1_pressed();
    void on_pushButton_2_pressed();
    void on_pushButton_3_pressed();
    void on_pushButton_4_pressed();

private:
    Ui::Widget *ui;

    QProcess *myRunningGame = nullptr; // pointer to game process (only one at a time)

    // setting up to make a timer to go back to menu
    QTimer idleCheckTimer;
    int idleCheckInterval = 15000; // every 15 seconds
    uint64_t idleKillThreshhold = 2 * 60 * 1000; // 2 minutes

    // functions to control games
    void startGame(const QString &exePath);
    void stopGame();

    void genericButton(int); // idea is to put stuff here rather than the button funcs...
};
#endif // WIDGET_H
