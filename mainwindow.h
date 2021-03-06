#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    // Hàm cấu trúc Đồ vật
    typedef struct{
        QString Ten;
        float TL,GT,DG;
        int PA=0;
    }DV;
    // đếm số vật bằng tham số n
    int n=0;
    // Lữu trữ temp
    QString line;
    // Trọng lượng của cái balo
    int tlbalo=0;
    // Danh sách đồ vật
    DV dsdv[100];
    DV dsdvde[100];
    void Greedy(DV dsdv[],int n,float W);
    void Swap(DV &s1,DV &s2);
    void SapXep(DV dsdv[],int n);

    // Hàm nhánh cận
    void Record();
    void NhanhCan(int i);
    // Hàm cập nhật dữ liệu
    void capnhat();
    // Hàm xử lý dữ liệu
    void xuly();
    // Hàm nhập dữ liệu vào
    void nhapdl();
    // nhập dữ liệu từ file
    void nhapdlfile();
    // lưu tên file
    QString filename;
    // Hàm để xoá một đồ vật
    void clear();
    void clear2();
    // thẻ bài kiểm tra
    int token=1;
    void check();
    //Test nhap
    void testnhap();
    // Đánh dấu đã nhấn nút File
    int permit1=0;
    // Tên các cột trong bảng Input, Output
    enum Columna{
        Ten,TL,GT,DG,PA
    };
    // Khởi tạo giá trị ban đầu của Hàm Nhánh Cận
    // Cận trên, Tổng giá trị, Trọng lượng còn lại
    int TGT=0,MAX=0,TLC=tlbalo,X[100];
    float CT;

private slots:

    void on_themvat_clicked();

    void on_dohoa_clicked();

    void ketqua();

    void on_xoavat_clicked();

    void on_file_clicked();

private:
    Ui::MainWindow *ui;
    bool clicked=false;
};

#endif // MAINWINDOW_H                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
