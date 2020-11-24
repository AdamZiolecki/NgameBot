#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mykeypress.h"
#include "readkey.h"
#include <QFileDialog>
#include <QThread>
#include <QRgb>
#include <QPixmap>
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("N++ Cheat");

    ui->treeWidget->editTriggers();
    ui->treeWidget->setColumnWidth(0, 130);
    ui->treeWidget->setColumnWidth(1, 130);
    ui->treeWidget->setColumnWidth(2, 130);
    ui->treeWidget->setColumnWidth(3, 130);
    connect(ui->treeWidget, SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)), this, SLOT(itemEdit()));
}

void MainWindow::getColorPixel()
{
    /*QScreen *screen;
    QPixmap pixmap = screen->grabWindow(QApplication::desktop()->winId(), 0, 0, 100, 100);
    QRgb pixelValue = pixmap.toImage().pixel(30,30);
    //qDebug() << pixelValue;*/

    /*qDebug() << QApplication::activeWindow();
    QApplication::setActiveWindow(QApplication::desktop());
    QWidget::setFocus();*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_upItemButton_clicked()
{
    if(ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem()) != 0)
    {
        QTreeWidgetItem *newItem = new QTreeWidgetItem();
        newItem->setText(0, ui->treeWidget->itemAbove(ui->treeWidget->currentItem())->text(0));
        newItem->setText(1, ui->treeWidget->itemAbove(ui->treeWidget->currentItem())->text(1));
        newItem->setText(2, ui->treeWidget->itemAbove(ui->treeWidget->currentItem())->text(2));

        ui->treeWidget->insertTopLevelItem(ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem())+1, newItem);
        delete ui->treeWidget->itemAbove(ui->treeWidget->currentItem());
    }
}

void MainWindow::on_downItemButton_clicked()
{
    if (ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem()) != (ui->treeWidget->topLevelItemCount()-1))
    {
        QTreeWidgetItem *newItem = new QTreeWidgetItem();
        newItem->setText(0, ui->treeWidget->itemBelow(ui->treeWidget->currentItem())->text(0));
        newItem->setText(1, ui->treeWidget->itemBelow(ui->treeWidget->currentItem())->text(1));
        newItem->setText(2, ui->treeWidget->itemBelow(ui->treeWidget->currentItem())->text(2));

        delete ui->treeWidget->itemBelow(ui->treeWidget->currentItem());
        ui->treeWidget->insertTopLevelItem(ui->treeWidget->indexOfTopLevelItem(ui->treeWidget->currentItem()), newItem);
    }
}

void MainWindow::on_deleteItemButton_clicked()
{
    delete ui->treeWidget->currentItem();
}

void MainWindow::itemEdit()
{
    if (ui->treeWidget->currentColumn() == 1 || ui->treeWidget->currentColumn() == 3 || ui->treeWidget->currentItem()->text(2) == "-")
    {
        ui->treeWidget->currentItem()->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    }
    else
    {
        ui->treeWidget->currentItem()->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    }
}

void MainWindow::on_addMoveButton_clicked()
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem();

    switch(ui->comboBox->currentIndex())
    {
    case 0:
        newItem->setText(0, "Jump");
        newItem->setText(1, "Jump");
        newItem->setText(2, "1");
        newItem->setText(3, "");
        break;
    case 1:
        newItem->setText(0, "Move right");
        newItem->setText(1, "Move right");
        newItem->setText(2, "1");
        break;
    case 2:
        newItem->setText(0, "Move left");
        newItem->setText(1, "Move left");
        newItem->setText(2, "1");
        break;
    case 3:
        newItem->setText(0, "Move right and jump");
        newItem->setText(1, "Move right and jump");
        newItem->setText(2, "1");
        break;
    case 4:
        newItem->setText(0, "Move left and jump");
        newItem->setText(1, "Move left and jump");
        newItem->setText(2, "1");
        break;
    case 5:
        newItem->setText(0, "Stay");
        newItem->setText(1, "Stay");
        newItem->setText(2, "1");
        break;
    case 6:
        newItem->setText(0, "Suicide");
        newItem->setText(1, "Suicide");
        newItem->setText(2, "-");
    }

    ui->treeWidget->addTopLevelItem(newItem);
}

void MainWindow::on_actionNew_triggered()
{
    ui->treeWidget->clear();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text files (*.txt)"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug() << "Error";
        }

        ui->treeWidget->clear();

        QTextStream in(&file);
        QStringList list2;
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList list;
            list = line.split(";");
            list2.append(list);

        }
        file.close();

        int i = 0;
        while(i < list2.size())
        {
            QTreeWidgetItem *newItem = new QTreeWidgetItem();
            newItem->setText(0, list2.at(i));
            newItem->setText(1, list2.at(i+1));
            newItem->setText(2, list2.at(i+2));
            ui->treeWidget->addTopLevelItem(newItem);
            i += 3;
        }
    }

}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text files (*.txt)"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append | QIODevice::Truncate))
        {
            qDebug() << "Error 0";
        }
        QTextStream out(&file);
        int i = 0;
        while (i < ui->treeWidget->topLevelItemCount())
        {
            out << ui->treeWidget->topLevelItem(i)->text(0);
            out << ";";
            out << ui->treeWidget->topLevelItem(i)->text(1);
            out << ";";
            out << ui->treeWidget->topLevelItem(i)->text(2);
            out << "\n";
            ++i;
        }
        file.close();
    }
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_donateButton_clicked()
{
    QWidget *window = new QWidget(this, Qt::Window);
    window->setFixedSize(200, 120);
    window->setWindowTitle("Joke!");
    QHBoxLayout *layout = new QHBoxLayout(window);
    QLabel *label = new QLabel;
    layout->addWidget(label);
    label->setText("It's joke");
    label->setAlignment(Qt::AlignCenter);
    QFont font("Arial", 16);
    label->setFont(font);
    window->show();

}

void MainWindow::on_actionWhat_is_going_on_triggered()
{
    QWidget *window = new QWidget(this, Qt::Window);
    window->setFixedSize(200, 120);
    window->setWindowTitle("Help");
    QHBoxLayout *layout = new QHBoxLayout(window);
    QLabel *label = new QLabel;
    layout->addWidget(label);
    label->setText("Never mind, I didn't have time\nto write this.");
    label->setAlignment(Qt::AlignLeft);
    QFont font("MS Shell Dlg 2", 9);
    label->setFont(font);
    window->show();
}

void MainWindow::on_actionHow_to_use_it_triggered()
{
    QWidget *window = new QWidget(this, Qt::Window);
    window->setFixedSize(200, 120);
    window->setWindowTitle("Help");
    QHBoxLayout *layout = new QHBoxLayout(window);
    QLabel *label = new QLabel;
    layout->addWidget(label);
    label->setText("Try it yourself!\n It's simple!");
    label->setAlignment(Qt::AlignCenter);
    QFont font("MS Shell Dlg 2", 12);
    label->setFont(font);
    window->show();
}

void MainWindow::on_runButton_clicked()
{
    MyKeyPress keyP;
    keyP.stay(ui->spinBox->value());
    keyP.up(1);

    for (int i = 0; i < ui->treeWidget->topLevelItemCount(); i++)
    {
        if (ui->treeWidget->topLevelItem(i)->text(1) == "Jump")
        {
            keyP.up(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Move left")
        {
            keyP.left(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Move right")
        {
            keyP.right(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Move left and jump")
        {
            keyP.leftUp(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Move right and jump")
        {
            keyP.rightUp(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Stay")
        {
            keyP.stay(ui->treeWidget->topLevelItem(i)->text(2).toInt());
        }
        else if (ui->treeWidget->topLevelItem(i)->text(1) == "Suicide")
        {
            keyP.suicide();
        }
    }
}

void MainWindow::on_readKeysButton_clicked()
{
    ReadKey *readKey = new ReadKey;
    readKey->show();
}
