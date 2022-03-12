#include "car.h"
#include "ui_car.h"
#include "mainwindow.h"

#include <QString>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <QFile>
#include <QTextStream>
#include <QIODevice>

using namespace std;
int timeInHoursInt, timeInMinsInt;
int takenSlots = 0;
int slotsNumInt;
string carInSlot[20]; // plates
bool carSlots[20]; // check if there is car in slot
QString carname, plate;
string timeIn, paymentType;

car::car(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::car)
{
    ui->setupUi(this);
    for (int i = 1; i<=20; i++)
        ui->comboBox->addItem(QString::number(i));
    string username = returnUsername();
    QString qusername = QString::fromStdString(username);
    ui->label->setText(qusername);
}

car::~car()
{
    delete ui;
}


void car::on_pushButton_3_clicked()
{
    carname = ui->lineEdit->text();
    plate = ui->lineEdit_2->text();
    QString timeInHours = ui->lineEdit_3->text();
    QString timeInMins = ui->lineEdit_4->text();
    QString slotsNum = ui->comboBox->currentText();
    slotsNumInt = slotsNum.toInt();
    timeInHoursInt = timeInHours.toInt();
    timeInMinsInt = timeInMins.toInt();
    timeIn = timeInHours.toStdString() + ":" + timeInMins.toStdString();

    for (int i = 1; i <= 20; i++)
    {
        if ((carInSlot[i] == plate.toStdString()) && !plate.isEmpty())
        {
            QMessageBox::warning(this, "Booking", "This car is already in the parking");
            break;
        }
    }
    if (!carname.isEmpty() && !plate.isEmpty() && !timeInHours.isEmpty() && !timeInMins.isEmpty() && (ui->radioButton->isChecked() || ui->radioButton_2->isChecked()))
    {
        if (carSlots[slotsNumInt] != true)
        {
            string username2 = returnUsername();
            QFile file(QString::fromStdString(username2) + ".txt");
            QTextStream in(&file);
            QTextStream out(&file);
            file.open(QIODevice::Append | QIODevice::ReadWrite | QIODevice::Truncate);
            out << slotsNumInt << "\n"
                    << plate << "\n"
                    << carname << "\n"
                    << timeInHours << ":" << timeInMins << "\n";
            carInSlot[slotsNumInt] = plate.toStdString();

            if (ui->radioButton->isChecked())
            {
                paymentType = "Cash";
                out << QString::fromStdString(paymentType) << "\n";
            }
            else if (ui->radioButton_2->isChecked())
            {
                paymentType = "Visa";
                out << QString::fromStdString(paymentType) << "\n";
            }

            QMessageBox::information(this, "Booking", "You car is now in the parking");
            takenSlots++;
        }
        else
            QMessageBox::warning(this, "Booking", "There is already a car in this slot");
    }
    else
        QMessageBox::warning(this, "Booking", "Please Enter all of the required data.");
}

void car::on_pushButton_2_clicked()
{
    hide();
}

void car::on_pushButton_4_clicked()
{
    hide();
    track track;
    track.setModal(true);
    track.exec();
}

int returnTimeIn()
{
    return timeInHoursInt, timeInMinsInt;
}

int returnTakenSlots()
{
    return takenSlots;
}

int returnSlot()
{
    return slotsNumInt;
}

string returnCarData()
{
    return carname.toStdString(), plate.toStdString(), timeIn, paymentType;
}
