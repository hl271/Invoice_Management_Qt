#include "editproductwindow.h"
#include "ui_editproductwindow.h"

EditProductWindow::EditProductWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditProductWindow)
{
    ui->setupUi(this);
    this->setFixedSize(360, 175);
}

EditProductWindow::~EditProductWindow()
{
    delete ui;
}

void EditProductWindow::on_save_btn_clicked()
{
    close();
}


void EditProductWindow::on_cancel_btn_clicked()
{
    close();
}

