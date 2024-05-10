#ifndef BOARDDISPLAY_H
#define BOARDDISPLAY_H

#include "note-board-display.h"

#include <QWidget>
#include<vector>
#include<QPushButton>


class BoardDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit BoardDisplay(QWidget *parent = nullptr);

    ~BoardDisplay();
public slots:
    void addNote();

protected:
    void mousePressEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool isDragging=false;
    QPoint lastMousePosition;
    std::vector<NoteBoardDisplay*> notes;
    QPushButton* addButton;
};

#endif // BOARDDISPLAY_H
