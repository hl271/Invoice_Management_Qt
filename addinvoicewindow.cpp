#include "addinvoicewindow.h"
#include "ui_addinvoicewindow.h"

AddInvoiceWindow::AddInvoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(520, 400);

    choose_pro_ptr = new ChooseProductWindow;
}

AddInvoiceWindow::~AddInvoiceWindow()
{
    delete ui;
}

void AddInvoiceWindow::on_add_btn_clicked()
{
    choose_pro_ptr->show();
}


void AddInvoiceWindow::on_save_btn_clicked()
{
    close();
}


void AddInvoiceWindow::on_cancel_btn_clicked()
{
    close();
}

