#ifndef EDITINVOICEWINDOW_H
#define EDITINVOICEWINDOW_H

#include <QWidget>
#include "chooseproductwindow.h"
#include "editproductwindow.h"
#include "deleteproductwindow.h"

namespace Ui {
class EditInvoiceWindow;
}

class EditInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditInvoiceWindow(QWidget *parent = nullptr);
    ~EditInvoiceWindow();

private slots:
    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_save_btn_clicked();

private:
    Ui::EditInvoiceWindow *ui;

    ChooseProductWindow *choose_pro_ptr;
    EditProductWindow *edit_pro_ptr;
    DeleteProductWindow *del_pro_ptr;
};

#endif // EDITINVOICEWINDOW_H
