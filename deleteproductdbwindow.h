// GUI - Do Hoang Khoi
#ifndef DELETEPRODUCTDBWINDOW_H
#define DELETEPRODUCTDBWINDOW_H

#include <QWidget>
#include "app.h"

namespace Ui {
class DeleteProductDBWindow;
}

class DeleteProductDBWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteProductDBWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~DeleteProductDBWindow();
    void Show();

signals:
    void del();
    void cancel();

private slots:
    void on_delete_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::DeleteProductDBWindow *ui;
    App *CoreApp;
};

#endif // DELETEPRODUCTDBWINDOW_H
