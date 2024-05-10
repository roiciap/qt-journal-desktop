#include "display-switch.h"

DisplaySwitch::DisplaySwitch(QWidget *parent)
    : QStackedWidget{parent}
{

}

void DisplaySwitch::setTargetAndClear(QWidget *displayWidget){
    for (int i=this->count(); 0<i; i++) {
        this->removeWidget(this->widget(i));
    }
    this->addWidget(displayWidget);
}
