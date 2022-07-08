#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);

    this->setFixedSize(520, 600);
}

FilterWindow::~FilterWindow()
{
    delete ui;
}

void FilterWindow::on_close_btn_clicked()
{
    close();
}

