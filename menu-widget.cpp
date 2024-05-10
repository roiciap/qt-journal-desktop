#include "menu-widget.h"

#include <QVBoxLayout>

MenuWidget::MenuWidget(QWidget *parent)
    : QWidget{parent}
{
    QPalette pal = QPalette();


    pal.setColor(QPalette::Window, Qt::red);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setFixedWidth(50);

    QVBoxLayout *layout = new QVBoxLayout(this); // Używamy QVBoxLayout jako layoutu dla widgetu
    layout->setContentsMargins(0, 0, 0, 0); // Usuwamy marginesy

    this->buttonBoard = new QPushButton("Button board", this);
    layout->addWidget(this->buttonBoard);

    this->buttonScroll = new QPushButton("Button Scroll", this);
    layout->addWidget(this->buttonScroll);
    setLayout(layout);

    connect(this->buttonScroll, &QPushButton::clicked,this, &MenuWidget::buttonPressed);
    connect(this->buttonBoard, &QPushButton::clicked,this, &MenuWidget::buttonPressed);

}
