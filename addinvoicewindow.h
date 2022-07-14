// GUI - Do Hoang Khoi
#ifndef ADDINVOICEWINDOW_H
#define ADDINVOICEWINDOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDateTime>
#include "chooseproductwindow.h"
#include "app.h"

namespace Ui {
class AddInvoiceWindow;
}

class AddInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddInvoiceWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~AddInvoiceWindow();
    void SHOW();

signals:
    void save();
    void cancel();

private slots:
    void Show();

    void on_add_btn_clicked();

    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::AddInvoiceWindow *ui;

    ChooseProductWindow *choose_pro_ptr;
    App *CoreApp;
    ProductWithQuantity product;
    std::vector<ProductWithQuantity> products;

    void display_data();
};

#endif // ADDINVOICEWINDOW_H
