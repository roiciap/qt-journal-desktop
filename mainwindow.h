#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "menu-widget.h"
#include "board-display.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    BoardDisplay *board;
    QStackedWidget *displayTarget;
    MenuWidget *menu;
    QWidget *mainWidget;

};
#endif // MAINWINDOW_H
