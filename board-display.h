#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H

#include <QWidget>
#include "note-board-display.h"
#include<vector>

class BoardDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit BoardDisplay(QWidget *parent = nullptr);

    ~BoardDisplay();
protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QPoint lastMousePosition;
    std::vector<NoteBoardDisplay*> notes;
};

#endif // BOARDDISPLAY_H
