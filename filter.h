#ifndef FILTER_H
#define FILTER_H

#include <QDialog>
#include <QStringList>
#include <QMessageBox>
#include <sstream>
#include "app.h"

namespace Ui {
class filter;
}

class filter : public QDialog
{
    Q_OBJECT

public:
    explicit filter(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~filter();
    void Show();

private slots:
    void on_filter_btn_clicked();

    void on_close_btn_clicked();

    void on_rdo_date_toggled(bool checked);

    void on_rdo_type_toggled(bool checked);

private:
    Ui::filter *ui;
    App *CoreApp;
    void resetElements();
};

#endif // FILTER_H
