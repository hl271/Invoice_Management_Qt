#ifndef CHOOSEINVOICEWINDOW_H
#define CHOOSEINVOICEWINDOW_H

#include <QWidget>
#include "editinvoicewindow.h"

namespace Ui {
class ChooseInvoiceWindow;
}

class ChooseInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseInvoiceWindow(QWidget *parent = nullptr);
    ~ChooseInvoiceWindow();

private slots:
    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::ChooseInvoiceWindow *ui;

    EditInvoiceWindow *edit_inv_ptr;
};

#endif // CHOOSEINVOICEWINDOW_H
