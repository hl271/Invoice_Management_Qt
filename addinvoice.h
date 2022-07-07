#ifndef ADDINVOICE_H
#define ADDINVOICE_H

#include <QDialog>
#include <QDebug>

#include "additem.h"
#include "app.h"

namespace Ui {
class AddInvoice;
}

class AddInvoice : public QDialog
{
    Q_OBJECT

public:
    explicit AddInvoice(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~AddInvoice();
    void Show();

private slots:
    void on_add_item_btn_clicked();

    void on_Cancel_btn_clicked();

private:
    Ui::AddInvoice *ui;
    App *CoreApp;
    addItem *ptrAddItem;
    void resetElements();
};

#endif // ADDINVOICE_H
