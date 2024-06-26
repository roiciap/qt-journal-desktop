#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "main-widget.h"
#include "menu-widget.h"
// #include "board_display/board-display.h"
#include "display-switch.h"
// #include "scroll_display/scroll-display.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE



struct MainWindowWidgets {
    MainWidget  *mainWidget;
    MenuWidget *menu;
    DisplaySwitch *displayTarget;
    // BoardDisplay *board;
    // ScrollDisplay *scroll;

    ~MainWindowWidgets(){
        delete this->mainWidget;
        delete this->menu;
        delete this->displayTarget;
    }
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MainWindowWidgets *widgets;
};
#endif // MAINWINDOW_H
