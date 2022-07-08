#ifndef DELETEPRODUCTWINDOW_H
#define DELETEPRODUCTWINDOW_H

#include <QWidget>

namespace Ui {
class DeleteProductWindow;
}

class DeleteProductWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteProductWindow(QWidget *parent = nullptr);
    ~DeleteProductWindow();

private slots:
    void on_delete_btn_clicked();

    void on_cancel_btn_clicked();

private:
    Ui::DeleteProductWindow *ui;
};

#endif // DELETEPRODUCTWINDOW_H
