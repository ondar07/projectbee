#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene_t;
    QPushButton *buttonExit = new QPushButton("Kill drones");
    //scene->addWidget(buttonExit);
    QPushButton *buttonEx = new QPushButton("Kill workers");
    QPushButton *buttonHoney = new QPushButton("Collect honey");
    //scene->addWidget(buttonEx);
    QObject::connect(buttonExit, SIGNAL(clicked()), scene, SLOT(killAllDrones()));
    QObject::connect(buttonEx, SIGNAL(clicked()), scene, SLOT(killAllWorkers()));
    QObject::connect(buttonHoney, SIGNAL(clicked()), scene, SLOT(collectHoney()));
    scene->honeyBox->setValue(0);
    scene->honeyBox->setSingleStep(0);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(buttonEx);
    layout->addWidget(buttonExit);
    layout->addWidget(buttonHoney);
    layout->addWidget(scene->honeyBox);
    QWidget *window = new QWidget();
    window->setLayout(layout);
    scene->addWidget(window);

    createActions();
    //window->show();

    createView();

    setCentralWidget(view);

    setUnifiedTitleAndToolBarOnMac(true);
}

void MainWindow::createActions()
{
    startAct = new QAction(QIcon(":/images/start.png"), tr("&Start"), this);
    connect(startAct, SIGNAL(triggered()), scene, SLOT(startTimers()));
    pauseAct = new QAction(QIcon(":/images/pause.png"), tr("&Pause"), this);
    connect(pauseAct, SIGNAL(triggered()), scene, SLOT(stopTimers()));
    //startStopToolBar = addToolBar(tr("Start"));
    //startStopToolBar->addAction(startAct);
    //startStopToolBar->addAction(pauseAct);
    actionMenu = menuBar()->addMenu(tr("&File"));
    actionMenu->addAction(startAct);
    actionMenu->addAction(pauseAct);
}

void MainWindow::createView()
{
    view = new QGraphicsView(this);
    view->setScene(scene);
    view->setRenderHint(QPainter::Antialiasing);
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Моделирование жизни пчелиного улья"));
    view->resize(705, 705);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
