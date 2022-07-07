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
#include "invoice.h"
#include "product.h"
#include "addinvoice.h"
#include "additem.h"
#include "filter.h"
#include "updateitem.h"
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
    void on_add_btn_clicked();

    void on_change_btn_clicked();

    void on_filter_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::MainWindow *ui;

    App *CoreApp;
    AddInvoice *ptrAddInvoice;
    filter *ptrFilter;
    UpdateItem *ptrUpdateItem;
};
#endif // MAINWINDOW_H
