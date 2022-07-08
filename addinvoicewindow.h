#ifndef ADDINVOICEWINDOW_H
#define ADDINVOICEWINDOW_H

#include <QWidget>
#include "chooseproductwindow.h"

namespace Ui {
class AddInvoiceWindow;
}

class AddInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddInvoiceWindow(QWidget *parent = nullptr);
    ~AddInvoiceWindow();

private slots:
    void on_add_btn_clicked();

    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::AddInvoiceWindow *ui;

    ChooseProductWindow *choose_pro_ptr;
};

#endif // ADDINVOICEWINDOW_H
