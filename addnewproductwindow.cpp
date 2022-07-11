#include "addnewproductwindow.h"
#include "ui_addnewproductwindow.h"

AddNewProductWindow::AddNewProductWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::AddNewProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(300, 150);
    this->CoreApp = CoreApp;
}

AddNewProductWindow::~AddNewProductWindow()
{
    delete ui;
}

void AddNewProductWindow::on_save_btn_clicked()
{
    string name = ui->name->text().toStdString();
    double price = ui->price->value();

    CoreApp->addNewProductToDb(name, price);
    ui->name->clear();
    ui->price->setValue(0);
    this->close();
    emit save();
}

void AddNewProductWindow::on_cancel_btn_clicked()
{
    ui->name->clear();
    ui->price->setValue(0);
    this->close();
    emit cancel();
}

