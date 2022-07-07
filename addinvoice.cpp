#include "addinvoice.h"
#include "ui_addinvoice.h"

AddInvoice::AddInvoice(QWidget *parent, App *CoreApp) :
    QDialog(parent),
    ui(new Ui::AddInvoice)
{
    ui->setupUi(this);
    this->CoreApp = CoreApp;
}

AddInvoice::~AddInvoice()
{
    delete ui;
    delete ptrAddItem;
    resetElements();
}

void AddInvoice::Show()
{
    this->show();
}

void AddInvoice::on_add_item_btn_clicked()
{
    std::string sCode = ui->code_val->text().toStdString();
    std::string type = ui->comboBox->currentText().toStdString();
    std::string id;

    if (type == "Domestic Import")
        id = CoreApp->addNewInvoiceToDb("ID", sCode);

    if (type == "Domestic Export")
        id = CoreApp->addNewInvoiceToDb("OD", sCode);

    if (type == "Foreign Import")
        id = CoreApp->addNewInvoiceToDb("IF", sCode);

    if (type == "Foreign Export")
        id = CoreApp->addNewInvoiceToDb("OF", sCode);


    ptrAddItem = new addItem(this, this->CoreApp, id);

    ptrAddItem->Show();

    resetElements();
    close();
}

void AddInvoice::on_Cancel_btn_clicked()
{
    resetElements();
    close();
}

void AddInvoice::resetElements()
{
    ui->code_val->clear();
}



