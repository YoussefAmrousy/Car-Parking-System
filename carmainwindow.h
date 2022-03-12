#ifndef CARMAINWINDOW_H
#define CARMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class carMainWindow;
}

class carMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit carMainWindow(QWidget *parent = nullptr);
    ~carMainWindow();

private:
    Ui::carMainWindow *ui;
};

#endif // CARMAINWINDOW_H
