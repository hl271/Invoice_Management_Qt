#include "addinvoicewindow.h"
#include "ui_addinvoicewindow.h"

AddInvoiceWindow::AddInvoiceWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::AddInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(520, 410);
    this->CoreApp = CoreApp;

    choose_pro_ptr = new ChooseProductWindow(this->product, nullptr, CoreApp);
    connect(choose_pro_ptr,&ChooseProductWindow::add,this,&AddInvoiceWindow::Show);

    display_data();
}

AddInvoiceWindow::~AddInvoiceWindow()
{
    delete ui;
    delete choose_pro_ptr;
}

void AddInvoiceWindow::on_add_btn_clicked()
{
    choose_pro_ptr->SHOW();
    this->close();
}

void AddInvoiceWindow::on_save_btn_clicked()
{
    std::string type = ui->inv_type->currentText().toStdString();
    if (type == "Domestic Import")
        type = "ID";
    if (type == "Foreign Import")
        type = "IF";
    if (type == "Domestic Export")
        type = "OD";
    if (type == "Foreign Export")
        type = "OF";
    std::string inv_id = CoreApp->addNewInvoiceToDb(type);
    for (auto pro : this->products)
        CoreApp->addProductToInvoice(inv_id, pro.product.getID(), pro.quantiy);
    QString format = "yyyy/MM/dd HH:mm";
    QDateTime current_time = QDateTime::currentDateTime();
    std::string time = current_time.toString(format).toStdString();
    CoreApp->DB_INVOICE[inv_id]->setTime(time);
    this->products.clear();
    this->close();
    emit save();
}

void AddInvoiceWindow::on_cancel_btn_clicked()
{
    this->products.clear();
    this->close();
    emit cancel();
}

void AddInvoiceWindow::Show()
{
    this->products.push_back(this->product);
    display_data();
    this->show();
}

void AddInvoiceWindow::display_data()
{
    ui->data->setRowCount(0);

    ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem("name"));
    ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem("Unit Price"));
    ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem("Quantity"));
    ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem("Price"));

    for(auto pro : this->products)
    {
        QString name = QString::fromStdString(pro.product.getID());
        QString unit_price = QString::number(pro.product.getUnitPrice());
        QString quantity = QString::number(pro.quantiy);
        QString price = QString::number(pro.quantiy * pro.product.getUnitPrice());

        ui->data->insertRow(ui->data->rowCount());
        ui->data->setItem(ui->data->rowCount() - 1, 0, new QTableWidgetItem(name));
        ui->data->setItem(ui->data->rowCount() - 1, 1, new QTableWidgetItem(unit_price));
        ui->data->setItem(ui->data->rowCount() - 1, 2, new QTableWidgetItem(quantity));
        ui->data->setItem(ui->data->rowCount() - 1, 3, new QTableWidgetItem(price));
    }
}

void AddInvoiceWindow::SHOW()
{
    this->show();
    display_data();
}

