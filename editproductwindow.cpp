#include "editproductwindow.h"
#include "ui_editproductwindow.h"

EditProductWindow::EditProductWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::EditProductWindow)
{
    ui->setupUi(this);
    this->setFixedSize(360, 175);
    this->CoreApp = CoreApp;
}

EditProductWindow::~EditProductWindow()
{
    delete ui;
}

void EditProductWindow::on_save_btn_clicked()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];

    std::string pro_id = ui->comboBox->currentText().toStdString();
    int quantity = ui->quantity->value();

    inv->setQuantity(pro_id, quantity);

    this->close();
    emit save();
}


void EditProductWindow::on_cancel_btn_clicked()
{
    this->close();
    emit cancel();
}

void EditProductWindow::set_inv_id(std::string inv_id)
{
    this->inv_id = inv_id;
}

void EditProductWindow::SHOW()
{
    Invoice *inv = CoreApp->DB_INVOICE[inv_id];

    ui->quantity->setValue(0);
    ui->comboBox->clear();
    for (auto pro_id : inv->get_list_of_product_ID())
        ui->comboBox->addItem(QString::fromStdString(pro_id));

    this->show();
}
