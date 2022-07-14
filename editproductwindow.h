// GUI - Do Hoang Khoi
#ifndef EDITPRODUCTWINDOW_H
#define EDITPRODUCTWINDOW_H

#include <QWidget>
#include "app.h"

namespace Ui {
class EditProductWindow;
}

class EditProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditProductWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~EditProductWindow();
    void set_inv_id(std::string inv_id);
    void SHOW();

signals:
    void save();
    void cancel();

private slots:

    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::EditProductWindow *ui;
    App *CoreApp;
    std::string inv_id;
};

#endif // EDITPRODUCTWINDOW_H
