#ifndef CAR_H
#define CAR_H
#include "track.h"
#include <QDialog>
#include <string>
#include <iostream>
using namespace std;

namespace Ui {
class car;
}

class car : public QDialog
{
    Q_OBJECT

public:
    explicit car(QWidget *parent = nullptr);
    ~car();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_pushButton_4_clicked();

private:
    Ui::car *ui;
};

int returnTimeIn();
int returnTakenSlots();
int returnSlot();
string returnCarData();

#endif // CAR_H
