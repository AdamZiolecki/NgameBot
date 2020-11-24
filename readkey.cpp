#include "readkey.h"
#include "ui_readkey.h"
#include <QDebug>

ReadKey::ReadKey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReadKey)
{
    ui->setupUi(this);
}

ReadKey::~ReadKey()
{
    delete ui;
}

void ReadKey::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Z)
    {
        qDebug() << "Z";
    }
    if (event->key() == Qt::RightArrow)
    {
        qDebug() << "Right arrow";
    }
}

void ReadKey::keyReleaseEvent(QKeyEvent *event)
{

}
