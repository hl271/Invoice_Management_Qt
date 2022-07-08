#ifndef EDITEXSTINGPRODUCTWINDOW_H
#define EDITEXSTINGPRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class EditExstingProductWindow;
}

class EditExstingProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditExstingProductWindow(QWidget *parent = nullptr);
    ~EditExstingProductWindow();

private slots:
    void on_save_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::EditExstingProductWindow *ui;
};

#endif // EDITEXSTINGPRODUCTWINDOW_H
