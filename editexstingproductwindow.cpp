#include "editexstingproductwindow.h"
#include "ui_editexstingproductwindow.h"

EditExstingProductWindow::EditExstingProductWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditExstingProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(350, 170);
}

EditExstingProductWindow::~EditExstingProductWindow()
{
    delete ui;
}

void EditExstingProductWindow::on_save_btn_clicked()
{
    close();
}

void EditExstingProductWindow::on_cancel_btn_clicked()
{
    close();
}

