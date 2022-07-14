// GUI - Do Hoang Khoi
#ifndef EDITEXSTINGPRODUCTWINDOW_H
#define EDITEXSTINGPRODUCTWINDOW_H

#include <QWidget>
#include "app.h"

namespace Ui {
class EditExstingProductWindow;
}

class EditExstingProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditExstingProductWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~EditExstingProductWindow();
    void Show();

signals:
    void save();
    void cancel();

private slots:
    void on_save_btn_clicked();

    void on_cancel_btn_clicked();


private:
    Ui::EditExstingProductWindow *ui;
    App *CoreApp;
};

#endif // EDITEXSTINGPRODUCTWINDOW_H
