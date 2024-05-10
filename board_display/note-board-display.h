#ifndef NOTEBOARDDISPLAY_H
#define NOTEBOARDDISPLAY_H


#include <QWidget>
#include <QPainter>

class NoteBoardDisplay : public QWidget
{
    Q_OBJECT
    // Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    static const int TOP_BAR_HEIGHT = 30;
    NoteBoardDisplay(QWidget*);



public slots:
    void moved(int, int);

protected:
    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;
    QPoint lastMousePosition;
    bool isDragging=false;
};




#endif // NOTEBOARDDISPLAY_H
