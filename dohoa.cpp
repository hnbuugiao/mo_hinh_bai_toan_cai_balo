#include "dohoa.h"
#include "ui_dohoa.h"
#include <QPainter>
#include <mainwindow.h>
#include <nhap.h>
#include <QBitmap>
#include <QMovie>
#include <QLabel>
#include <QMediaPlayer>
#include <QDebug>
#include <QMessageBox>

dohoa::dohoa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dohoa)
{
    ui->setupUi(this);
    timerId=startTimer(150);
    dem=0;
    position=100;

    //in đậm header
    QFont font;
    font.setWeight(QFont::Bold);

   // ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setColumnCount(3);
    QStringList name;
   // name << "Tên hàng hoá" << "Trọng lượng" << "Giá trị" << "Đơn giá" << "Phương án";
    name << "Tên đồ vật" << "Số lượng" << "Giá trị";
    ui->tableWidget->setHorizontalHeaderLabels(name);
     ui->tableWidget->horizontalHeader()->setFont(font);
        for (int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }


    ui->tableWidget2->setColumnCount(3);
    QStringList name1;
    name1 << "Tên hàng hoá" << "Trọng lượng" << "Giá trị";
    ui->tableWidget2->setHorizontalHeaderLabels(name1);
    ui->tableWidget2->horizontalHeader()->setFont(font);
        for (int c = 0; c < ui->tableWidget2->horizontalHeader()->count(); ++c)
    {
        ui->tableWidget2->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);

    }
}

dohoa::~dohoa()
{
    delete ui;
}
void dohoa::paintEvent(QPaintEvent *){
    QPainter painter(this);
    hondao(painter);
}
void dohoa::timerEvent(QTimerEvent *){
 //   if(dsdvde[filo].PA==0) filo++;
   // else{
    position+=20*i;
    if(dem<=2*n){
    if(dem%2!=0 && position<=800) {
        i=1;
        if(position==800) {
            dem++;
            showbang();
            filo++;
                }
         }
     else{
        i=-1;
        if(position==100) dem++;
        if(dem==(2*n)+1) QMessageBox::information(this,"Tổng giá trị","Tổng giá trị là "+QString::number(TGT));
        ui->tgt->setText(QString::number(TGT));

        }
    }
    else i=0;
    repaint();
  //  }
}
void dohoa::showbang(){
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int fila;
    QPainter painter(this);

    fila = ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    ui->tableWidget->setItem(fila,0,new QTableWidgetItem(dsdvde[fila].Ten));
    ui->tableWidget->setItem(fila,1,new QTableWidgetItem(QString::number(dsdvde[fila].PA)));
    dsdvde[filo].SGT = dsdvde[fila].PA * dsdvde[filo].GT;
    TGT+=dsdvde[fila].SGT;
    ui->tableWidget->setItem(fila,2,new QTableWidgetItem(QString::number(dsdvde[fila].SGT)));

    ui->tableWidget->item(fila,0)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->item(fila,1)->setTextAlignment(Qt::AlignCenter);
    ui->tableWidget->item(fila,2)->setTextAlignment(Qt::AlignCenter);

}

void dohoa::showbang2(){
        ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    int fila;
    fila = ui->tableWidget2->rowCount()-1;

        while(ui->tableWidget2->rowCount() > 0)
        ui->tableWidget2->removeRow(0);

    if(fila>n);
    else{
    for(int i=0;i<n;i++){
        ui->tableWidget2->insertRow(ui->tableWidget2->rowCount());
          ui->tableWidget2->setItem(i,Ten,new QTableWidgetItem(dsdv[i].Ten));
           ui->tableWidget2->setItem(i,TL,new QTableWidgetItem(QString::number(dsdv[i].TL)));
          ui->tableWidget2->setItem(i,GT,new QTableWidgetItem(QString::number(dsdv[i].GT)));

          ui->tableWidget2->item(i,Ten)->setTextAlignment(Qt::AlignCenter);
          ui->tableWidget2->item(i,TL)->setTextAlignment(Qt::AlignCenter);
          ui->tableWidget2->item(i,GT)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void dohoa::showlabel(){
    QPainter painter(this);

    QRect rect(position+60,570,150,120);
    if(filo>n-1);
    else{

        dsdvde[filo].SGT = dsdvde[filo].PA * dsdvde[filo].GT;

        QFont font = painter.font();
        font.setPointSize(15);
        painter.setFont(font);
        painter.setPen(Qt::red);
        painter.drawText(rect,Qt::AlignCenter,"Tên đồ vật:"+dsdvde[filo].Ten+
                                 +"\n"+"Số lượng:"+QString::number(dsdvde[filo].PA)+"\n"+"Giá trị:"+QString::number(dsdvde[filo].SGT));
    }
}

void dohoa::hondao(QPainter &painter){

        int w=width();
        int h=height();
        painter.Antialiasing;

        QImage truck(":/Images/truck.png");
        QImage house(":/Images/house.png");
        QImage city(":/Images/city.jpg");
        QImage road(":/Images/road.jpg");
        QImage sky(":/Images/sky.jpg");

        if(dem%2==0){
            QMatrix rm;
            rm.rotate(180);
            truck = truck.transformed(rm);
            truck = truck.mirrored(false,true);
        }
        painter.drawImage(QRect(0,0,w,200),sky);
        painter.drawImage(QRect(0,200,w,h*0.8),city);
        painter.drawImage(QRect(position,570,400,200),truck);


        ui->label_2->setGeometry(100,260,200,30);
        ui->label->setGeometry(1050,260,200,30);
        ui->tableWidget2->setGeometry(0,0,310,250);
        ui->tableWidget->setGeometry(960,0,320,250);
        ui->label_3->setGeometry(920,290,120,30);
        ui->tgt->setGeometry(1030,295,100,20);
        if(dem%2!=0) showlabel();
        for(int i=1;i<=1;i++){
        showbang2();
        }
}

void dohoa::on_btnStop_clicked()
{
        killTimer(timerId);
}

void dohoa::on_pushButton_clicked()
{
    timerId =startTimer(150);
}
