// GUI - Pham Quang Huy
#include "editinvoicewindow.h"
#include "ui_editinvoicewindow.h"

EditInvoiceWindow::EditInvoiceWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::EditInvoiceWindow)
{
    ui->setupUi(this);

    this->setFixedSize(520, 440);
    this->CoreApp = CoreApp;

    choose_pro_ptr = new ChooseProductWindow(this->product, nullptr, CoreApp);
    edit_pro_ptr = new EditProductWindow(nullptr, CoreApp);
    del_pro_ptr = new DeleteProductWindow(nullptr, CoreApp);
    connect(choose_pro_ptr,&ChooseProductWindow::add,this,&EditInvoiceWindow::added_show);
    connect(edit_pro_ptr,&EditProductWindow::cancel,this,&EditInvoiceWindow::Show);
    connect(edit_pro_ptr,&EditProductWindow::save,this,&EditInvoiceWindow::Show);
    connect(del_pro_ptr,&DeleteProductWindow::cancel,this,&EditInvoiceWindow::Show);
    connect(del_pro_ptr,&DeleteProductWindow::del,this,&EditInvoiceWindow::Show);
}

EditInvoiceWindow::~EditInvoiceWindow()
{
    delete ui;
    delete choose_pro_ptr;
    delete edit_pro_ptr;
    delete del_pro_ptr;
}

void EditInvoiceWindow::on_add_btn_clicked()
{
    choose_pro_ptr->SHOW();
    this->close();
}

void EditInvoiceWindow::on_edit_btn_clicked()
{
    edit_pro_ptr->set_inv_id(this->inv_id);
    edit_pro_ptr->SHOW();
    this->close();
}


void EditInvoiceWindow::on_del_btn_clicked()
{
    del_pro_ptr->set_inv_id(this->inv_id);
    del_pro_ptr->SHOW();
    this->close();
}

void EditInvoiceWindow::on_save_btn_clicked()
{
    this->close();
    emit save();
}

void EditInvoiceWindow::display_data()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];
    ui->id->setText(QString::fromStdString(inv->getId()));
    QString type;

    if (inv->isDomestic() && inv->isIncoming())
        type = "Domestic Import";
    if (!inv->isDomestic() && inv->isIncoming())
        type = "Domestic Import";
    if (inv->isDomestic() && !inv->isIncoming())
        type = "Domestic Import";
    if (!inv->isDomestic() && !inv->isIncoming())
        type = "Domestic Import";
    ui->type->setText(type);
    ui->type->setReadOnly(true);

    QString format = "yyyy/MM/dd HH:mm";
    QString date = QString::fromStdString(inv->getTime());

    ui->date->setDateTime(QDateTime::fromString(date, format));
    ui->date->setReadOnly(true);

    ui->data->setRowCount(0);

    ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem("name"));
    ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem("Unit Price"));
    ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem("Quantity"));
    ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem("Price"));

    for(auto pro : inv->get_list_of_product_ID())
    {
        QString name = QString::fromStdString(inv->get_list_of_products()[pro].product.getID());
        QString unit_price = QString::number(inv->get_list_of_products()[pro].product.getUnitPrice());
        QString quantity = QString::number(inv->get_list_of_products()[pro].quantiy);
        QString price = QString::number(inv->get_list_of_products()[pro].quantiy * inv->get_list_of_products()[pro].product.getUnitPrice());

        ui->data->insertRow(ui->data->rowCount());
        ui->data->setItem(ui->data->rowCount() - 1, 0, new QTableWidgetItem(name));
        ui->data->setItem(ui->data->rowCount() - 1, 1, new QTableWidgetItem(unit_price));
        ui->data->setItem(ui->data->rowCount() - 1, 2, new QTableWidgetItem(quantity));
        ui->data->setItem(ui->data->rowCount() - 1, 3, new QTableWidgetItem(price));
    }
}

void EditInvoiceWindow::set_inv_id(std::string inv_id)
{
    this->inv_id = inv_id;
}

void EditInvoiceWindow::SHOW()
{
    this->show();
    display_data();
}

void EditInvoiceWindow::added_show()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];
    inv->addProduct(product.product.getID(), product.product, product.quantiy);
    display_data();
    this->show();
}

void EditInvoiceWindow::Show()
{
    display_data();
    this->show();
}
