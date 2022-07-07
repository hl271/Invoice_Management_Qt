#include "filter.h"
#include "ui_filter.h"

filter::filter(QWidget *parent, App *CoreApp) :
    QDialog(parent),
    ui(new Ui::filter)
{
    ui->setupUi(this);
    this->CoreApp = CoreApp;
    QStringList header;
    header << "Invoice Code" << "Date" << "Product ID" << "Product Name" << "Price" << "Quantity";
    ui->data_table->setHorizontalHeaderLabels(header);
    ui->from_label->setVisible(false);
    ui->to_label->setVisible(false);
    ui->start_date->setVisible(false);
    ui->end_date->setVisible(false);
    ui->rdo_Foreign->setVisible(false);
    ui->rdo_domestic->setVisible(false);
    ui->rdo_export->setVisible(false);
    ui->rdo_import->setVisible(false);
    ui->rdo_df->setVisible(false);
    ui->rdo_ie->setVisible(false);
}

filter::~filter()
{
    delete ui;

    resetElements();
}

void filter::Show()
{
    this->show();
}

void filter::on_filter_btn_clicked()
{

    ui->data_table->clearContents();
    QStringList header;
    header << "Invoice Code" << "Date" << "Product ID" << "Product Name" << "Price" << "Quantity";
    ui->data_table->setHorizontalHeaderLabels(header);

    if(ui->rdo_code->isChecked())
    {
        std::string sCode = ui->filter_val->text().toStdString();
        std::string result = CoreApp->searchByInvoiceCode(sCode);
        if (result == "")
        {
            QMessageBox messageBox;
            messageBox.critical(0,"Error", "The invoice code does not exist!");
            messageBox.setFixedSize(500, 200);
        }

        Invoice *invoice = CoreApp->DB_INVOICE[sCode];
        std::stringstream ss;
        ss << invoice->getTimestamp();
        std::string ts = ss.str();

        unordered_map<string, struct ProductWithQuantity> products = invoice->get_list_of_products();

        for (const std::string &it : invoice->get_list_of_product_ID())
        {
            ui->data_table->insertRow(ui->data_table->rowCount());
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(sCode)));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(ts)));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(products[it].product.getID())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(products[it].product.getProduceName())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].product.getUnitPrice())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].quantiy)));
        }

    }

    if(ui->rdo_type->isChecked())
    {
        std::vector<std::string> result;
        if (ui->rdo_Foreign->isChecked())
        {
            if (ui->rdo_export->isChecked())
                result = CoreApp->searchByInvoiceType("OF");
            if (ui->rdo_import->isChecked())
                result = CoreApp->searchByInvoiceType("IF");
            if (ui->rdo_ie->isChecked())
                result = CoreApp->searchByInvoiceType("F");
        }

        if (ui->rdo_domestic->isChecked())
        {
            if (ui->rdo_export->isChecked())
                result = CoreApp->searchByInvoiceType("OD");
            if (ui->rdo_import->isChecked())
                result = CoreApp->searchByInvoiceType("ID");
            if (ui->rdo_ie->isChecked())
                result = CoreApp->searchByInvoiceType("D");
        }

        if (ui->rdo_df->isChecked())
        {
            if (ui->rdo_export->isChecked())
                result = CoreApp->searchByInvoiceType("O");
            if (ui->rdo_import->isChecked())
                result = CoreApp->searchByInvoiceType("I");
            if (ui->rdo_ie->isChecked())
            {
                result = CoreApp->searchByInvoiceType("F");
                std::vector<std::string> result1 = CoreApp->searchByInvoiceType("D");
                result.insert(result.end(), result1.begin(), result1.end());
            }
        }

        for (const std::string &code : result)
        {
            Invoice *invoice = CoreApp->DB_INVOICE[code];
            std::stringstream ss;
            ss << invoice->getTimestamp();
            std::string ts = ss.str();

            unordered_map<string, struct ProductWithQuantity> products = invoice->get_list_of_products();

            for (const std::string &it : invoice->get_list_of_product_ID())
            {
                ui->data_table->insertRow(ui->data_table->rowCount());
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(code)));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(ts)));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(products[it].product.getID())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(products[it].product.getProduceName())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].product.getUnitPrice())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].quantiy)));
            }
        }
    }

    if(ui->rdo_item->isChecked())
    {
        std::string sID = ui->filter_val->text().toStdString();
        std::vector<std::string> result = CoreApp->searchByInvoiceItems(sID);

        for (const std::string &code : result)
        {
            Invoice *invoice = CoreApp->DB_INVOICE[code];
            std::stringstream ss;
            ss << invoice->getTimestamp();
            std::string ts = ss.str();

            struct ProductWithQuantity product = invoice->get_list_of_products()[sID];

            ui->data_table->insertRow(ui->data_table->rowCount());
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(code)));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(ts)));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(product.product.getID())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(product.product.getProduceName())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(product.product.getUnitPrice())));
            ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(product.quantiy)));
        }
    }

    if (ui->rdo_date->isChecked())
    {
        std::string start_day = ui->start_date->text().toStdString();
        std::string end_day = ui->end_date->text().toStdString();

        std::vector<std::string> result = CoreApp->searchByTimeRange(start_day, end_day);

        for (const std::string &code : result)
        {
            Invoice *invoice = CoreApp->DB_INVOICE[code];
            std::stringstream ss;
            ss << invoice->getTimestamp();
            std::string ts = ss.str();

            unordered_map<string, struct ProductWithQuantity> products = invoice->get_list_of_products();

            for (const std::string &it : invoice->get_list_of_product_ID())
            {
                ui->data_table->insertRow(ui->data_table->rowCount());
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 0, new QTableWidgetItem(QString::fromStdString(code)));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 1, new QTableWidgetItem(QString::fromStdString(ts)));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::fromStdString(products[it].product.getID())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 3, new QTableWidgetItem(QString::fromStdString(products[it].product.getProduceName())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].product.getUnitPrice())));
                ui->data_table->setItem(ui->data_table->rowCount() - 1, 2, new QTableWidgetItem(QString::number(products[it].quantiy)));
            }
        }
    }
}

void filter::on_close_btn_clicked()
{
    ui->rdo_code->setChecked(true);

    ui->from_label->setVisible(false);
    ui->to_label->setVisible(false);
    ui->start_date->setVisible(false);
    ui->end_date->setVisible(false);
    ui->rdo_Foreign->setVisible(false);
    ui->rdo_domestic->setVisible(false);
    ui->rdo_export->setVisible(false);
    ui->rdo_import->setVisible(false);
    ui->rdo_df->setVisible(false);
    ui->rdo_ie->setVisible(false);
    ui->filter_val->clear();
    close();
}

void filter::resetElements()
{
    ui->filter_val->clear();
}


void filter::on_rdo_date_toggled(bool checked)
{
    if (checked)
    {
        ui->from_label->setVisible(true);
        ui->to_label->setVisible(true);
        ui->start_date->setVisible(true);
        ui->end_date->setVisible(true);
    }
    else
    {
        ui->from_label->setVisible(false);
        ui->to_label->setVisible(false);
        ui->start_date->setVisible(false);
        ui->end_date->setVisible(false);
    }
}


void filter::on_rdo_type_toggled(bool checked)
{
    if (checked)
    {
        ui->rdo_Foreign->setVisible(true);
        ui->rdo_domestic->setVisible(true);
        ui->rdo_export->setVisible(true);
        ui->rdo_import->setVisible(true);
        ui->rdo_df->setVisible(true);
        ui->rdo_ie->setVisible(true);
    }
    else
    {
        ui->rdo_Foreign->setVisible(false);
        ui->rdo_domestic->setVisible(false);
        ui->rdo_export->setVisible(false);
        ui->rdo_import->setVisible(false);
        ui->rdo_df->setVisible(false);
        ui->rdo_ie->setVisible(false);
    }
}

