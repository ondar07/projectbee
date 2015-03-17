#include "egg.h"
#include <QPainter>
#include <QStyleOption>

#include <QTextStream> // для вывода всяких результатов в консоли

QTextStream Qcin2(stdin);
QTextStream Qcout2(stdout);

Egg::Egg()
{
    age = 0;
    angle = 0;
    type = -1; //потом установим
    place = QPoint(0,0);
    vsble = true; // если становится false,
                    // то eggList освободит ранее выделенную память под Egg

}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * *методы * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

int Egg::getAge() {
    return age;
}

qreal Egg::getAngle() {
    return angle;
}

// развитие яйца
void Egg::evolution() {
    if(type < 0)
        return;

    if(getAge() > 2) {
        //QObject::disconnect();
        //QObject::disconnect(&eggTimer, SIGNAL(timeout()), this, SLOT(evolution()));
        //eggTimer.stop();

        // 1) сделать невидимым
        vsble = false;
        setVisible(false);

        // 2) emit signal to Scene_t о создании пчел
        switch(type) {
        case 0: // если матка
            emit createQueen(place, cellNumber);
            break;
        case 1: // worker
            emit createWorker(place, cellNumber);
            break;
        case 2: // трутень
            emit createDrone(place, cellNumber);
        }

        // 3) послать сигнал eggList на уничтожение всех невидимых яиц
        emit killEggs();

        return; // !!!! иначе дальше обращение по освоб. указателю
    }
    age += 1;
    if(type == 2) { // если трутень
        angle += 30;
        setRotation(rotation()+30);
    } else {
        angle -= 30;
        setRotation(rotation()-30);
    }

}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * *рисование * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// область изображения
QRectF Egg::boundingRect() const
{
    qreal adjust = 0.5;

    return QRectF(QPoint(-6-adjust,-10-adjust), QSize(11,22));
}

void Egg::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
{
    p->setPen(QPen(QColor(240,225,225)));
    p->save();
    p->translate(QPointF(0,0));
    QRadialGradient gradient(0, 2, 15, 0, 50);
    gradient.setColorAt(0.8, Qt::white);
    gradient.setColorAt(0.3, QColor(240,225,225));
    p->setBrush(gradient);
    p->drawEllipse(QPointF(0,0), 5, 9);
    p->restore();
}
