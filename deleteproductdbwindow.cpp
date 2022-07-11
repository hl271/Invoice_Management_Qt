#include "deleteproductdbwindow.h"
#include "ui_deleteproductdbwindow.h"

DeleteProductDBWindow::DeleteProductDBWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::DeleteProductDBWindow)
{
    ui->setupUi(this);
    this->setFixedSize(400, 125);

    this->CoreApp = CoreApp;
}

DeleteProductDBWindow::~DeleteProductDBWindow()
{
    delete ui;
}


void DeleteProductDBWindow::on_delete_btn_clicked()
{
    std::string pro_id = ui->comboBox->currentText().toStdString();
    for (auto inv_id : CoreApp->IDS_INVOICE)
        if (CoreApp->DB_INVOICE[inv_id]->checkIfProductExists(pro_id))
            CoreApp->removeProductFromInvoice(inv_id, pro_id);

    for (int i = 0; i < CoreApp->IDS_PRODUCT.size(); i++)
        if (pro_id == CoreApp->IDS_PRODUCT[i])
        {
            CoreApp->IDS_PRODUCT.erase(CoreApp->IDS_PRODUCT.begin() + i);
            break;
        }
    CoreApp->DB_PRODUCT.erase(pro_id);

    this->close();
    emit del();
}


void DeleteProductDBWindow::on_cancel_btn_clicked()
{
    this->close();
    emit cancel();
}

void DeleteProductDBWindow::Show()
{
    ui->comboBox->clear();
    for (auto pro_id : CoreApp->IDS_PRODUCT)
        ui->comboBox->addItem(QString::fromStdString(pro_id));
    this->show();
}
