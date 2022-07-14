// GUI - Do Hoang Khoi
#ifndef DELETEPRODUCTWINDOW_H
#define DELETEPRODUCTWINDOW_H

#include <QWidget>
#include <QDebug>
#include "app.h"

namespace Ui {
class DeleteProductWindow;
}

class DeleteProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteProductWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~DeleteProductWindow();
    void SHOW();
    void set_inv_id(std::string inv_id);

signals:
    void del();
    void cancel();

private slots:
    void on_delete_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::DeleteProductWindow *ui;
    App *CoreApp;
    std::string inv_id;
};

#endif // DELETEPRODUCTWINDOW_H
