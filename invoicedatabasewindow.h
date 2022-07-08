#ifndef INVOICEDATABASEWINDOW_H
#define INVOICEDATABASEWINDOW_H

#include <QWidget>
#include "addinvoicewindow.h"
#include "editinvoicewindow.h"
#include "filterwindow.h"

namespace Ui {
class InvoiceDatabaseWindow;
}

class InvoiceDatabaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InvoiceDatabaseWindow(QWidget *parent = nullptr);
    ~InvoiceDatabaseWindow();

private slots:

    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_filter_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::InvoiceDatabaseWindow *ui;

    AddInvoiceWindow *add_inv_ptr;
    EditInvoiceWindow *edit_inv_ptr;
    FilterWindow *filter_ptr;
};

#endif // INVOICEDATABASEWINDOW_H
