#include "inputcanvas.h"
#include "ui_inputcanvas.h"

#include <iostream>

using namespace std;


/**
 * Previous version of displaying picture.
 *
 */
void InputCanvas::visualization() {
    // Example: The best model looks like:
    // factor1 =~ y1 + y3 + y4 + y5
    // factor2 =~ x1 + x2 + x3
    // factor3 =~ y2 + y6 + y7 + y8
    // factor1 ~ factor3

    freopen("graph.dot","w",stdout);
    cout<<"digraph G{"<<endl;
    //cout<<"label=\"";
    //cout<<"DSEM";
    //cout<<"\";"<<endl;
    cout<<"rankdir=LR;"<<endl;
    cout<<"A [shape=box];"<<endl;
    cout<<"A->B->C;"<<endl;
    cout<<"D->B;"<<endl;
    cout<<"B->E [dir=both];"<<endl;
    cout<<"E->A [dir=foward];"<<endl;
    cout<<"}"<<endl;

    string s = "dot -Tpng graph.dot -o output.png";
    const char* cmd = s.data();
    system(cmd);
}

InputCanvas::InputCanvas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputCanvas)
{
    ui->setupUi(this);
    visualization();
    QPixmap pixmap("output.png");
    ui->label->setPixmap(pixmap.scaled(ui->label->size()));
    ui->label->resize(ui->label->pixmap()->size());
    ui->label->show();
}

InputCanvas::~InputCanvas()
{
    delete ui;
}
