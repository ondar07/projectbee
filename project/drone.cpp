#include "drone.h"
#include <QPainter>
#include <QStyleOption>


Drone::Drone()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAge()));
    timer->start(1000 * 1); // через 1 сек, age будет увеличиваться на 5
    fertilized = false; // вначале, конечно, он не оплодотворил
    health = 20; // при рождении
}

void Drone::updateAge() {
    age += 5;
    if(age>15) {
        setFertilized(true); // теперь scene_t его замочит
        emit signalFromDrone();
    }
}

/*  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * *методы трутня* * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int Drone::getHealth() {
    return health;
}

bool Drone::getFertilized() {
    return fertilized;
}

void Drone::setHealth(int n) {
    health = n;
}

// true, если оплодотворил
void Drone::setFertilized(bool state) {
    fertilized = state;
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * *рисование * * * * * * * * * * * * * * * * * * * * * * * *
 *  * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// область изображения пчелки
// над точными размерами еще не задумывался
// здесь очень грубо
// если взять малую область, то при вращении, будет вращаться только выбранная часть
QRectF Drone::boundingRect() const
{
    qreal adjust = 0.5;

    return QRectF(QPoint(-25-adjust,-25-adjust), QSize(50,88));
}


/* функция рисования крыльев пчелы */
// данные функции static, т.к. при собирании
// ругается линкер (т.к. данная функция используется
// и в queen.cpp, drone.cpp, worker.cpp
static void dr_cr(QPainter *p, QPointF point, int angle) {

     // крылья
     // левое
    p->save();
    p->translate(point); // перемещаем начало координат в эту точку
    p->setBrush(Qt::gray);
    p->rotate(angle); // поворачиваем СК
    if(angle<0) { // левое
        p->drawEllipse(QPointF(-70,-3), 65, 12);
    } else {
        p->drawEllipse(QPointF(70,-3), 65, 12);
    }
    p->restore();

}

void Drone::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
{
        p->scale(0.175, 0.175); //уменьшить размер пчелы в 2 раза
    /* Усы */
    QPainterPath path(QPointF(-10,-25)); // левое
    path.cubicTo(QPointF(-10,-35), QPointF(-15,-25), QPointF(-35,-40));
    p->setBrush(Qt::NoBrush);
    p->drawPath(path);

    path.moveTo(10,-25); // правое
    path.cubicTo(QPointF(10,-35), QPointF(15,-25), QPointF(35,-40));
    p->setBrush(QColor(206,206,187));
    p->drawPath(path);

    /* конечности */
    p->save();  // меняем кисть, поэтому сохраним исходное значение параметров
    QPen pen(Qt::black, 4); // устанавливаем ширину пера
    p->setPen(pen);

    p->drawLine(QPointF(0,40), QPointF(-50,25)); // левое верхнее
    p->drawLine(QPointF(-50,25), QPointF(-65,0));
    p->drawLine(QPointF(0,40), QPointF(50,25)); // правое верхнее
    p->drawLine(QPointF(50,25), QPointF(65,0));

    p->drawLine(QPointF(0,50), QPointF(-50,52)); // med left
    p->drawLine(QPointF(-50,52), QPointF(-75,85));

    p->drawLine(QPointF(0,50), QPointF(50,52)); // med right
    p->drawLine(QPointF(50,52), QPointF(75,85));

    p->drawLine(QPointF(0,54), QPointF(-40,58)); // low left
    p->drawLine(QPointF(-40,58), QPointF(-50,65));
    p->drawLine(QPointF(-50,65), QPointF(-70,125));

    p->drawLine(QPointF(0,54), QPointF(40,58)); // low right
    p->drawLine(QPointF(40,58), QPointF(50,65));
    p->drawLine(QPointF(50,65), QPointF(70,125));

    p->restore();   // возвращаем исходное значение параметров


    // голова
    p->setBrush(QColor(245,215,60));
    p->drawEllipse(QPointF(0,0),27,27);

    /* глаза (тоже можно в отдельную функцию можно вынести)*/
    // левый
    p->save();
    p->translate(QPointF(-15,-15)); // перемещаем начало координат в эту точку
    p->rotate(-45);
    p->setBrush(QColor(100,50,0));
    p->drawEllipse(QPointF(0,0), 17, 7);
    p->restore();

    // правый
    p->save();
    p->translate(QPointF(15,-15)); // перемещаем начало координат в эту точку
    p->rotate(45); // вращаем систему координат
    p->setBrush(QColor(100,50,0));
    p->drawEllipse(QPointF(0,0), 17, 7);
    p->restore();

    // туловище
    QLinearGradient linearGrad(QPointF(0, 150), QPointF(0, 165));
        linearGrad.setColorAt(0, QColor(225,180,0));
        linearGrad.setColorAt(1, QColor(210,170,0));
    p->setBrush(linearGrad);
    p->drawEllipse(QPointF(0,45),28,28);

    // брюхо
    p->setBrush(linearGrad);
    p->drawEllipse(QPointF(0,115),30,70);

    // нарисуем черные эллипсы на брюхе
    // med
    //QPainterPath path;
    path.addEllipse(QPointF(0,115), 30, 10);
    QLinearGradient linearGrad1(QPointF(0, -5), QPointF(0, 5));
    linearGrad1.setColorAt(0, QColor(110,55,0));
    linearGrad1.setColorAt(1, QColor(135,70,0));
    p->setBrush(linearGrad1);
    p->drawPath(path);

    //top
    path.addEllipse(QPointF(0,85), 27, 8);
    p->setBrush(linearGrad1);
    p->drawPath(path);

    //low
    path.addEllipse(QPointF(0,145), 27, 8);
    p->setBrush(linearGrad1);
    p->drawPath(path);

    // рисуем крылья
    dr_cr(p, QPointF(-10, 35), -65); // левое
    dr_cr(p, QPointF(10, 35), 65); // правое

}
