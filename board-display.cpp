#include "board-display.h"

#include "note-board-display.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

BoardDisplay::BoardDisplay(QWidget *parent)
    : QWidget{parent}
{

    QPalette pal = QPalette();


    pal.setColor(QPalette::Window, Qt::gray);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    NoteBoardDisplay *note = new NoteBoardDisplay(this);
    this->notes.push_back(note);

    // QHBoxLayout *hLayout = new QHBoxLayout(this);
    // QVBoxLayout *vLayout = new QVBoxLayout();
    // hLayout->addLayout(vLayout);
    // vLayout->addWidget(note);
    // this->setLayout(hLayout);
}

BoardDisplay::~BoardDisplay(){
    for(auto noteDisp: notes){
        delete noteDisp;
    }
    notes.clear();
}


void BoardDisplay::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::RightButton) {
        // Zapisanie pozycji myszy w momencie naciśnięcia prawego przycisku
        lastMousePosition = event->globalPosition().toPoint();
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
    if (event->buttons() & Qt::RightButton) {
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
        event->accept();
    } else {
        QWidget::mouseReleaseEvent(event);
    }
}

