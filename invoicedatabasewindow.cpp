#include "invoicedatabasewindow.h"
#include "ui_invoicedatabasewindow.h"

InvoiceDatabaseWindow::InvoiceDatabaseWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::InvoiceDatabaseWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1250, 515);

    add_inv_ptr = new AddInvoiceWindow(nullptr, CoreApp);
    edit_inv_ptr = new ChooseInvoiceWindow(nullptr, CoreApp);
    filter_ptr = new FilterWindow(nullptr, CoreApp);
    this->CoreApp = CoreApp;

    connect(add_inv_ptr,&AddInvoiceWindow::cancel,this,&InvoiceDatabaseWindow::Show);
    connect(add_inv_ptr,&AddInvoiceWindow::save,this,&InvoiceDatabaseWindow::Show);
    connect(edit_inv_ptr,&ChooseInvoiceWindow::del,this,&InvoiceDatabaseWindow::Show);
    connect(edit_inv_ptr,&ChooseInvoiceWindow::cancel,this,&InvoiceDatabaseWindow::Show);
    connect(filter_ptr,&FilterWindow::cancel,this,&InvoiceDatabaseWindow::Show);


    display_data();
}

InvoiceDatabaseWindow::~InvoiceDatabaseWindow()
{
    delete ui;
    delete add_inv_ptr;
    delete edit_inv_ptr;
    delete filter_ptr;
}

void InvoiceDatabaseWindow::on_add_btn_clicked()
{
    add_inv_ptr->SHOW();
    this->close();
}

void InvoiceDatabaseWindow::on_edit_btn_clicked()
{
    edit_inv_ptr->SHOW();
    this->close();
}

void InvoiceDatabaseWindow::on_filter_btn_clicked()
{
    filter_ptr->show();
    this->close();
}

void InvoiceDatabaseWindow::on_exit_btn_clicked()
{
    this->close();
    emit exit2menu();
}

void InvoiceDatabaseWindow::Show()
{
    ui->data->clear();
    display_data();
    this->show();
}

void InvoiceDatabaseWindow::display_data()
{
    ui->data->setColumnCount(8);
    ui->data->setColumnWidth(0, 120);
    ui->data->setColumnWidth(1, 150);
    ui->data->setColumnWidth(2, 150);
    ui->data->setColumnWidth(3, 240);
    ui->data->setColumnWidth(4, 120);
    ui->data->setColumnWidth(5, 190);
    ui->data->setColumnWidth(6, 120);
    ui->data->setColumnWidth(7, 120);

    for (auto id : CoreApp->IDS_INVOICE)
    {
        Invoice *invoice = CoreApp->DB_INVOICE[id];


        QTreeWidgetItem *root = new QTreeWidgetItem(ui->data);
        root->setText(0, "Inv No. :");
        root->setText(1, QString::fromStdString(invoice->getId()));
        root->setText(2, "created at :");
        root->setText(3, QString::fromStdString(invoice->getTime()));
        root->setText(4, "type :");
        root->setText(5, QString::fromStdString(invoice->getTypeAsStr()));
        root->setText(6, "total :");
        root->setText(7, QString::number(invoice->calculateTotal()));

        ui->data->addTopLevelItem(root);

        for (auto pro_id : invoice->get_list_of_product_ID())
        {
            QTreeWidgetItem *pro = new QTreeWidgetItem();
            pro->setText(0, "Pro No. :");
            pro->setText(1, QString::fromStdString(invoice->get_list_of_products()[pro_id].product.getID()));
            pro->setText(2, "quanity :");
            pro->setText(3, QString::number(invoice->get_list_of_products()[pro_id].quantiy));
            root->addChild(pro);
        }
    }

    ui->total_profit->setText(QString::number(CoreApp->calculateProfit()));
}

void InvoiceDatabaseWindow::SHOW()
{
    this->Show();
}
