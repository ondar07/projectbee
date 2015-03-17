#ifndef WORKER_H
#define WORKER_H

#include "bee.h"

class Worker : public Bee
{
public:
    //worker();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

signals:
    void getHoney(); // слот на данный сигнал будет у scene_t
                    // (реакция улья)
};

#endif // WORKER_H
