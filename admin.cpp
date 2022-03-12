#include "admin.h"
#include "ui_admin.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    int takenSlots = returnTakenSlots();
    int empty = 20-takenSlots;
    ui->label_5->setText(QString::number(empty));
}
admin::~admin()
{
    delete ui;
}

void admin::on_pushButton_3_clicked()
{
    QString carname = ui->lineEdit->text();
    QString plate = ui->lineEdit_2->text();
    QString slot = ui->lineEdit_3->text();
    int slotsNumInt = slot.toInt();
    if (slotsNumInt > 20 || !(int)slotsNumInt)
    {
        QMessageBox::information(this, "Admin", "There are only 20 slots in the parking");
        return;
    }

    QFile file("admin.txt");
    QTextStream in(&file);
    QTextStream out(&file);
    file.open(QIODevice::Append | QIODevice::ReadWrite | QIODevice::Truncate);
    out << slotsNumInt << "\n"
            << plate << "\n"
            << carname << "\n";
    QMessageBox::information(this, "Admin", "The car was added to the parking");
    int takenSlots = returnTakenSlots();
    int empty = 20-takenSlots;
    ui->label_5->setText(QString::number(empty));
}

void admin::on_pushButton_4_clicked()
{
     QFile file("admin.txt");
     file.remove();
}
