#include "scene_t.h"

static const int QUEEN_MAX_AGE = 60;
static const int WORKER_MAX_AGE = 60;

Scene_t::Scene_t() {
    setSceneRect(0, 0, 700, 700); //размер 700 x 700
    beehive = new Beehive;
    queen = new MainQueen;
    eglist = new EggList();
    threadDrones = new QThread;
    threadWorkers = new QThread;
    initialiseTimers();
    createConnections();
    startTimers();
    stopTimers();
    startTimers();
    setItemIndexMethod(QGraphicsScene::NoIndex);
    honeyBox = new QSpinBox();
    sceneTimerForBees.start(1000/33); // чтобы пчелы двигались
    threadWorkers->start();
    threadDrones->start();
}

void Scene_t::addSound(QString path)
{
    QMediaPlayer *player = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(100);
    player->play();
}

void Scene_t::initialiseTimers()
{
    QObject::connect(&timerForLayEggs, SIGNAL(timeout()),  queen, SLOT(whatEmptyCell())); // каждую секунду будем вызывать этот слот
    QObject::connect(queen, SIGNAL(toBeehive()),  beehive, SLOT(whatEmptyCell())); // beehive вернет пустую ячейку
    QObject::connect(beehive, SIGNAL(toMainQueen(int,QPoint)), queen, SLOT(layEggs(int,QPoint)));
    timerUpdateScene.start(1000/333);
}

void Scene_t::createConnections()
{
    QObject::connect(queen, SIGNAL(toEggList(int,bool,QPoint,int)), eglist, SLOT(fromQueen(int,bool,QPoint,int)));
    QObject::connect(eglist, SIGNAL(toDrawEgg(Egg*)), this, SLOT(drawEggs(Egg*)));
    QObject::connect(eglist, SIGNAL(signCreateQueen(QPoint, int)),this, SLOT(createQueen(QPoint,int)));
    QObject::connect(eglist, SIGNAL(signCreateDrone(QPoint, int)), this, SLOT(createDrone(QPoint, int)));
    QObject::connect(eglist, SIGNAL(signCreateWorker(QPoint, int)), this, SLOT(createWorker(QPoint, int)));
    QObject::connect(this, SIGNAL(toBeehive(int)), beehive, SLOT(cleaningCell(int)));
    QObject::connect(&timerUpdate, SIGNAL(timeout()), this, SLOT(advance()));
    QObject::connect(&timerUpdateScene, SIGNAL(timeout()), this, SLOT(update()));
    QObject::connect(&timerUpdate, SIGNAL(timeout()), this, SLOT(update_bees()));
    // соединим сигналами и слотами главную матку(queen) и scene
    QObject::connect(this, SIGNAL(wasBornQueen()),  queen, SLOT(wasBornQueen()) );
    QObject::connect(queen, SIGNAL(killQueen()), this, SLOT(killQueen()) );
    // оплодотворение
    QObject::connect(this, SIGNAL(queenWasFertilized()), queen, SLOT(fromDrone()));
    QObject::connect(queen, SIGNAL(killDrone()), this, SLOT(killDrone()));
}


void Scene_t::startTimers()
{
    timerUpdate.start(1000/333);
    timerForLayEggs.start(1000);
    eglist->eggTimer.start(1000);
}

void Scene_t::stopTimers()
{
    timerUpdate.stop();
    timerForLayEggs.stop();
    eglist->eggTimer.stop();
}


void Scene_t::createQueen(QPoint position, int cellNumb) {
    Queen *queen = new Queen;
    queenList.append(queen); // добавим в конец списка
    queen->setPos(position);
    Scene_t::addItem(queen);
    queen->setScale(0.8); // пусть так будет (типа, они мелкие при рождении)
    emit wasBornQueen(); // испускаем сигнал, что родилась новая матка
    QObject::connect(&sceneTimerForBees, SIGNAL(timeout()), queen, SLOT(advance()));

    // отправим beehive сигнал, чтобы освободить ячейку
    emit toBeehive(cellNumb);
}

void Scene_t::createDrone(QPoint position, int cellNumb) {
    Drone *drone = new Drone;
    droneList.append(drone); // добавим в конец списка
    drone->moveToThread(threadDrones);
    QObject::connect(threadDrones, SIGNAL(started()),  drone, SLOT(process()));
    QObject::connect( drone, SIGNAL(finished()), threadDrones, SLOT(quit()));
    QObject::connect( drone, SIGNAL(finished()),  drone, SLOT(deleteLater()));
    QObject::connect(threadDrones, SIGNAL(finished()), threadDrones, SLOT(deleteLater()));
    drone->setPos(position);
    Scene_t::addItem(drone);
    // данное соединение используется при операциях оплодотворения
    QObject::connect(drone, SIGNAL(signalFromDrone()), this, SLOT(forDrone()) );
    QObject::connect(&sceneTimerForBees, SIGNAL(timeout()), drone, SLOT(advance()));

    // отправим beehive сигнал, чтобы освободить ячейку
    emit toBeehive(cellNumb);

}

void Scene_t::createWorker(QPoint position, int cellNumb) {
    Worker *worker = new Worker;
    workerList.append(worker); // добавим в конец списка
    worker->moveToThread(threadWorkers);
    QObject::connect(threadWorkers, SIGNAL(started()),  worker, SLOT(process()));
    QObject::connect( worker, SIGNAL(finished()), threadWorkers, SLOT(quit()));
    QObject::connect( worker, SIGNAL(finished()),  worker, SLOT(deleteLater()));
    QObject::connect(threadWorkers, SIGNAL(finished()), threadWorkers, SLOT(deleteLater()));
    worker->setPos(position);
    Scene_t::addItem(worker);
    QObject::connect(&sceneTimerForBees, SIGNAL(timeout()), worker, SLOT(advance()));
    QObject::connect(worker, SIGNAL(getHoney()), this, SLOT(getHoney()));

    emit getHoney(); // пока что каждая рабочая пчела при рождении отправляет сигнал
                    // и в улье появляется элементик меда
    // отправим beehive сигнал, чтобы освободить ячейку
    emit toBeehive(cellNumb);
}

// слот на сигнал killQueen, который приходит от главной матки
void Scene_t::killQueen() {
    if(!queenList.isEmpty()) {
        int i;
        i = queenList.size()-1;                 // номер последней пчелы
        queenList.at(i)->setVisible(false);
        queenList.removeAt(i); //удаляем
    }
}

// слот на сигнал killDrone, который приходит от главной матки
void Scene_t::killDrone() {
    for(int i = 0; i < droneList.size(); i++) {
        if(droneList.at(i)->getFertilized()) { // если спаривался, kill
            droneList.at(i)->setVisible(false);
            delete droneList.takeAt(i);
        }
    }
}


void Scene_t::collectHoney()
{
    int val = honeyBox->value();
    for(int i = 0; i < honeyList.size(); i++) {
        if (honeyList.at(i)!= NULL)
            val++;
        honeyList.at(i)->setVisible(false);
        delete honeyList.takeAt(i);
    }
    honeyBox->setValue(val);
}


void Scene_t::killAllDrones() {
    for(int i = 0; i < droneList.size(); i++) {
        droneList.at(i)->setVisible(false);
        delete droneList.takeAt(i);
    }
}


void Scene_t::killAllWorkers() {
    for(int i = 0; i < workerList.size(); i++) {
        workerList.at(i)->setVisible(false);
        delete workerList.takeAt(i);
    }
}


// слот-реакция на сигнал от трутня
void Scene_t::forDrone() {
    emit queenWasFertilized();
}

// реакция на сигнал от EggList
// нарисовать яйцо на сцене
void Scene_t::drawEggs(Egg * egg) {
    QPoint place;
    place = egg->place;
    egg->setPos(place);
    addItem(egg);
}

// та-даан! мед на вьюшке
void Scene_t::getHoney() {
    int numbCellForHoney;

    numbCellForHoney = this->beehive->getNumbEmptyCellForHoney();

    if(numbCellForHoney == -1) {
        return;
    }
    this->beehive->cellList[numbCellForHoney]->setState(1); // занято
    // находим место
    QPoint place;
    place = this->beehive->cellList[numbCellForHoney]->getCenterCoord();
    // создать элемент, добавить honeyList
    Honey *honey = new Honey;
    honey->setPos(place);
    this->honeyList.append(honey);
    this->addItem(honey);
}

void Scene_t::update_bees()
{
     for (int i = 0; i < queenList.size(); i++){
         if (queenList.at(i)->getAge() > QUEEN_MAX_AGE){    //проверяем возраст
             queenList.at(i)->setVisible(false);
             delete queenList.takeAt(i);           //БАБАХ! и пчёлки нет;
         }
     }
     for(int i = 0; i< workerList.size(); i++) {
         if(workerList.at(i)->getAge() > WORKER_MAX_AGE) {
             workerList.at(i)->setVisible(false);
             delete workerList.takeAt(i);
         }
     }
}
