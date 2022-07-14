// GUI - Do Hoang Khoi
#ifndef CHOOSEINVOICEWINDOW_H
#define CHOOSEINVOICEWINDOW_H

#include <QWidget>
#include "editinvoicewindow.h"
#include "app.h"

namespace Ui {
class ChooseInvoiceWindow;
}

class ChooseInvoiceWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseInvoiceWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~ChooseInvoiceWindow();
    void SHOW();

signals:
    void del();
    void cancel();

private slots:
    void on_edit_btn_clicked();

    void on_del_btn_clicked();

    void on_cancel_btn_clicked();

    void Show();

private:
    Ui::ChooseInvoiceWindow *ui;

    EditInvoiceWindow *edit_inv_ptr;
    App *CoreApp;
};

#endif // CHOOSEINVOICEWINDOW_H
