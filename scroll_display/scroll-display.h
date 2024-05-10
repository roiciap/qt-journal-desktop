#ifndef SCROLLDISPLAY_H
#define SCROLLDISPLAY_H

#include <QWidget>

class ScrollDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit ScrollDisplay(QWidget *parent = nullptr);
};

#endif // SCROLLDISPLAY_H
