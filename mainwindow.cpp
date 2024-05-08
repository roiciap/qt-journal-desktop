#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHBoxLayout>


MainWindowWidgets* initializeMainWidgets(){
// initialize main widget
    QWidget  *mainWidget = new QWidget();
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, Qt::darkGray);

    mainWidget->setAutoFillBackground(true);
    mainWidget->setPalette(pal);

    BoardDisplay *board = new BoardDisplay();
    MenuWidget *menu = new MenuWidget(mainWidget);
    QStackedWidget *displayTarget = new QStackedWidget(mainWidget);

    QHBoxLayout *hLayout = new QHBoxLayout(mainWidget);
    mainWidget->setLayout(hLayout);
    // create current display target
    hLayout->addWidget(displayTarget);
    hLayout->setStretchFactor(displayTarget, 1);


    displayTarget->addWidget(board);
    displayTarget->setCurrentIndex(0);

    hLayout->addWidget(menu);

    return new MainWindowWidgets{
        mainWidget=mainWidget,
        menu=menu,
        displayTarget=displayTarget,
        board=board
    };
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // QVBoxLayout *vLayout = new QVBoxLayout();

    this->widgets = initializeMainWidgets();


    this->setCentralWidget(this->widgets->mainWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete widgets;
}
