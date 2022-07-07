#include "additem.h"
#include "ui_additem.h"

addItem::addItem(QWidget *parent, App *CoreApp, std::string id) :
    QDialog(parent),
    ui(new Ui::addItem)
{
    ui->setupUi(this);
    this->CoreApp = CoreApp;
    this->id = id;
}

addItem::~addItem()
{
    delete ui;
    resetElements();
}

void addItem::Show()
{
    this->show();
}

void addItem::on_ADD_btn_clicked()
{
    ui->label->setText("");
    std::string sID = ui->ID_val->text().toStdString();
    std::string sName = ui->name_val->text().toStdString();
    double sPrice = ui->price_val->text().toDouble();
    int sQuantity = ui->quantity_val->text().toInt();

    CoreApp->addNewProductToDb(sID, sName, sPrice);
    CoreApp->addProductToInvoice(this->id, sID, sQuantity);

    ui->label->setText("Success");

    resetElements();
    close();
}

void addItem::resetElements()
{
    ui->ID_val->clear();
    ui->name_val->clear();
    ui->price_val->clear();
    ui->quantity_val->clear();
}
