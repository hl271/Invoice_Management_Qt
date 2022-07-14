// GUI - Do Hoang Khoi
#ifndef PRODUCTDATABASEWINDOW_H
#define PRODUCTDATABASEWINDOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include "addnewproductwindow.h"
#include "editexstingproductwindow.h"
#include "deleteproductdbwindow.h"
#include "app.h"

namespace Ui {
class ProductDatabaseWindow;
}

class ProductDatabaseWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductDatabaseWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~ProductDatabaseWindow();

signals:
    void exit2menu();

private slots:

    void on_add_btn_clicked();

    void on_edit_btn_clicked();

    void on_exit_btn_clicked();

    void Show();

    void on_delete_2_clicked();

private:
    Ui::ProductDatabaseWindow *ui;

    AddNewProductWindow *add_new_pro_ptr;
    EditExstingProductWindow *edit_pro_ptr;
    DeleteProductDBWindow *del_pro_ptr;
    App *CoreApp;

    void display_data();
};

#endif // PRODUCTDATABASEWINDOW_H
