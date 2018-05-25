#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <nhap.h>
#include <dohoa.h>
#include <QMessageBox>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QPainter>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // in đậm header
    QFont font;
    font.setWeight(QFont::Bold);
    // Setting cho bảng Input
    ui->tableWidget->setColumnCount(3);
    QStringList name;
    name << "Tên hàng hoá" << "Trọng lượng" << "Giá trị";
    ui->tableWidget->setHorizontalHeaderLabels(name);


    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setFont(font);
    for (int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    // style tiêu đề */
    ui->tieude->setStyleSheet("font-size: 30pt; font-weight: bold; color: black;");
    line = "";

    ui->widget->setStyleSheet("background-image: url(:/Images/road.jpg)");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Swap(DV &s1, DV &s2){
    DV temp=s1;
    s1=s2;
    s2=temp;

}

void MainWindow::SapXep(DV dsdv[],int n){
    for(int i=1;i<=n;i++)
        for(int j=n;j>=i;j--){
            if(dsdv[j].DG>dsdv[j-1].DG)
                Swap(dsdv[j],dsdv[j-1]);
        }
}

void MainWindow::Greedy(DV dsdv[],int n,float W){
    for(int i=1;i<=n;i++){
        dsdv[i].PA=(int)W/dsdv[i].TL;
        W=W-(dsdv[i].TL*dsdv[i].PA);
    }
}


// Hàm Nhánh cận
void MainWindow::Record(){
    int i;
    if(MAX<TGT){
        MAX=TGT;
        for(i=0;i<n;i++)
        dsdvde[i].PA=X[i];
    }
}

void MainWindow::NhanhCan(int i){
    int j;
    for(j=TLC/dsdvde[i].TL;j>=0;j--){
        TGT+=j*dsdvde[i].GT;
        TLC-=j*dsdvde[i].TL;
        CT=TGT+TLC*dsdvde[i+1].DG;
        if(CT>MAX){
            X[i]=j;
            if((i==n-1)||(TLC==0))
                Record();
            else NhanhCan(i+1);
        }
        X[i]=0;
        TGT-=j*dsdvde[i].GT;
        TLC+=j*dsdvde[i].TL;
    }
}
// Xử lý dữ liệu nhập vào
void MainWindow::xuly(){
    SapXep(dsdvde,n);
  //  Greedy(dsdvde,n,tlbalo);
    TLC=tlbalo;
    CT=TLC*dsdvde[0].DG;
   // qDebug() << TLC << CT;
    NhanhCan(0);
}
// Thêm một đồ vật mới vào
void MainWindow::on_themvat_clicked()
{
    int fila;
    fila = ui->tableWidget->rowCount()-1;
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    n++;
}
// Nhập dữ liệu từ bảng Input
void MainWindow::nhapdl(){
    QTableWidgetItem *a=new QTableWidgetItem();
    QTableWidgetItem *b=new QTableWidgetItem();
    QTableWidgetItem *c=new QTableWidgetItem();
    for(int i=0;i<n;i++){
            a=ui->tableWidget->item(i,0);
            b=ui->tableWidget->item(i,1);
            c=ui->tableWidget->item(i,2);


            if(a->text().isEmpty()){
                QMessageBox::information(this,"Lỗi nhập dữ liệu","Có giá trị rỗng!!");
                token=0;
            }
            if(b->text().isEmpty()){
                QMessageBox::information(this,"Lỗi nhập dữ liệu","Có giá trị rỗng!!");
                token=0;
            }
            if(c->text().isEmpty()){
                QMessageBox::information(this,"Lỗi nhập dữ liệu","Có giá trị rỗng!!");
                token=0;
            }

            dsdv[i].Ten=a->text();
            dsdv[i].TL=b->text().toInt();
            dsdv[i].GT=c->text().toInt();
            dsdv[i].DG=dsdv[i].GT / dsdv[i].TL;

            dsdvde[i].Ten=dsdv[i].Ten;
            dsdvde[i].TL=dsdv[i].TL;
            dsdvde[i].GT=dsdv[i].GT;
            dsdvde[i].DG=dsdv[i].DG;

    }
    tlbalo = ui->lineEdit->text().toInt();

}

void MainWindow::nhapdlfile()
{
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    int count=0;
    QStringList temp[100];
    int row=0;
    while(!in.atEnd()){
        QString line = in.readLine();
        temp[row] = line.split(" ");
        qDebug() << temp[row].value(0) << temp[row].value(1) << temp[row].value(2);
        row++;
        count++;
    }
    for(int i=0;i<count;i++){
        on_themvat_clicked();
    }
    n = count;
    for(int i=0;i<count;i++){
        ui->tableWidget->setItem(i,Ten,new QTableWidgetItem(temp[i].value(0)));
         ui->tableWidget->setItem(i,TL,new QTableWidgetItem(temp[i].value(1)));
          ui->tableWidget->setItem(i,GT,new QTableWidgetItem(temp[i].value(2)));

          ui->tableWidget->item(i,0)->setTextAlignment(Qt::AlignCenter);
          ui->tableWidget->item(i,1)->setTextAlignment(Qt::AlignCenter);
          ui->tableWidget->item(i,2)->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::capnhat(){
    nhapdl();
}

void MainWindow::clear2(){
    for(int i=0;i<n;i++){
        dsdvde[i].Ten.clear();
        dsdvde[i].TL=0;
        dsdvde[i].GT=0;
        dsdvde[i].DG=0;
        dsdvde[i].PA=0;
        X[i]=0;
    }
    CT=0;
    MAX=0;
    TGT=0;
}
void MainWindow::check(){
    token=1;
    for(int i=0;i<n;i++){
        QString a=ui->tableWidget->item(i,0)->text();
        float b=ui->tableWidget->item(i,1)->text().toFloat();
        float c=ui->tableWidget->item(i,2)->text().toFloat();
        QString d;
        if(a == "" || b == 0 || c == 0  ){
            if(a == "") d="Tên";
            else if( b == 0) d = "Trọng lượng";
            else d = "Giá trị";
            token=0;
            QMessageBox::information(this,"Lỗi nhập dữ liệu","Thông tin nhập vào tại dòng " + QString::number(i+1) + ", cột " + d +" không hợp lệ!");
        }
    }
    if(ui->lineEdit->text() == ""){
        QMessageBox::information(this,"Lỗi nhập dữ liệu","Chưa nhập vào trọng lượng balo!");
        token=0;
    }
}

// Cập nhật lại dữ liệu và xuất ra Output
void MainWindow::ketqua()
{
    clear2();
    capnhat();
    check();
    xuly();
}
// Chuyển sang đồ hoạ
void MainWindow::on_dohoa_clicked()
{
    ketqua();
    testnhap();
    if(token==1){
    dohoa dh;
    dh.setWindowTitle("Do hoa");
    dh.n=n;
    dh.tlbalo=tlbalo;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            dh.dsdv[i].Ten = dsdv[i].Ten;
            dh.dsdv[i].TL = dsdv[i].TL;
            dh.dsdv[i].GT = dsdv[i].GT;
            dh.dsdv[i].DG = dsdv[i].DG;
            dh.dsdv[i].PA = dsdv[i].PA;
        }
        dh.dsdvde[i].Ten = dsdvde[i].Ten;
        dh.dsdvde[i].TL = dsdvde[i].TL;
        dh.dsdvde[i].GT = dsdvde[i].GT;
        dh.dsdvde[i].DG = dsdvde[i].DG;
        dh.dsdvde[i].PA = dsdvde[i].PA;
    }
    dh.exec();
    }
}

// Xoá một vật
void MainWindow::on_xoavat_clicked()
{
    QList<QTableWidgetItem*> selectionRangeList = this->ui->tableWidget->selectedItems();
    int rowIndex;
    QListIterator<QTableWidgetItem*> selectionRangeListIter(selectionRangeList);

    while(selectionRangeListIter.hasNext()){
        rowIndex = ((int)((QTableWidgetItem*)selectionRangeListIter.next())->row());
        this->ui->tableWidget->removeRow(rowIndex);
    }
    n--;
}

void MainWindow::on_file_clicked()
{
    filename=QFileDialog::getOpenFileName(
    this,
    tr("Open file"),
    "C://",
    "All files (*.*);;Text File(*.txt"
    );
    nhapdlfile();
    permit1=1;
}

void MainWindow::testnhap()
{
    if(permit1==1){
    int permit;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Lưu dữ liệu nguồn", "Bạn có muốn lưu dữ liệu vừa nhập?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes)
        permit=1;
    else
        permit=0;
    if(permit==1){
    QFile file1(filename);
    file1.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream stream(&file1);
    for(int i=0;i<n;i++){
    stream << dsdv[i].Ten << " " << QString::number(dsdv[i].TL) << " " << QString::number(dsdv[i].GT) << endl;
          }
      }
    }
}

