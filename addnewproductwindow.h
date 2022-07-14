// GUI - Do Hoang Khoi
#ifndef ADDNEWPRODUCTWINDOW_H
#define ADDNEWPRODUCTWINDOW_H

#include <QWidget>
#include "app.h"

namespace Ui {
class AddNewProductWindow;
}

class AddNewProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewProductWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~AddNewProductWindow();

signals:
    void save();
    void cancel();

private slots:
    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::AddNewProductWindow *ui;
    App *CoreApp;
};

#endif // ADDNEWPRODUCTWINDOW_H
