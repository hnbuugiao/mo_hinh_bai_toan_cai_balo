#include "graphic.h"
#include <QPainter>

graphic::graphic(QWidget *parent) :
    QWidget(parent)
{
}
void graphic::paintEvent(QPaintEvent *){
    int w=width();
    int h=height();
    QPainter painter(this);
    painter.setBrush(QColor("#aeadac"));
    painter.drawRect(0,0,w,h);
}
