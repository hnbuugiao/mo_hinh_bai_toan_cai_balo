#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QWidget>

class graphic : public QWidget
{
    Q_OBJECT
public:
    explicit graphic(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // GRAPHIC_H
