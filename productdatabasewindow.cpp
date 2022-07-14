// GUI - Pham Quang Huy
#include "productdatabasewindow.h"
#include "ui_productdatabasewindow.h"

ProductDatabaseWindow::ProductDatabaseWindow(QWidget *parent, App *CoreApp) :
    QWidget(parent),
    ui(new Ui::ProductDatabaseWindow)
{
    ui->setupUi(this);

    this->setFixedSize(340, 450);
    this->CoreApp = CoreApp;

    add_new_pro_ptr = new AddNewProductWindow(nullptr, CoreApp);
    edit_pro_ptr = new EditExstingProductWindow(nullptr, CoreApp);
    del_pro_ptr = new DeleteProductDBWindow(nullptr, CoreApp);
    connect(edit_pro_ptr,&EditExstingProductWindow::cancel,this,&ProductDatabaseWindow::Show);
    connect(edit_pro_ptr,&EditExstingProductWindow::save,this,&ProductDatabaseWindow::Show);
    connect(add_new_pro_ptr,&AddNewProductWindow::cancel,this,&ProductDatabaseWindow::Show);
    connect(add_new_pro_ptr,&AddNewProductWindow::save,this,&ProductDatabaseWindow::Show);
    connect(del_pro_ptr,&DeleteProductDBWindow::del,this,&ProductDatabaseWindow::Show);
    connect(del_pro_ptr,&DeleteProductDBWindow::cancel,this,&ProductDatabaseWindow::Show);

    display_data();
}

ProductDatabaseWindow::~ProductDatabaseWindow()
{
    delete ui;
    delete add_new_pro_ptr;
    delete edit_pro_ptr;
}

void ProductDatabaseWindow::on_add_btn_clicked()
{
    add_new_pro_ptr->show();
    this->close();
}

void ProductDatabaseWindow::on_edit_btn_clicked()
{
    edit_pro_ptr->Show();
    this->close();
}

void ProductDatabaseWindow::on_exit_btn_clicked()
{
    this->close();
    emit exit2menu();
}

void ProductDatabaseWindow::display_data()
{
    ui->data_table->setRowCount(0);

    for (auto pro_id : CoreApp->IDS_PRODUCT)
    {
        QString id = QString::fromStdString(CoreApp->DB_PRODUCT[pro_id].getID());
        QString price = QString::number(CoreApp->DB_PRODUCT[pro_id].getUnitPrice());
        ui->data_table->insertRow(ui->data_table->rowCount());
        ui->data_table->setItem(ui->data_table->rowCount() - 1, 0, new QTableWidgetItem(id));
        ui->data_table->setItem(ui->data_table->rowCount() - 1, 1, new QTableWidgetItem(price));
    }
}

void ProductDatabaseWindow::Show()
{
    display_data();
    this->show();
}

void ProductDatabaseWindow::on_delete_2_clicked()
{
    del_pro_ptr->Show();
    this->close();
}

