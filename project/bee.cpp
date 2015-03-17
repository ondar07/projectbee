#include "bee.h"
//#include <QTextStream> // для вывода всяких результатов в консоли
#include <QTimer>
#include <math.h>

//QTextStream Qcin1(stdin);
//QTextStream Qcout1(stdout);


Bee::Bee() {
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateAge()));
    timer->start(1000 * 1); // через 1 сек, age будет увеличиваться на 10
    angle = 0; // угол поворота (т.е. куда она повернута в данный момент)
    age = 0;
    speed = 0.0;
    setHandlesChildEvents(true);
}

void Bee::updateAge() {
    age += 7;
}


int Bee::getAge() {
    return age;
}

qreal Bee::getAngle() {
    return angle;
}

static const double Pi = 3.14159265358979323846264338327950288419717;
static double TwoPi = 2.0 * Pi;

static qreal normalizeAngle(qreal angle)
{
    while (angle < 0)
        angle += TwoPi;
    while (angle > TwoPi)
        angle -= TwoPi;
    return angle;
}

void Bee::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        // handle left mouse button here
        age += 1000000;
    } else {
        // pass on other buttons to base class
    }
}


void Bee::advance(int step)
{
    if (!step)
        return;

    QLineF lineToCenter(QPointF(0, 0), mapFromScene(250, 350)); // в окрестности точки (250,250) будет происходит движение
    if (lineToCenter.length() > 150) { // в радиусе 250
        qreal angleToCenter = ::acos(lineToCenter.dx() / lineToCenter.length());
        if (lineToCenter.dy() < 0)
            angleToCenter = TwoPi - angleToCenter;
        angleToCenter = normalizeAngle((Pi - angleToCenter) + Pi / 2);

        if (angleToCenter < Pi && angleToCenter > Pi / 4) {
            // Rotate left
            angle += (angle < -Pi / 2) ? 0.25 : -0.25;
        } else if (angleToCenter >= Pi && angleToCenter < (Pi + Pi / 2 + Pi / 4)) {
            // Rotate right
            angle += (angle < Pi / 2) ? 0.25 : -0.25;
        }
    } else if (::sin(angle) < 0) {
        angle += 0.25;
    } else if (::sin(angle) > 0) {
        angle -= 0.25;
    }

    // Add some random movement
    if (qrand() % 1)
        angle += (qrand() % 100) / 500.0;
    else
        angle -= (qrand() % 100) / 500.0;


    speed += (-50 + qrand() % 100) / 100.0;

    qreal dx = ::sin(angle) * 10;

    setRotation(rotation() + dx);
    setPos(mapToParent(0, -(2 + sin(speed) * 1)));
}
