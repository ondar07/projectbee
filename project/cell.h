#ifndef CELL_H
#define CELL_H

#include <QGraphicsItem>

class Cell : public QGraphicsItem
{
public:
    Cell();


    QRectF boundingRect() const;

    //QPainterPath shape() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    int getState();
    void setState(int n);
    bool isEmpty(); // проверка, является ли ячейка пустой.
                   // возвращает true, если пустая
                   // иначе false

    void setCenterCoord(qreal x, qreal y); //установить координаты центра ячейки
    QPoint getCenterCoord(); // получить координаты центра

private:
    int state; //состояние (0-свободно, 1-занято)

    QColor color;
    QPoint centerCoord; // центр клетки (будем здесь хранить координаты)
                    // чтобы матка добралась до нее и отложила яйца
};

#endif // CELL_H
