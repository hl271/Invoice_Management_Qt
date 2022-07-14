// GUI - Do Hoang Khoi
#ifndef FILTERWINDOW_H
#define FILTERWINDOW_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QDateTime>
#include <sstream>
#include "app.h"

namespace Ui {
class FilterWindow;
}

class FilterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit FilterWindow(QWidget *parent = nullptr, App *CoreApp = nullptr);
    ~FilterWindow();

signals:
    void cancel();

private slots:
    void on_close_btn_clicked();

    void on_rdo_type_toggled(bool checked);

    void on_rdo_date_toggled(bool checked);

    void on_filter_btn_clicked();

    void on_rdo_code_toggled(bool checked);

    void on_rdo_item_toggled(bool checked);

private:
    Ui::FilterWindow *ui;
    App *CoreApp;
};

#endif // FILTERWINDOW_H
