#ifndef SCENE_T_H
#define SCENE_T_H

#include <QGraphicsScene>
#include <QtMultimedia>
#include <QString>
#include <QTimer>
#include "queen.h"
#include "drone.h"
#include "egg.h"
#include "worker.h"
#include "beehive.h"
#include "queen.h"
#include "mainqueen.h"
#include "egglist.h"
#include "honey.h"
#include <QSpinBox>

class Scene_t: public QGraphicsScene
{
    Q_OBJECT
    
public:
    Scene_t();
    Beehive *beehive;
    MainQueen *queen;
    QTimer timerForLayEggs;
    QTimer timerUpdate;
    QTimer timerUpdateScene;
    EggList * eglist;
    QThread* threadDrones;
    QThread* threadWorkers;
    QSpinBox *honeyBox;
    void addSound(QString path);

public slots:
    void createQueen(QPoint position, int cellNumb);        //создание матки
    void createDrone(QPoint position, int cellNumb);        // (position - где появится на сцене)
    void createWorker(QPoint position, int cellNumb);

    void collectHoney();
    void startTimers();
    void stopTimers();
    void killAllDrones();
    void killAllWorkers();
    void forDrone();        // слот для сигнала от трутня
    void update_bees();        //обновляет всё, связанное с пчёлками; пока - только убивает мёртвых
    void killQueen();         // если приходит сигнал от главной матки, то убиваем
    void killDrone();       // будем убивать трутней, у которых fertilized == true
    void drawEggs(Egg * egg); // слот на сигнал от EggList (добавить на сцену)
    void getHoney(); // будем изображать на сцене мед (сигнал получаем от worker)

signals:
    void wasBornQueen(); // при рождении матки посылаем сигнал главной матке
                    // чтобы она убила эту матку
    void queenWasFertilized(); // отправим данный сигнал, когда получим сигнал от трутня
                            // в описании слота forDrone()
    void toBeehive(int cellNumb);

protected:
    void initialiseTimers();
    void createConnections();
    QList <Queen *> queenList; //здесь хранятся ссылки на маток
    QList <Worker *> workerList;
    QList <Drone *> droneList;
    QList <Honey *> honeyList;
    QTimer sceneTimerForBees;
};

#endif // SCENE_T_H
