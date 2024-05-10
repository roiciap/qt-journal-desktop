#include "note-board-display.h"

#include <QQmlContext>

NoteBoardDisplay::NoteBoardDisplay(QWidget* parent): QQuickWidget(parent) {
    QQmlContext *context = this->rootContext();
    context->setContextProperty("noteLogic", this);

    setSource(QUrl::fromLocalFile(":/note-board-display.qml"));
}

void NoteBoardDisplay::moved(int x, int y){
    int xPos=this->x(),
        yPos=this->y();
    this->move(xPos+x, yPos+y);
}

