#include "chooseproductwindow.h"
#include "ui_chooseproductwindow.h"

ChooseProductWindow::ChooseProductWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(400, 150);
}

ChooseProductWindow::~ChooseProductWindow()
{
    delete ui;
}

void ChooseProductWindow::on_pushButton_clicked()
{
    close();
}

