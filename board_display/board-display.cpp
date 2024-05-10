#include "board-display.h"

#include "note-board-display.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMouseEvent>

BoardDisplay::BoardDisplay(QWidget *parent)
    : QWidget{parent}
{

    QPalette pal = QPalette();


    pal.setColor(QPalette::Window, Qt::gray);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->addButton = new QPushButton(this);
    connect(this->addButton, &QPushButton::clicked,this, &BoardDisplay::addNote);
}

BoardDisplay::~BoardDisplay(){
    for(auto noteDisp: notes){
        delete noteDisp;
    }
    notes.clear();
}



void BoardDisplay::addNote(){
    NoteBoardDisplay *note = new NoteBoardDisplay(this);
    notes.push_back(note);
    note->show();

}



void BoardDisplay::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton) {
        // Zapisanie pozycji myszy w momencie naciśnięcia prawego przycisku
        lastMousePosition = event->globalPosition().toPoint();
        isDragging=true;
        event->accept();
    } else {
        QWidget::mousePressEvent(event);
    }
}


void moveAllNotes(int dx,int dy,std::vector<NoteBoardDisplay*> notes){
    for(auto note: notes){
        note->moved(dx,dy);
    }
}

void BoardDisplay::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::RightButton && isDragging) {
        // Przesuwanie widgetu na podstawie różnicy pozycji myszy
        int dx = event->globalPosition().toPoint().x() - lastMousePosition.x();
        int dy = event->globalPosition().toPoint().y() - lastMousePosition.y();
        moveAllNotes(dx,dy,this->notes);
        lastMousePosition = event->globalPosition().toPoint();
        event->accept();
    } else {
        QWidget::mouseMoveEvent(event);
    }
}


void BoardDisplay::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton) {
        isDragging=false;
        event->accept();
    } else {
        QWidget::mouseReleaseEvent(event);
    }
}
