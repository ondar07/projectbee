#ifndef EGG_H
#define EGG_H

#include <QGraphicsItem>
#include <QTimer>

class Egg : public QGraphicsObject
{
    Q_OBJECT

public:
    Egg();
    //~Egg();

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    int getAge();
    qreal getAngle();
    int type; // тип: 0 - матка, 1 - рабочая пчела, 2 - трутень
    QPoint place; // точка размещения
                // понадобится, когда будем передавать пчеле
                // где появляться
    bool vsble; // visible (используется в классе eggList
                // чтобы удалить все невидимые яйца)
    int cellNumber; // порядковый номер ячейки, в которой будет яйцо
                    // (данная переменная нужна, чтобы отправить сигнал beehive
                    // для установления state = 1)

public slots:
    void evolution(); // здесь будет развитие (вращение яйца + апдейт age)

signals:
    void createQueen(QPoint position, int cellNumb);     // сигнал, который будет отправляться eggList
    void createWorker(QPoint position, int cellNumb);    // о том, что надо создать пчелу
    void createDrone(QPoint position, int cellNumb);     // eggList, в свою очередь, будет отправлять Scene_t
    void killEggs();  // будем посылать eggList

protected:
    qreal angle; // угол поворота
    int age; // возраст


};
#endif // EGG_H
