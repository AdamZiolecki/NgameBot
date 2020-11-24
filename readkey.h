#ifndef READKEY_H
#define READKEY_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class ReadKey;
}

class ReadKey : public QWidget
{
    Q_OBJECT

public:
    explicit ReadKey(QWidget *parent = 0);
    ~ReadKey();

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::ReadKey *ui;
};

#endif // READKEY_H
