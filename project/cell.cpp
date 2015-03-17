#include "cell.h"

//#include <QGraphicsScene>
#include <QPainter>
#include <QStyleOption>

static qreal h = 20;
static qreal mh = h/2.0;

Cell::Cell()
      : color(Qt::yellow)
{
    state = 0;
}

// получить состояние
int Cell::getState() {
    return state;
}

// установить состояние для клетки (0 - свободно, 1 - занято)
void Cell::setState(int n) {
    state = n;
}

// пустая ли? true, если пустая
// иначе false
bool Cell::isEmpty() {
    if(state==0) {
        return true;
    } else {
        return false;
    }
}


// установить координаты центра ячейки
void Cell::setCenterCoord(qreal x, qreal y) {
    centerCoord.setX(x);
    centerCoord.setY(y);
}

// получить координаты центра ячейки
QPoint Cell::getCenterCoord() {
    return centerCoord;
}

QRectF Cell::boundingRect() const
{
    qreal adjust = 0.5;
    qreal x = (1.7/2.0)*h;
    return QRectF(QPoint(-x-adjust,h-adjust), QSize(2*x+adjust, 2*h+adjust));
}

void Cell::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
{
    //p->scale(4.0,4.0); // увеличить размер в 2 раза
    p->setPen(QPen(QColor(255,196,57)));

    QRadialGradient gradient(7, 7, 40, -30, -20);
    gradient.setColorAt(0.5, Qt::yellow);
    gradient.setColorAt(0.3, QColor(255,205,0));
     gradient.setColorAt(0.8, QColor(252,211,8));
    qreal x = (1.7/2.0)*h;
    p->setBrush(gradient);
    QPolygon polygon;
    polygon << QPoint(-x, mh) << QPoint(0, h)
        << QPoint(x, mh)  << QPoint(x,-mh)
        << QPoint(0, -h) << QPoint(-x, -mh);
    p->drawPolygon(polygon);
}

