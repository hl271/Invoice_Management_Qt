// GUI - Pham Quang Huy
#include "editexstingproductwindow.h"
#include "ui_editexstingproductwindow.h"

EditExstingProductWindow::EditExstingProductWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::EditExstingProductWindow)
{
    ui->setupUi(this);

    this->setFixedSize(350, 170);
    this->CoreApp = CoreApp;
}

EditExstingProductWindow::~EditExstingProductWindow()
{
    delete ui;
}

void EditExstingProductWindow::on_save_btn_clicked()
{
    std::string pro_id = ui->comboBox->currentText().toStdString();
    double price = ui->price->value();

    CoreApp->DB_PRODUCT[pro_id].setUnitPrice(price);

    close();
    emit save();
}

void EditExstingProductWindow::on_cancel_btn_clicked()
{
    this->close();
    emit cancel();
}

void EditExstingProductWindow::Show()
{
    ui->price->setValue(0);
    ui->comboBox->clear();
    for (auto pro_id : CoreApp->IDS_PRODUCT)
        ui->comboBox->addItem(QString::fromStdString(pro_id));
    this->show();
}

