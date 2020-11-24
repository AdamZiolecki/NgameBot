#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QDebug>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void getColorPixel();
    ~MainWindow();

private slots:
    void on_upItemButton_clicked();

    void on_downItemButton_clicked();

    void on_deleteItemButton_clicked();

    void on_addMoveButton_clicked();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionClose_triggered();

    void on_donateButton_clicked();

    void on_actionWhat_is_going_on_triggered();

    void on_actionHow_to_use_it_triggered();

    void on_runButton_clicked();

    void itemEdit();

    void on_readKeysButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
