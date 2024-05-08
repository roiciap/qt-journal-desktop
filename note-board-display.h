#ifndef NOTEBOARDDISPLAY_H
#define NOTEBOARDDISPLAY_H


#include <QQuickWidget>

class NoteBoardDisplay : public QQuickWidget
{
    Q_OBJECT
    // Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)

public:
    NoteBoardDisplay(QWidget*);


public slots:
    void moved(int, int);
};



#endif // NOTEBOARDDISPLAY_H
