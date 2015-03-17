#ifndef HONEY_H
#define HONEY_H

#include <QGraphicsObject>

class Honey : public QGraphicsObject
{
    Q_OBJECT

public:
    Honey();
    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);
};

#endif // HONEY_H
