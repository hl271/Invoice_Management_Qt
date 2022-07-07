#include "updateitem.h"
#include "ui_updateitem.h"

UpdateItem::UpdateItem(QWidget *parent, App *CoreApp) :
    QDialog(parent),
    ui(new Ui::UpdateItem)
{
    ui->setupUi(this);
    this->CoreApp = CoreApp;
}

UpdateItem::~UpdateItem()
{
    delete ui;

    resetElements();
}

void UpdateItem::Show()
{
    this->show();
}

void UpdateItem::on_UPDATE_btn_clicked()
{
    std::string sCode = ui->code_val->text().toStdString();
    std::string sName = ui->name_val->text().toStdString();
    std::string sID = ui->ID_val->text().toStdString();
    int sQuantity = ui->quantity_val->text().toInt();

    CoreApp->editProductInInvoice(sCode, sID, sQuantity);

    close();
}

void UpdateItem::resetElements()
{
    ui->code_val->clear();
    ui->ID_val->clear();
    ui->name_val->clear();
    ui->price_val->clear();
    ui->quantity_val->clear();
}
