#ifndef BEE_H
#define BEE_H

#include <QGraphicsItem>
#include <QTimer>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

class Bee : public QGraphicsObject
{
    Q_OBJECT

public:
    Bee();
    int getAge();
    qreal getAngle();

public slots:
    void updateAge();

protected:
    void advance(int step); // здесь зададим рандомности движения (из мышей)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    qreal angle; // угол, под которым она повернута относительно вертикальной оси (куда голова пчелы повернута)
    qreal speed; // скорость перемещения
    int age; // возраст
};
#endif // BEE_H
