#ifndef NHAP_H
#define NHAP_H

#include <QDialog>

namespace Ui {
class nhap;
}

class nhap : public QDialog
{
    Q_OBJECT

public:
    explicit nhap(QWidget *parent = 0);
    ~nhap();
        QString nhapdulieu();
        QString tl();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::nhap *ui;
};

#endif // NHAP_H
