#include "widget.h"
#include "./ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    this->showFullScreen();

    // temp way to quit fullscreen. Should be removed before deployment
    QShortcut *quitShortcut = new QShortcut(QKeySequence("Ctrl+Q"), this);
    connect(quitShortcut, &QShortcut::activated, this, &QWidget::close);
}

Widget::~Widget()
{
    delete ui;
}
