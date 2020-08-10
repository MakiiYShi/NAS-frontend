#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;


/**
 * @brief visualization
 *
 */
void visualization() {
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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    visualization();
    QPixmap pixmap("output.png");
    ui->label->setPixmap(pixmap.scaled(ui->label->size()));
    ui->label->resize(ui->label->pixmap()->size());
    ui->label->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
}
