#include "menu-widget.h"

MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    QPalette pal = QPalette();


    pal.setColor(QPalette::Window, Qt::red);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setFixedWidth(50);
}
