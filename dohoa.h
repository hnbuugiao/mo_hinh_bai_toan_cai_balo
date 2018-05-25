#ifndef DOHOA_H
#define DOHOA_H

#include <QDialog>
#include <QTimer>
namespace Ui {
class dohoa;
}

class dohoa : public QDialog
{
    Q_OBJECT

public:
    explicit dohoa(QWidget *parent = 0);
    ~dohoa();
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void hondao(QPainter& painter);
    // Bảng kho hàng A ( Input)
    void showbang();
    // Bảng kho hàng B ( Output)
    void showbang2();
    void showlabel();
    // Cấu trúc đồ vật
    typedef struct{
        QString Ten;
        float TL,GT,DG;
        int PA;
        float SGT=TL*PA;
    }DVA;
    // Danh sách đồ vật
    DVA dsdv[100];
    DVA dsdvde[100];
    // Khởi tạo giá trị ban đầu
    int sovat=0,tlbalo=0,n=0;
    // Tham số cho hàm timer
    double timerId;
    double position;
    int TGT=0;
    int i=0,dem=1,filo=0;
    // Tên các cột của bảng
    enum Columna{
        Ten,TL,GT,DG,PA,SGT
    };
    // Hàm dừng tiến trình đang chạy
   // void xuLyRun();
  //  void on_btnStop_clicked();
public slots:

private slots:


    void on_btnStop_clicked();

    void on_pushButton_clicked();

private:
    Ui::dohoa *ui;
    QTimer *timer;
};

#endif // DOHOA_H
