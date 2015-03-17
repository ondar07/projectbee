#include "mainwindow.h"
#include <QtWidgets>
#include "scene_t.h"
#include <QThread>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    //Scene_t *scene = new Scene_t();
    QString sound_path = "/home/ondar/mySound.wav";


    w.scene->addSound(sound_path);

    w.scene->beehive->draw_cells(w.scene);

    w.scene->queen->setPos(300,300);
    w.scene->addItem(w.scene->queen);

    QThread* threadQueen = new QThread;
    w.scene->queen->moveToThread(threadQueen);


    QObject::connect(threadQueen, SIGNAL(started()),  w.scene->queen, SLOT(process()));
    QObject::connect( w.scene->queen, SIGNAL(finished()), threadQueen, SLOT(quit()));
    QObject::connect( w.scene->queen, SIGNAL(finished()),  w.scene->queen, SLOT(deleteLater()));
    QObject::connect(threadQueen, SIGNAL(finished()), threadQueen, SLOT(deleteLater()));
    threadQueen->start();

    w.show();
    return app.exec();
}
