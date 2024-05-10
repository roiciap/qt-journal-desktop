#include "display-switch.h"

DisplaySwitch::DisplaySwitch(QWidget *parent)
    : QStackedWidget{parent}
{

}

void DisplaySwitch::setTargetAndClear(QWidget *displayWidget){
    auto cnt = this->count();
    if(cnt!= 0){
        auto a = this->widget(0);
        this->removeWidget(a);
        delete a;
    }

    this->addWidget(displayWidget);
}


