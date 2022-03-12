#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <fstream>
#include <QMessageBox>
using namespace std;

string loginFile = "login.txt";
string user;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
    ifstream inFile;
    inFile.open(loginFile);
    ofstream outFile;
    string un, pw;
    bool flag = false;

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    while (!inFile.eof())
    {
        getline(inFile, un);
        getline(inFile, pw);

        if (un ==username.toStdString() && pw == password.toStdString())
        {
            if (username.toStdString() == "admin" && password.toStdString() == "admin")
            {
                hide();
                QMessageBox::information(this, "Log In","Welcome, " + username);
                admin admin;
                admin.setModal(true);
                admin.exec();
                flag = true;
                break;
            }
            this->hide();
            QMessageBox::information(this, "Log In","Welcome, " + username);
            user = username.toStdString();
            car car;
            car.setModal(true);
            car.exec();
            flag = true;
            break;
        }
    }

    if (flag != true)
    {
        QMessageBox::information(this, "Log In", "Incorrect username or password");
    }
    inFile.close();
}

void MainWindow::on_pushButton_register_clicked()
{
    ofstream outFile;
    ifstream inFile;
    inFile.open(loginFile);
    outFile.open(loginFile, ios::app);

    string storedUsername, storedPassword;

    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    while (!inFile.eof())
    {
        getline(inFile, storedUsername);
        getline(inFile, storedPassword);

        if (storedUsername == username.toStdString())
        {
            QMessageBox::information(this, "Registartion", "This account already exists!");
            break;
        }
        else
        {
            outFile << username.toStdString() << "\n" << password.toStdString() << "\n";
            QMessageBox::information(this, "Registration","Registered Successfully!");
            break;
        }
    }
    outFile.close();
    inFile.close();
}

string returnUsername()
{
    return user;
}
