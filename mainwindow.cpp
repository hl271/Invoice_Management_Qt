#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(450, 450);

    qDebug() << product_filepath;
    qDebug() << invoice_filepath;

    CoreApp = new App();

//    Load products.csv to database

    QFile products_file(product_filepath);
    if (products_file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream products_in(&products_file);

        while (!products_in.atEnd())
        {
            QList<QString> line = products_in.readLine().split(";");

            std::string id = line[0].toStdString();
            double unit_price = line[1].toDouble();

            CoreApp->addExistingProductToDb(id, unit_price);
        }

    }

    products_file.close();

//    Load invoices.csv to database

    QFile invoices_file(invoice_filepath);
    if (invoices_file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream invoices_in(&invoices_file);

        while(!invoices_in.atEnd())
        {
            QList<QString> line = invoices_in.readLine().split(";");
            std::string code = line[0].toStdString();
            std::string time = line[2].toStdString();
//            double profit = line[3].toDouble();
            CoreApp->addExistingInvoiceToDb(code, time);
            CoreApp->DB_INVOICE[code]->setTime(time);
//            CoreApp->DB_INVOICE[code]->updateProfit(profit);

            for (int i = 4; i < line.size(); i += 2)
            {
                std::string id = line[i].toStdString();
                int quantity = line[i + 1].toInt();

                CoreApp->addProductToInvoice(code, id, quantity);
            }
        }
    }

    invoices_file.close();

    inv_ptr = new InvoiceDatabaseWindow(nullptr, CoreApp);
    pro_ptr = new ProductDatabaseWindow(nullptr, CoreApp);

    connect(inv_ptr,&InvoiceDatabaseWindow::exit2menu,this,&MainWindow::show);
    connect(pro_ptr,&ProductDatabaseWindow::exit2menu,this,&MainWindow::show);
}

MainWindow::~MainWindow()
{
    QFile products_file(product_filepath);
    if (products_file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text))
    {
        QTextStream products_out(&products_file);
        for (std::string id : CoreApp->IDS_PRODUCT)
        {
            QString id_item = QString::fromStdString(id);
            QString unit_price = QString::number(CoreApp->DB_PRODUCT[id].getUnitPrice());

            products_out << id_item << ";" << unit_price << "\n";
        }
    }

    products_file.close();

    QFile invoices_file(invoice_filepath);
    if (invoices_file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text))
    {
        QTextStream invoices_out(&invoices_file);
        for (std::string code : CoreApp->IDS_INVOICE)
        {
            Invoice *invoice = CoreApp->DB_INVOICE[code];

            std::string type = code.substr(0, 2);
            if (type == "ID") {
                type = "Domestic Import";
            }
            else if (type == "IF") {
                type = "Foreign Import";
            }
            else if (type == "OD") {
                type = "Domestic Export";
            }
            else if (type == "OF") {
                type = "Foreign Import";
            }

            std::string time = invoice->getTime();

            QString code_invoice = QString::fromStdString(code);
            QString type_invoice = QString::fromStdString(type);
            QString time_invoice = QString::fromStdString(time);
            QString profit_invoice = QString::number(invoice->calculateTotal());

            invoices_out << code_invoice << ";" << type_invoice << ";" << time_invoice << ";" << profit_invoice;
            vector<string> product_ids = invoice->get_list_of_product_ID();
            for (auto id = product_ids.begin(); id != product_ids.end(); id++)
            {
                QString id_product = QString::fromStdString(*id);
                QString quantity_product = QString::number(invoice->get_list_of_products()[*id].quantiy);

                invoices_out << ";" << id_product << ";" << quantity_product;
            }

            invoices_out << "\n";
        }

    invoices_file.close();
    }

    delete ui;
    delete CoreApp;
    delete inv_ptr;
    delete pro_ptr;
}



void MainWindow::on_inv_btn_clicked()
{
    inv_ptr->SHOW();
    this->close();
}


void MainWindow::on_pro_btn_clicked()
{
    pro_ptr->show();
    this->close();
}


void MainWindow::on_exit_btn_clicked()
{
    this->close();
}

