#ifndef UPDATEITEM_H
#define UPDATEITEM_H

#include <QWidget>
#include <QDialog>
#include "app.h"

namespace Ui {
class UpdateItem;
}

class UpdateItem : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateItem(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~UpdateItem();
    void Show();

private slots:
    void on_UPDATE_btn_clicked();

private:
    Ui::UpdateItem *ui;
    App *CoreApp;
    void resetElements();
};


#endif // UPDATEITEM_H
