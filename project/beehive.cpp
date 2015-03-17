#include "beehive.h"

static const qreal sqrt3 = 1.73205080757; //sqrt 3 (корень из 3 выскакивает, при рассмотрении
                                        //шестиугольника (ячейки cell)
                                        // понадобится при рисовании

Beehive::Beehive()
{
    cell_count = 160;
    temper = 25;
    iteratorForEggs = 70;   // яйца для нижних ячеек
    iteratorForHoney = 0; // мед для верхних ячеек
    // в цикле выделяем память для каждой ячейки
    for(int i= 0; i < cell_count; i++) {
        cellList.append(new Cell);
    }
}

//возвращает значение cell_count (функция нужна в виду того, что
// переменная в private
int Beehive::retCellCount() {
    return cell_count;
}

// получить порядковый номер в списке ячеек
// свободной ячейки для откладки яиц
int Beehive::getNumberEmptyCell() {
    if(iteratorForEggs == cell_count-1)
        iteratorForEggs = 70; // начинаем заново с первой ячейки смотреть
    for(int i = iteratorForEggs; i < cell_count; i++) {
        if(cellList[i]->isEmpty()) {
            iteratorForEggs = i;
            return i;
        }
    }
    // если так и не нашли ячейки, то возвращаем 0
    return 0;
}

// поиск своб. номера ячейки для меда
int Beehive::getNumbEmptyCellForHoney() {
    if(iteratorForHoney == 70-1)
        iteratorForHoney = 0; //
    for(int i = iteratorForHoney; i<70; i++) {
        if(cellList[i]->isEmpty()) {
            iteratorForHoney = i;
            return i;
        }
    }
    // если не нашли, то -1
    return -1;
}

// почистим
void Beehive::cleaningCell(int numberCell) {
    this->cellList[numberCell]->setState(0); // свободная

}

void Beehive::whatEmptyCell() {
    int numbEmpCell;
    QPoint placeEmpCell;

    numbEmpCell = getNumberEmptyCell();
    if(numbEmpCell == 0) { // если не нашли своб. ячейки, то возвращаем нули
        placeEmpCell = QPoint(0,0);
    } else {
        this->cellList[numbEmpCell]->setState(1);// устанавливаем, что ячейка занята
        placeEmpCell = this->cellList[numbEmpCell]->getCenterCoord();
    }
    emit toMainQueen(numbEmpCell, placeEmpCell); // теперь матка отложит яйца (latEggs)
}

int Beehive::getTemper()
{
    return temper;
}

void Beehive::tempChanged(int value)
{
    //if (value != temper)
          temper = value;
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * *рисование * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void Beehive::draw_cells(QGraphicsScene *scene) {
    qreal h = 20; // сторона шестиугольника cell
    //но нас будут интересовать sqrt(3)h
    h = sqrt3 * h;
    qreal x; // координата для новой строки ячеек
    qreal y;

    x = 150.0;
    y= 180.0; // координаты (центра) самой верхней левой ячейки
              // относительно СК сцены
    int iter=0; // счетчик ячеек
    int i; // счетчик
    bool is_odd = false; // нечетная ли строка ячеек?
    while(iter < cell_count) {
        for(i = 0; i<10; i++) {
            qreal newX;

            newX = x+i*h+1;
            cellList[iter]->setPos(newX, y);
            scene->addItem(cellList[iter]);
            cellList[iter]->setCenterCoord(newX, y); // устанавливаем координаты
            iter++;
        }

        if(is_odd) {
            x -= h/2.0;
            is_odd = false;
        } else {
            x += h/2.0;
            is_odd = true; // для след. раза
        }
        y += h-2;

    }
}
