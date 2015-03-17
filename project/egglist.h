#ifndef EGGLIST_H
#define EGGLIST_H

#include <QObject>
#include <QList>
#include "egg.h"
#include <QTimer>

class EggList : public QObject
{
    Q_OBJECT

public:
    EggList();
    QTimer eggTimer;

public slots:

    void fromQueen(int countEggs, bool fertil, QPoint placeEmpCell, int cellNumb); // ответ на сигнал от матки
    void killEggs(); // яйца, которые стали невидимыми

    void createQueen(QPoint position, int cellNumb);     // слот-посредник.
    void createWorker(QPoint position, int cellNumb);    // дальше передаем сигнал Scene_t
    void createDrone(QPoint position, int cellNumb);

signals:
    void finished(); // будем посылать thread
    void toDrawEgg(Egg *egg); // to Scene_t
    //void error(QString err);

    void signCreateQueen(QPoint position, int cellNumb);     //
    void signCreateWorker(QPoint position, int cellNumb);    // передаем сигнал Scene_t
    void signCreateDrone(QPoint position, int cellNumb);

protected:
    QList <Egg *> * eggList;
};

#endif // EGGLIST_H
