#ifndef DISPLAYSWITCH_H
#define DISPLAYSWITCH_H

#include <QStackedWidget>

class DisplaySwitch : public QStackedWidget
{
    Q_OBJECT
public:
    explicit DisplaySwitch(QWidget *parent = nullptr);
    void setTargetAndClear(QWidget*);
signals:
};

#endif // DISPLAY-SWITCH_H
