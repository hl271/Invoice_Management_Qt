#ifndef CHOOSEPRODUCTWINDOW_H
#define CHOOSEPRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class ChooseProductWindow;
}

class ChooseProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseProductWindow(QWidget *parent = nullptr);
    ~ChooseProductWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ChooseProductWindow *ui;
};

#endif // CHOOSEPRODUCTWINDOW_H
