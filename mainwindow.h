// GUI - Do Hoang Khoi
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <QDir>
#include <QStandardItem>
#include <sstream>

#include "invoicedatabasewindow.h"
#include "productdatabasewindow.h"

#include "invoice.h"
#include "product.h"
#include "app.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString product_filepath = QDir::currentPath()+ "/products.csv";
     QString invoice_filepath = QDir::currentPath()+"/invoices.csv";
    ~MainWindow();

private slots:

     void on_inv_btn_clicked();

     void on_pro_btn_clicked();

     void on_exit_btn_clicked();

private:
    Ui::MainWindow *ui;

    InvoiceDatabaseWindow *inv_ptr;
    ProductDatabaseWindow *pro_ptr;

    App *CoreApp;
};
#endif // MAINWINDOW_H
