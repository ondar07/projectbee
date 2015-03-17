#include "egglist.h"
#include <cstdlib>
#include <QTextStream> // для вывода всяких результатов в консоли

QTextStream Qcin3(stdin);
QTextStream Qcout3(stdout);

EggList::EggList()
{
    eggList = new QList <Egg *>;
}

// тип: 0 - матка, 1 - рабочая пчела, 2 - трутень
static int eggType(bool fertil) {
    if(fertil == false) { // если неоплод., то рождаются трутни
        return 2;
    }
    int chance; // вероятность рождения матки - 30%
                // вероятность рождения рабочей пчелы - 70%
    qsrand(time(NULL));
    chance=qrand() % 100;

    if(chance <= 70)
        return 1;
    else
        return 0;
}

// добавление элементов (ответ на сигнал от матки)
// cellNumb - порядковый номер ячейки в beehive
// будем отправлять beehive, чтобы улей поставил состояние state = 0
// после того, как яйцо освободит ячейку
void EggList::fromQueen(int countEggs, bool fertil, QPoint placeEmpCell, int cellNumb) {
    Egg *egg = new Egg;
    egg->type = eggType(fertil); //
    egg->place = placeEmpCell; // установим параметры
    egg->cellNumber = cellNumb; //
    QObject::connect(&(eggTimer),SIGNAL(timeout()), egg, SLOT(evolution()) );

    eggList->append(egg);

    QObject::connect(egg, SIGNAL(killEggs()), this, SLOT(killEggs()));

    // соединим сигналами и слотами объекты классов egg и eggList(this)
    QObject::connect(egg, SIGNAL(createQueen(QPoint, int)), this, SLOT(createQueen(QPoint, int)));
    QObject::connect(egg, SIGNAL(createDrone(QPoint, int)), this, SLOT(createDrone(QPoint, int)));
    QObject::connect(egg, SIGNAL(createWorker(QPoint, int)), this, SLOT(createWorker(QPoint, int)));

    emit toDrawEgg(egg); // пошлем сигнал Scene_t, чтобы она нарисовала яйцо
}

// освобождение памяти по тем элементам, которые невидимые
void EggList::killEggs() {

    for(int i = 0; i < this->eggList->size(); i++) {
        if(eggList->at(i)->vsble == false)
            delete eggList->takeAt(i);
    }

}

// слоты-посредники.
/* ***************************************** */
void EggList::createQueen(QPoint position, int cellNumb) {
    emit signCreateQueen(position, cellNumb);
}

void EggList::createWorker(QPoint position, int cellNumb) {
    emit signCreateWorker(position, cellNumb);
}

void EggList::createDrone(QPoint position, int cellNumb) {
    emit signCreateDrone(position, cellNumb);
}
/* ***************************************** */
