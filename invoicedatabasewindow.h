#ifndef INVOICEDATABASEWINDOW_H
#define INVOICEDATABASEWINDOW_H

#include <QWidget>
#include <QList>
#include <sstream>
#include "addinvoicewindow.h"
#include "chooseinvoicewindow.h"
#include "filterwindow.h"
#include "app.h"

namespace Ui {
class InvoiceDatabaseWindow;
}

class InvoiceDatabaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceDatabaseWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~InvoiceDatabaseWindow();
    void SHOW();

signals:
    void exit2menu();

private slots:

    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_filter_btn_clicked();

    void on_exit_btn_clicked();

    void Show();

private:
    Ui::InvoiceDatabaseWindow *ui;

    AddInvoiceWindow *add_inv_ptr;
    ChooseInvoiceWindow *edit_inv_ptr;
    FilterWindow *filter_ptr;
    App *CoreApp;

    void display_data();
};

#endif // INVOICEDATABASEWINDOW_H
