#ifndef MENUWIDGET_H
#define MENUWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "board_display/board-display.h"
#include "scroll_display/scroll-display.h"

class MenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuWidget(QWidget *parent = nullptr);
signals:
    void buttonLeftClick(QWidget *displayWidget);

private:
    QPushButton* buttonScroll;
    QPushButton* buttonBoard;

private slots:
    void buttonPressed(){
        QPushButton *senderButton = qobject_cast<QPushButton*>(sender());
        if (senderButton) {
            if (senderButton == buttonScroll) {
                emit buttonLeftClick(new ScrollDisplay());
            } else if (senderButton == buttonBoard) {
                emit buttonLeftClick(new BoardDisplay());
            }
        }
    }
};

#endif // MENUWIDGET_H
