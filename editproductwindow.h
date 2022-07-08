#ifndef EDITPRODUCTWINDOW_H
#define EDITPRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class EditProductWindow;
}

class EditProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditProductWindow(QWidget *parent = nullptr);
    ~EditProductWindow();

private slots:

    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::EditProductWindow *ui;
};

#endif // EDITPRODUCTWINDOW_H
