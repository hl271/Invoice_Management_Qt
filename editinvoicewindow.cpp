#include "editinvoicewindow.h"
#include "ui_editinvoicewindow.h"

EditInvoiceWindow::EditInvoiceWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(520, 440);

    choose_pro_ptr = new ChooseProductWindow;
    edit_pro_ptr = new EditProductWindow;
    del_pro_ptr = new DeleteProductWindow;
}

EditInvoiceWindow::~EditInvoiceWindow()
{
    delete ui;
}

void EditInvoiceWindow::on_add_btn_clicked()
{
    choose_pro_ptr->show();
}

void EditInvoiceWindow::on_edit_btn_clicked()
{
    edit_pro_ptr->show();
}


void EditInvoiceWindow::on_del_btn_clicked()
{
    del_pro_ptr->show();
}


void EditInvoiceWindow::on_save_btn_clicked()
{
    close();
}

