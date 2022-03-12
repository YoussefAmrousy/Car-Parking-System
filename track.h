#ifndef TRACK_H
#define TRACK_H

#include <QDialog>
#include "car.h"
#include "project1.h"

namespace Ui {
class track;
}

class track : public QDialog
{
    Q_OBJECT

public:
    explicit track(QWidget *parent = nullptr);
    ~track();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::track *ui;
};

#endif // TRACK_H
