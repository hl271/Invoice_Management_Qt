#include "chooseproductwindow.h"
#include "ui_chooseproductwindow.h"

ChooseProductWindow::ChooseProductWindow(ProductWithQuantity &pro_ptr, QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::ChooseProductWindow)
{
    ui->setupUi(this);
    this->pro_ptr = &pro_ptr;

    this->setFixedSize(400, 150);
    this->CoreApp = CoreApp;
}

ChooseProductWindow::~ChooseProductWindow()
{
    delete ui;
}

void ChooseProductWindow::on_add_btn_clicked()
{
    std::string id = ui->pro_name->currentText().toStdString();
    int quantity = ui->pro_quantity->text().toInt();
    double price = CoreApp->DB_PRODUCT[id].getUnitPrice();

    this->pro_ptr->product.setID(id);
    this->pro_ptr->product.setUnitPrice(price);
    this->pro_ptr->quantiy = quantity;

    this->close();
    emit add();
}

void ChooseProductWindow::SHOW()
{
    ui->pro_quantity->setValue(0);
    ui->pro_name->clear();
    for (auto pro : this->CoreApp->IDS_PRODUCT)
        ui->pro_name->addItem(QString::fromStdString(pro));
    this->show();
}
