#include "productdatabasewindow.h"
#include "ui_productdatabasewindow.h"

ProductDatabaseWindow::ProductDatabaseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductDatabaseWindow)
{
    ui->setupUi(this);

    this->setFixedSize(340, 450);

    add_new_pro_ptr = new AddNewProductWindow;
    edit_pro_ptr = new EditExstingProductWindow;
}

ProductDatabaseWindow::~ProductDatabaseWindow()
{
    delete ui;
}

void ProductDatabaseWindow::on_add_btn_clicked()
{
    add_new_pro_ptr->show();
}

void ProductDatabaseWindow::on_edit_btn_clicked()
{
    edit_pro_ptr->show();
}

void ProductDatabaseWindow::on_exit_btn_clicked()
{
    close();
}

