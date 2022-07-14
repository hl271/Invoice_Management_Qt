// GUI - Pham Quang Huy
#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);

    this->CoreApp = CoreApp;

    ui->date_2->setVisible(false);
    ui->date_lbl->setVisible(false);
    ui->type->setVisible(false);;
    ui->type_lbl->setVisible(false);
    ui->filter_val->clear();
    ui->filter_val->setEnabled(true);
    ui->from_label->setEnabled(false);
    ui->to_label->setEnabled(false);
    ui->end_date->setEnabled(false);
    ui->start_date->setEnabled(false);
    ui->type_2->setEnabled(false);
}

FilterWindow::~FilterWindow()
{
    delete ui;
}

void FilterWindow::on_close_btn_clicked()
{
    this->close();
    emit cancel();
}


void FilterWindow::on_rdo_type_toggled(bool checked)
{
    if (checked)
    {
        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);
        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem(""));
        ui->total_profit->clear();
        ui->date_2->setVisible(false);
        ui->date_lbl->setVisible(false);
        ui->type->setVisible(false);;
        ui->type_lbl->setVisible(false);
        ui->filter_val->clear();
        ui->filter_val->setEnabled(false);
        ui->type_2->setEnabled(true);
    }
}


void FilterWindow::on_rdo_date_toggled(bool checked)
{
    if (checked)
    {
        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);
        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem(""));
        ui->total_profit->clear();
        ui->date_2->setVisible(false);
        ui->date_lbl->setVisible(false);
        ui->type->setVisible(false);;
        ui->type_lbl->setVisible(false);
        ui->filter_val->clear();
        ui->filter_val->setEnabled(false);
        ui->from_label->setEnabled(true);
        ui->to_label->setEnabled(true);
        ui->end_date->setEnabled(true);
        ui->start_date->setEnabled(true);
        ui->type_2->setEnabled(false);
    }
}

void FilterWindow::on_rdo_code_toggled(bool checked)
{
    if (checked)
    {
        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);
        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem(""));
        ui->total_profit->clear();
        ui->date_2->setVisible(false);
        ui->date_lbl->setVisible(false);
        ui->type->setVisible(false);;
        ui->type_lbl->setVisible(false);
        ui->filter_val->clear();
        ui->filter_val->setEnabled(true);
        ui->from_label->setEnabled(false);
        ui->to_label->setEnabled(false);
        ui->end_date->setEnabled(false);
        ui->start_date->setEnabled(false);
        ui->type_2->setEnabled(false);
        ui->date_2->setReadOnly(true);
    }
}

void FilterWindow::on_rdo_item_toggled(bool checked)
{
    if (checked)
    {
        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);
        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem(""));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem(""));

        ui->total_profit->clear();
        ui->date_2->setVisible(false);
        ui->date_lbl->setVisible(false);
        ui->type->setVisible(false);;
        ui->type_lbl->setVisible(false);
        ui->filter_val->clear();
        ui->filter_val->setEnabled(true);
        ui->from_label->setEnabled(false);
        ui->to_label->setEnabled(false);
        ui->end_date->setEnabled(false);
        ui->start_date->setEnabled(false);
        ui->type_2->setEnabled(false);
    }
}

void FilterWindow::on_filter_btn_clicked()
{
    if (ui->rdo_code->isChecked())
    {
        std::string code = ui->filter_val->text().toStdString();
        ui->date_2->setVisible(true);
        ui->date_lbl->setVisible(true);
        ui->type->setVisible(true);;
        ui->type_lbl->setVisible(true);

        Invoice *inv = CoreApp->DB_INVOICE[code];
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

        QString format = "yyyy/MM/dd HH:mm";
        QString date = QString::fromStdString(inv->getTime());

        ui->date_2->setDateTime(QDateTime::fromString(date, format));

        ui->data->setColumnCount(4);
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

        ui->total_profit->setText(QString::number(inv->calculateTotal()));
    }

    if (ui->rdo_date->isChecked())
    {
        QDateTime start_time = ui->start_date->dateTime();
        QDateTime end_time = ui->end_date->dateTime();

        if (start_time < end_time)
        {
            std::vector<std::string> results;
            QString format = "yyyy/MM/dd HH:mm";
//            start_time = QDateTime::fromString(start_time.toString(format));
//            end_time = QDateTime::fromString(end_time.toString(format));
            for (auto inv_id : CoreApp->IDS_INVOICE)
            {
                QString time = QString::fromStdString(CoreApp->DB_INVOICE[inv_id]->getTime());
                QDateTime inv_time = QDateTime::fromString(time, format);
                if (inv_time >= start_time && inv_time <= end_time)
                    results.push_back(inv_id);
            }

            double total_profit = 0.0;

            ui->data->setColumnCount(4);
            ui->data->setRowCount(0);

            ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem("Inv No."));
            ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem("Created at"));
            ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem("Type"));
            ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem("Profit"));

            for (auto inv_id : results)
            {
                Invoice *inv = CoreApp->DB_INVOICE[inv_id];

                QString id = QString::fromStdString(inv_id);
                QString date = QString::fromStdString(inv->getTime());
                QString type;
                double total = inv->calculateTotal();
                double tax_payment = total * inv->getTax();
                if (!inv->isIncoming()) {
                    total_profit += total - tax_payment;
                }
                else {
                    total_profit += -total - tax_payment;
                }
                type= QString::fromStdString(inv->getTypeAsStr());
                QString profit = QString::number(inv->calculateTotal());

                ui->data->insertRow(ui->data->rowCount());
                ui->data->setItem(ui->data->rowCount() - 1, 0, new QTableWidgetItem(id));
                ui->data->setItem(ui->data->rowCount() - 1, 1, new QTableWidgetItem(date));
                ui->data->setItem(ui->data->rowCount() - 1, 2, new QTableWidgetItem(type));
                ui->data->setItem(ui->data->rowCount() - 1, 3, new QTableWidgetItem(profit));
            }

            ui->total_profit->setText(QString::number(total_profit));
        }
    }

    if (ui->rdo_item->isChecked())
    {
        std::string pro_id = ui->filter_val->text().toStdString();
        double total_profit = 0.0;

        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);

        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem("Inv No."));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem("Quantity"));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem("Unit Price"));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem("Price"));

        for (auto inv_id : CoreApp->IDS_INVOICE)
            if (CoreApp->DB_INVOICE[inv_id]->checkIfProductExists(pro_id))
            {
                Invoice *invoice = CoreApp->DB_INVOICE[inv_id];
                total_profit += invoice->get_list_of_products()[pro_id].product.getUnitPrice() * invoice->get_list_of_products()[pro_id].quantiy;
                QString inv_1d = QString::fromStdString(inv_id);
                QString quantity = QString::number(invoice->get_list_of_products()[pro_id].quantiy);
                QString unit_price = QString::number(invoice->get_list_of_products()[pro_id].product.getUnitPrice());
                QString price = QString::number(invoice->get_list_of_products()[pro_id].product.getUnitPrice() * invoice->get_list_of_products()[pro_id].quantiy);

                ui->data->insertRow(ui->data->rowCount());
                ui->data->setItem(ui->data->rowCount() - 1, 0, new QTableWidgetItem(inv_1d));
                ui->data->setItem(ui->data->rowCount() - 1, 1, new QTableWidgetItem(quantity));
                ui->data->setItem(ui->data->rowCount() - 1, 2, new QTableWidgetItem(unit_price));
                ui->data->setItem(ui->data->rowCount() - 1, 3, new QTableWidgetItem(price));
            }
        ui->total_profit->setText(QString::number(total_profit));
    }

    if (ui->rdo_type->isChecked())
    {
        QString type = ui->type_2->currentText();
        std::vector<std::string> results;

        if (type == "Domestic Import")
            results = CoreApp->searchByInvoiceType("ID");
        if (type == "Domestic Export")
            results = CoreApp->searchByInvoiceType("ED");
        if (type == "Foreign Import")
            results = CoreApp->searchByInvoiceType("IF");
        if (type == "Foreign Export")
            results = CoreApp->searchByInvoiceType("EF");
        if (type == "Import")
            results = CoreApp->searchByInvoiceType("I");
        if (type == "Domestic")
            results = CoreApp->searchByInvoiceType("D");
        if (type == "Foreign")
            results = CoreApp->searchByInvoiceType("F");
        if (type == "Export")
            results = CoreApp->searchByInvoiceType("E");

        double total_profit = 0.0;

        ui->data->setColumnCount(4);
        ui->data->setRowCount(0);

        ui->data->setHorizontalHeaderItem(0,new QTableWidgetItem("Inv No."));
        ui->data->setHorizontalHeaderItem(1,new QTableWidgetItem("Created at"));
        ui->data->setHorizontalHeaderItem(2,new QTableWidgetItem("Type"));
        ui->data->setHorizontalHeaderItem(3,new QTableWidgetItem("Profit"));

        for (auto inv_id : results)
        {
            total_profit += CoreApp->DB_INVOICE[inv_id]->calculateTotal();

            Invoice *inv = CoreApp->DB_INVOICE[inv_id];

            QString id = QString::fromStdString(inv_id);
            QString date = QString::fromStdString(inv->getTime());
            QString type;
            if (inv->isDomestic() && inv->isIncoming())
                type = "Domestic Import";
            if (!inv->isDomestic() && inv->isIncoming())
                type = "Foreign Import";
            if (inv->isDomestic() && !inv->isIncoming())
                type = "Domestic Export";
            if (!inv->isDomestic() && !inv->isIncoming())
                type = "Foreign Export";
            QString profit = QString::number(inv->calculateTotal());

            ui->data->insertRow(ui->data->rowCount());
            ui->data->setItem(ui->data->rowCount() - 1, 0, new QTableWidgetItem(id));
            ui->data->setItem(ui->data->rowCount() - 1, 1, new QTableWidgetItem(date));
            ui->data->setItem(ui->data->rowCount() - 1, 2, new QTableWidgetItem(type));
            ui->data->setItem(ui->data->rowCount() - 1, 3, new QTableWidgetItem(profit));
        }

        ui->total_profit->setText(QString::number(total_profit));
    }
}

