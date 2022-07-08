#include "addnewproductwindow.h"
#include "ui_addnewproductwindow.h"

AddNewProductWindow::AddNewProductWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddNewProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(300, 150);
}

AddNewProductWindow::~AddNewProductWindow()
{
    delete ui;
}

void AddNewProductWindow::on_save_btn_clicked()
{
    close();
}

void AddNewProductWindow::on_cancel_btn_clicked()
{
    close();
}

