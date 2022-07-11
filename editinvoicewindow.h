#ifndef EDITINVOICEWINDOW_H
#define EDITINVOICEWINDOW_H

#include <QWidget>
#include <QDateTime>
#include "chooseproductwindow.h"
#include "editproductwindow.h"
#include "deleteproductwindow.h"
#include "app.h"

namespace Ui {
class EditInvoiceWindow;
}

class EditInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditInvoiceWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~EditInvoiceWindow();
    void set_inv_id(std::string inv_id);
    void SHOW();

signals:
    void save();

private slots:
    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_save_btn_clicked();

    void added_show();

    void Show();

private:
    Ui::EditInvoiceWindow *ui;

    ChooseProductWindow *choose_pro_ptr;
    EditProductWindow *edit_pro_ptr;
    DeleteProductWindow *del_pro_ptr;
    App *CoreApp;
    std::string inv_id;
    ProductWithQuantity product;

    void display_data();
};

#endif // EDITINVOICEWINDOW_H
