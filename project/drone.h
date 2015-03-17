#ifndef DRONE_H
#define DRONE_H

#include "bee.h"
#include <QTimer>

class Drone : public Bee
{
    Q_OBJECT

public:
    Drone();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    // методы трутня
    int getHealth();
    bool getFertilized();

    void setHealth(int n);
    void setFertilized(bool state);

public slots:
    void updateAge();

signals:
    void signalFromDrone(); // будем отправлять Scene_t
                            // после 15 дней жизни посылают данный сигнал


private:
    int health; // в процентах от 0 до 100 (сытость)
                // надо будет сигналы/методы с рабочей пчелой написать
                // когда они начнут морить голодом (ближе к осени), будем минусовать health
                // если health станет <=0, то убиваем
    bool fertilized; // если true, то оплодотворил
                     // понадобится, когда на сигнал от матки
                     // в droneList в scene_t пройтись по списку
                     // найти трутней с true значением и мочить их
};

#endif // DRONE_H
