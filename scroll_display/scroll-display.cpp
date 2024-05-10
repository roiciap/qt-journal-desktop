#include "scroll-display.h"

ScrollDisplay::ScrollDisplay(QWidget *parent)
    : QWidget{parent}
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::green);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}
