#include "honey.h"
#include <QPainter>
#include <QStyleOption>

Honey::Honey() {

}

QRectF Honey::boundingRect() const {
    qreal adjust = 0.5;

    return QRectF(QPoint(-6-adjust,-10-adjust), QSize(11,22));
}

void Honey::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *) {
    p->save();
    p->translate(QPointF(0,0));

    QRadialGradient gradient(QPointF(0,0), 10, QPointF(0,0));
    gradient.setColorAt(0, QColor(255, 247, 0)); // надо более точно подобрать
    gradient.setColorAt(1, QColor(250, 185, 80)); // цвета для градиента

    p->setBrush(QBrush(gradient));
    p->setPen(Qt::NoPen); // чтобы отсутствовал граничный контур
    p->drawEllipse(QPointF(0,0), 10, 10);
    p->restore();
}
