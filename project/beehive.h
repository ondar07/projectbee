#ifndef BEEHIVE_H
#define BEEHIVE_H

#include <QtWidgets>
#include "cell.h"
#include <QList>
#include <QObject>

class Beehive : public QObject {

    Q_OBJECT

public:
    Beehive();
    void draw_cells(QGraphicsScene *scene);
    int retCellCount();
    int getNumbEmptyCellForHoney(); // для меда
    int getTemper();
    QList<Cell *> cellList; // список ячеек
public slots:
    void tempChanged(int value);
    void cleaningCell(int numberCell); // слот на сигнал от Scene_t
                                        // чтобы "почистить" ячейку
                        // есть мысль:этот слот присвоить рабочей пчеле
    void whatEmptyCell(); // ответ на сигнал от главной матки
                        // находим своб. ячейку и отправляем сигнал toMainQueen

signals:
    void toMainQueen(int numbEmpCell, QPoint placeEmpCell); // возвращаем порядковый номер и координаты

protected:
    int iteratorForEggs;   // используем в выделении свободных ячеек для матки
    int iteratorForHoney;   // для выделения своб. ячеек для меда
    int getNumberEmptyCell(); // получить порядковый номер пустой ячейки
                            // чтобы 1) матка отложила яйца
                            // или 2) рабочая пчела смогла почистить грязные ячейки

private:
    int cell_count; // количество ячеек
    int temper;
};

#endif // BEEHIVE_H
