#ifndef ADDNEWPRODUCTWINDOW_H
#define ADDNEWPRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class AddNewProductWindow;
}

class AddNewProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddNewProductWindow(QWidget *parent = nullptr);
    ~AddNewProductWindow();

private slots:
    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::AddNewProductWindow *ui;
};

#endif // ADDNEWPRODUCTWINDOW_H
