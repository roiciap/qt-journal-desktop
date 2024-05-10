#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindowWidgets* initializeMainWidgets(){
// initialize main widget


    // BoardDisplay *board = new BoardDisplay();
    // ScrollDisplay* scroll = new ScrollDisplay();
    MenuWidget *menu = new MenuWidget();
    DisplaySwitch *displayTarget = new DisplaySwitch();
    // displayTarget->setTargetAndClear(board);
    MainWidget  *mainWidget = new MainWidget(menu, displayTarget);

    return new MainWindowWidgets{
        mainWidget=mainWidget,
        menu=menu,
        displayTarget=displayTarget
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QVBoxLayout *vLayout = new QVBoxLayout();
    // this->resize(500,500);
    this->widgets = initializeMainWidgets();
    this->setCentralWidget(this->widgets->mainWidget);
}


MainWindow::~MainWindow()
{
    // delete ui;
    delete widgets;
}
