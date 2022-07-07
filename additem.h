#ifndef ADDITEM_H
#define ADDITEM_H

#include <QDialog>
#include "app.h"

namespace Ui {
class addItem;
}

class addItem : public QDialog
{
    Q_OBJECT

public:
    explicit addItem(QWidget *parent = nullptr, App *CoreApp = nullptr, std::string id = "");
    ~addItem();
    void Show();

private slots:
    void on_ADD_btn_clicked();

private:
    Ui::addItem *ui;
    App *CoreApp;
    std::string id;
    void resetElements();
};

#endif // ADDITEM_H
