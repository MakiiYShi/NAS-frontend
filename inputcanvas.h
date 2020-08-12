#ifndef INPUTCANVAS_H
#define INPUTCANVAS_H

#include <QDialog>

namespace Ui {
class InputCanvas;
}

class InputCanvas : public QDialog
{
    Q_OBJECT

public:
    explicit InputCanvas(QWidget *parent = nullptr);
    ~InputCanvas();
    void visualization();

private:
    Ui::InputCanvas *ui;
};

#endif // INPUTCANVAS_H
