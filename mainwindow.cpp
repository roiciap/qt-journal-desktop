#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QHBoxLayout>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    // QVBoxLayout *vLayout = new QVBoxLayout();

    this->mainWidget = new QWidget(this);



    // create Board
    this->board = new BoardDisplay(mainWidget);

    // create current display target

    this->displayTarget = new QStackedWidget(this);
    hLayout->addWidget(this->displayTarget);
    hLayout->setStretchFactor(this->displayTarget, 1);


    displayTarget->addWidget(this->board);
    displayTarget->setCurrentIndex(0);
    // ADD MENU
    this->menu = new MenuWidget(this->mainWidget);
    hLayout->addWidget(this->menu);


    mainWidget->setLayout(hLayout);
    this->setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete board;
}
