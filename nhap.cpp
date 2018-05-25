#include "nhap.h"
#include "ui_nhap.h"

nhap::nhap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nhap)
{
    ui->setupUi(this);
}

nhap::~nhap()
{
    delete ui;
}

void nhap::on_buttonBox_accepted()
{
    accept();
}

void nhap::on_buttonBox_rejected()
{
    reject();
}

QString nhap::nhapdulieu(){
    return ui->nhapnew->toPlainText();
}
QString nhap::tl(){
    return ui->trongluong->text();
}
