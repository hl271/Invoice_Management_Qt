#include "deleteproductwindow.h"
#include "ui_deleteproductwindow.h"

DeleteProductWindow::DeleteProductWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(400, 125);
}

DeleteProductWindow::~DeleteProductWindow()
{
    delete ui;
}

void DeleteProductWindow::on_delete_btn_clicked()
{
    close();
}


void DeleteProductWindow::on_cancel_btn_clicked()
{
    close();
}

