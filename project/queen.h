#ifndef QUEEN_H
#define QUEEN_H

#include "bee.h"

class Queen : public Bee
{
public:
    //Queen();
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

};

#endif // QUEEN_H
