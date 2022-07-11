#ifndef CHOOSEPRODUCTWINDOW_H
#define CHOOSEPRODUCTWINDOW_H

#include <QWidget>
#include "app.h"

namespace Ui {
class ChooseProductWindow;
}

class ChooseProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseProductWindow(ProductWithQuantity &pro_ptr, QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~ChooseProductWindow();
    void SHOW();

signals:
    void add();

private slots:
    void on_add_btn_clicked();

private:
    Ui::ChooseProductWindow *ui;
    App *CoreApp;
    ProductWithQuantity *pro_ptr;
};

#endif // CHOOSEPRODUCTWINDOW_H
