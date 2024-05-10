#include "note-board-display.h"
#include <QMouseEvent>



NoteBoardDisplay::NoteBoardDisplay(QWidget* parent): QWidget(parent) {
    this->resize(200, 200);
    this->move(50,50);
}

void NoteBoardDisplay::moved(int x, int y){
    int xPos=this->x(),
        yPos=this->y();
    this->move(xPos+x, yPos+y);
}

void NoteBoardDisplay:: paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);



    painter.setBrush(QColor(255, 191, 0));
    painter.setPen(Qt::NoPen); // Bez obramowania

    // Rysowanie zaokrąglonego prostokąta
    painter.drawRoundedRect(rect(), 20, 20);

    // Rysowanie czarnego paska na górze z przeźroczystością 0.5
    painter.setBrush(QColor(255, 255, 255, 127));
    painter.drawRoundedRect(QRectF(10,35,width()-20,155), 20, 20);
}



void NoteBoardDisplay::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton && event->pos().y() <= TOP_BAR_HEIGHT) {
        // Zapisanie pozycji myszy w momencie naciśnięcia prawego przycisku
        isDragging=true;
        lastMousePosition = event->globalPosition().toPoint();
        event->accept();
    } else if(event->button() == Qt::RightButton){
        event->accept();
    }
    else {
        QWidget::mousePressEvent(event);
    }
}



void NoteBoardDisplay::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton && isDragging) {
        // Przesuwanie widgetu na podstawie różnicy pozycji myszy
        int dx = event->globalPosition().toPoint().x() - lastMousePosition.x();
        int dy = event->globalPosition().toPoint().y() - lastMousePosition.y();
        moved(dx,dy);
        lastMousePosition = event->globalPosition().toPoint();
        event->accept();
    } else {
        QWidget::mouseMoveEvent(event);
    }
}


void NoteBoardDisplay::mouseReleaseEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton) {
        isDragging=false;
        event->accept();
    } else {
        QWidget::mouseReleaseEvent(event);
    }
}
