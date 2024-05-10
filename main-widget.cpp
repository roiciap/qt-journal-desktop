#include "main-widget.h"
#include <QHBoxLayout>

MainWidget::MainWidget(MenuWidget* menu, DisplaySwitch* displayTarget)
    : QWidget{nullptr}
{
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::darkGray);
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    menu->setParent(this);
    displayTarget->setParent(this);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    this->setLayout(hLayout);
    // create current display target
    hLayout->addWidget(displayTarget);
    hLayout->setStretchFactor(displayTarget, 1);
    hLayout->addWidget(menu);
    connect(menu, &MenuWidget::buttonLeftClick, displayTarget, &DisplaySwitch::setTargetAndClear);
}
