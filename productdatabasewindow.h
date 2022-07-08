#ifndef PRODUCTDATABASEWINDOW_H
#define PRODUCTDATABASEWINDOW_H

#include <QWidget>
#include "addnewproductwindow.h"
#include "editexstingproductwindow.h"

namespace Ui {
class ProductDatabaseWindow;
}

class ProductDatabaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductDatabaseWindow(QWidget *parent = nullptr);
    ~ProductDatabaseWindow();

private slots:

    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::ProductDatabaseWindow *ui;

    AddNewProductWindow *add_new_pro_ptr;
    EditExstingProductWindow *edit_pro_ptr;
};

#endif // PRODUCTDATABASEWINDOW_H
