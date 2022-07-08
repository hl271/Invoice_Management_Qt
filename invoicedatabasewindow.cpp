#include "invoicedatabasewindow.h"
#include "ui_invoicedatabasewindow.h"

InvoiceDatabaseWindow::InvoiceDatabaseWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InvoiceDatabaseWindow)
{
    ui->setupUi(this);

    this->setFixedSize(700, 515);

    add_inv_ptr = new AddInvoiceWindow;
    edit_inv_ptr = new EditInvoiceWindow;
    filter_ptr = new FilterWindow;
}

InvoiceDatabaseWindow::~InvoiceDatabaseWindow()
{
    delete ui;
}

void InvoiceDatabaseWindow::on_add_btn_clicked()
{
    add_inv_ptr->show();
}

void InvoiceDatabaseWindow::on_edit_btn_clicked()
{
    edit_inv_ptr->show();
}

void InvoiceDatabaseWindow::on_filter_btn_clicked()
{
    filter_ptr->show();
}

void InvoiceDatabaseWindow::on_exit_btn_clicked()
{
    close();
}

