#include "deleteproductwindow.h"
#include "ui_deleteproductwindow.h"

DeleteProductWindow::DeleteProductWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::DeleteProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(400, 125);
    this->CoreApp = CoreApp;
}

DeleteProductWindow::~DeleteProductWindow()
{
    delete ui;
}

void DeleteProductWindow::on_delete_btn_clicked()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];
    std::string pro_id = ui->comboBox->currentText().toStdString();
    inv->removeProduct(pro_id);

    this->close();
    emit del();
}


void DeleteProductWindow::on_cancel_btn_clicked()
{
    this->close();
    emit cancel();
}

void DeleteProductWindow::SHOW()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];

    ui->comboBox->clear();
    for (auto pro_id : inv->get_list_of_product_ID())
        ui->comboBox->addItem(QString::fromStdString(pro_id));

    this->show();
}

void DeleteProductWindow::set_inv_id(std::string inv_id)
{
    this->inv_id = inv_id;
}
