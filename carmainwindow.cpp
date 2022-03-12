#include "carmainwindow.h"
#include "ui_carmainwindow.h"

carMainWindow::carMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::carMainWindow)
{
    ui->setupUi(this);
}

carMainWindow::~carMainWindow()
{
    delete ui;
}
