#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "menu-widget.h"
#include "display-switch.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(MenuWidget*, DisplaySwitch*);

signals:
};

#endif // MAINWIDGET_H
