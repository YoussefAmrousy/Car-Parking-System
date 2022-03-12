#include "track.h"
#include "ui_track.h"
#include "mainwindow.h"
#include <QString>
#include <string>
#include <fstream>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <cmath>
using namespace std;

track::track(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::track)
{
    ui->setupUi(this);
    string username = returnUsername();
    QFile file(QString::fromStdString(username) + ".txt");
    QTextStream in(&file);
    QTextStream out(&file);
    file.open(QIODevice::ReadWrite);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();

}

track::~track()
{
    delete ui;
}

bool flag = false;
void track::on_pushButton_clicked()
{
    if (flag == false)
    {
        QString timeOutHours = ui->lineEdit->text();
        QString timeOutMins = ui->lineEdit_2->text();

        if (!timeOutHours.isEmpty() && !timeOutMins.isEmpty())
        {
            flag = true;
            int rate = 20;
            int timeInH, timeInM = returnTimeIn();
            int timeOutH = timeOutHours.toInt() / 100;
            int timeOutM = timeOutMins.toInt() / 100;
            int cost1 = abs((timeOutH-timeInH)*rate);
            int cost2 = abs((timeOutM-timeInM)*rate);
            int tcost = cost1+cost2;
            QMessageBox::information(this, "Cost", "Your cost is: " + QString::number(tcost));

            string username = returnUsername();
            QFile file(QString::fromStdString(username) + ".txt");
            file.remove();

            int slotNum = returnSlot();
            string timeOut = timeOutHours.toStdString() + ":" + timeOutMins.toStdString();
            string carname, plate, timeIn, paymentType = returnCarData();
            addToHistory(slotNum, carname, plate, timeIn, timeOut, tcost, paymentType);
        }
        else
        {
            QMessageBox::information(this, "Check Out", "Enter time Out.");
        }
    }
        else
        {
            hide();
    }
}

void track::on_pushButton_2_clicked()
{
    hide();
}
