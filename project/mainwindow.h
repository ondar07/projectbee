#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene_t.h"
#include <QToolBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//protected:
    Scene_t * scene;
private:
    QMenu *actionMenu;
    QAction *startAct;
    QAction *pauseAct;
    QToolBar *startStopToolBar;
    QGraphicsView *view;
    void createView();
    void createActions();
    void createToolBars();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
