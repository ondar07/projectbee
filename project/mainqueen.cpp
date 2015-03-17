#include "mainqueen.h"
#include <QTimer>
#include <math.h>

MainQueen::MainQueen()
{
    countEggsPerDay = 100;
    fertilized = false; // не оплодотв. (будет трутень)
    placeEmptyCell = QPoint(300,300);
}

// описание слота (реакция на сигнал о рождении матки)
void MainQueen::wasBornQueen() {
    // через секунду отправляем сигнал убить
    // (типа даем чуток пожить)
    QTimer::singleShot(1000, this,SLOT(emitSignalToKill()) );
}

// теперь убиваем
void MainQueen::emitSignalToKill() {
    emit killQueen();
}

void MainQueen::fromDrone() {
    setFertilized(true); // яйца оплодотворены (получим матку или рабочую пчелу)
    emit killDrone(); // отправляем сигнал scene_t
                        // чтобы убить Drone
}

void MainQueen::whatEmptyCell() {
    emit toBeehive();
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * *методы матки * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void MainQueen::setFertilized(bool fertil) {
    fertilized = fertil; // поменять значения после откладки ! ! !
}

// отложить яйца
// type - тип откладываемых яиц (если true, то оплодотвор., иначе false)
void MainQueen::layEggs(int numbEmpCell, QPoint placeEmpCell) {
    int countEggs = getCountEggs();
    bool type = getFertilized();

    if(numbEmpCell == 0) { // если нет своб. ячейки, то ничего не делаем
        return;
    }
    // отправим сигнал eggList
    emit toEggList(countEggs, type, placeEmpCell, numbEmpCell);

    // т.к. мы уже отложили яйца, то новые яйца не оплодотв.
    setFertilized(false);
    //
    // устанавим, куда надо матке лететь
    setPlaceEmptyCell(placeEmpCell);
}

// требуется модификация
void MainQueen::process() {
    ;
    //emit finished();
}

// установить, куда надо лететь, чтобы отложить яйца
void MainQueen::setPlaceEmptyCell(QPoint place) { // place - точка (координаты относит. СК сцены)

    // относительно координат Item
    //placeEmptyCell.setX(mapFromScene(place).rx());
    //placeEmptyCell.setY(mapFromScene(place).ry());

    //надо наверно использовать координаты сцены
    //все относительно сист. коорд. scene
    placeEmptyCell.setX(place.rx());
    placeEmptyCell.setY(place.ry());
}

QPoint MainQueen::getPlaceEmptyCell() {
    return placeEmptyCell;
}

int MainQueen::getCountEggs() {
    return countEggsPerDay;
}

bool MainQueen::getFertilized() {
    return fertilized;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
// переопределим движение
void MainQueen::advance(int step) {
    if(!step)
        return;

    /* движение к пустым клеткам */

    int dx, dy; // для движения
    dx = dy = 0; // чтобы если уже в окрестности
                 // то не двигаем
    int x, y; // координаты своб. ячейки
    x = getPlaceEmptyCell().rx();
    y = getPlaceEmptyCell().ry();

    // если клетка правее, чем пчела
    if(x>pos().rx()) {
        // теперь смотрим на разницу
        if((x-pos().rx()) >= 10) {
            dx = 5;
        } else {
            dx = 0;
        }
    } else {        // когда объект правее, чем клетка
        if((pos().rx()-x) >= 10) {
            dx = -5;
        } else {
            dx = 0;
        }
    }

    // теперь по y (ось y НАПРАВЛЕНА ВНИЗ)
    // когда объект выше (на экране), чем клетка
    // движемся вниз (т.е. расти по y)
    if(y>pos().ry()) {
        if((y-pos().ry()) >= 10) {
            dy = 5;
        } else {
            dy = 0;
        }
    } else {
    // когда объект ниже (по оси y), чем клетка
    // то мы должны подниматься вверх (т.е. опускаться по оси y)
        if((pos().ry()-y) >= 10) {
            dy = -5;
        } else {
            dy = 0;
        }
    }

    if(rotation()>=360 || rotation() <=-360)
        setRotation(0);
    /* добавим вращения голове (часть кода из мышей) */
    if (qrand() % 1) {
        angle += (qrand() % 100) / 1000.0;
    } else {
        angle -= (qrand() % 100) / 1000.0;
    }
    qreal dx_head = ::sin(angle) * 4;
    setRotation(rotation() + dx_head);
    // двигаем пчелу к клетке до тех пор, пока не попадем в "окрестность" своб. клетки
    setPos(pos()+QPoint(dx, dy));
}
