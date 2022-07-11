#include "chooseinvoicewindow.h"
#include "ui_chooseinvoicewindow.h"

ChooseInvoiceWindow::ChooseInvoiceWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::ChooseInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(355, 125);

    edit_inv_ptr = new EditInvoiceWindow(nullptr, CoreApp);
    connect(edit_inv_ptr,&EditInvoiceWindow::save,this,&ChooseInvoiceWindow::Show);

    this->CoreApp = CoreApp;
    for (auto inv : CoreApp->IDS_INVOICE)
        ui->comboBox->addItem(QString::fromStdString(inv));
}

ChooseInvoiceWindow::~ChooseInvoiceWindow()
{
    delete ui;
    delete edit_inv_ptr;
}

void ChooseInvoiceWindow::on_edit_btn_clicked()
{
    std::string inv_id = ui->comboBox->currentText().toStdString();
    edit_inv_ptr->set_inv_id(inv_id);
    edit_inv_ptr->SHOW();
    this->close();
}

void ChooseInvoiceWindow::on_del_btn_clicked()
{
    std::string id = ui->comboBox->currentText().toStdString();
    CoreApp->removeInvoice(id);
    ui->comboBox->clear();
    for (auto inv : CoreApp->IDS_INVOICE)
        ui->comboBox->addItem(QString::fromStdString(inv));
    this->close();
    emit del();
}

void ChooseInvoiceWindow::on_cancel_btn_clicked()
{
    this->close();
    emit cancel();
}

void ChooseInvoiceWindow::Show()
{
    ui->comboBox->clear();
    for (auto inv : CoreApp->IDS_INVOICE)
        ui->comboBox->addItem(QString::fromStdString(inv));

    this->show();
}

void ChooseInvoiceWindow::SHOW()
{
    this->Show();
}

