#ifndef MAINQUEEN_H
#define MAINQUEEN_H

#include "queen.h"

class MainQueen : public Queen
{
    Q_OBJECT

public:
    MainQueen();

    QPoint getPlaceEmptyCell();
    void setPlaceEmptyCell(QPoint place);
    void setFertilized(bool state);

public slots:
    void process(); // ответ на сигнал от thread
    void layEggs(int numbEmpCell, QPoint placeEmpCell);
    void wasBornQueen(); // обработка сигнала от scene_t
                    // о рождении новой матки
    void emitSignalToKill(); // этот слот -- костыль
                            // нужен, чтобы сделать паузу в 1 сек
                            // и испустить сигнал
    void fromDrone(); // реакция на трутня (сигнал приходит от Scene_t)

    void whatEmptyCell(); // в этом слоте будем отправлять сигнал beehive
                        // чтобы узнать номер своб. ячейки и координаты
signals:
    void killQueen(); // будем отправлять Scene_t
                        // убивать маток
    void killDrone(); // to Scene_t
    void toEggList(int countEggs, bool fertil, QPoint placeEmpCell, int numberCell);
    void toBeehive(); // будем отправлять beehive, чтобы узнать номер своб. ячейки и координаты центра
    void finished();

protected:
    void advance(int step);

    int getCountEggs(); // будем только из матки вызывать
    bool getFertilized();

private:
    QPoint placeEmptyCell; // куда надо лететь, чтобы отложить яйца
                            // координаты относительно СК scene
    int countEggsPerDay; // в идеале в зависимости от температуры оно будет меняться
    bool fertilized; // оплодотворены ли яйца ?
};

#endif // MAINQUEEN_H
