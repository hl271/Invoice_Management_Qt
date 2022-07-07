#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CoreApp = new App();

//    Load products.csv to database

    QFile products_file(product_filepath);
    if (products_file.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream products_in(&products_file);

        while (!products_in.atEnd())
        {
            QList<QString> line = products_in.readLine().split(";");

            for (int i = 0; i < line.size(); i += 3)
            {
                std::string id = line[i].toStdString();
                std::string name = line[i + 1].toStdString();
                double unit_price = line[i + 2].toDouble();

                CoreApp->addExistingProductToDb(id, name, unit_price);
            }
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
            double profit = line[3].toDouble();
            CoreApp->addExistingInvoiceToDb(code, time);
            CoreApp->DB_INVOICE[code]->updateProfit(profit);

            for (int i = 4; i < line.size(); i += 2)
            {
                std::string id = line[i].toStdString();
                int quantity = line[i].toInt();

                CoreApp->addProductToInvoice(code, id, quantity);
            }
        }
    }

    invoices_file.close();

    ptrAddInvoice = new AddInvoice(this, CoreApp);
    ptrUpdateItem = new UpdateItem(this, CoreApp);
    ptrFilter = new filter(this, CoreApp);
}

MainWindow::~MainWindow()
{
    std::cout <<"MainWindow closed!" <<std::endl;
    QFile products_file(product_filepath);
    if (products_file.open(QFile::WriteOnly | QFile::Truncate | QFile::Text))
    {
        QTextStream products_out(&products_file);
        for (std::string id : CoreApp->IDS_PRODUCT)
        {
            QString id_item = QString::fromStdString(id);
            QString name_product = QString::fromStdString(CoreApp->DB_PRODUCT[id].getProduceName());
            QString unit_price = QString::number(CoreApp->DB_PRODUCT[id].getUnitPrice());

            products_out << id_item << ";" << name_product << ";" << unit_price << "\n";
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

            std::stringstream ss;
            ss << invoice->getTimestamp();
            std::string ts = ss.str();

            QString code_invoice = QString::fromStdString(code);
            QString type_invoice = QString::fromStdString(type);
            QString time_invoice = QString::fromStdString(ts);
            QString profit_invoice = QString::number(invoice->getProfit());

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
    delete ptrAddInvoice;
    delete ptrUpdateItem;
    delete ptrFilter;
}

void MainWindow::on_add_btn_clicked()
{
    ptrAddInvoice->Show();
}

void MainWindow::on_change_btn_clicked()
{
    ptrUpdateItem->Show();
}

void MainWindow::on_filter_btn_clicked()
{
    ptrFilter->Show();
}

void MainWindow::on_exit_btn_clicked()
{
    close();
}
