#include "chooseinvoicewindow.h"
#include "ui_chooseinvoicewindow.h"

ChooseInvoiceWindow::ChooseInvoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChooseInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(355, 125);

    edit_inv_ptr = new EditInvoiceWindow;
}

ChooseInvoiceWindow::~ChooseInvoiceWindow()
{
    delete ui;
}

void ChooseInvoiceWindow::on_edit_btn_clicked()
{
    edit_inv_ptr->show();
}

void ChooseInvoiceWindow::on_del_btn_clicked()
{
    close();
}

void ChooseInvoiceWindow::on_cancel_btn_clicked()
{
    close();
}

