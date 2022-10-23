#ifndef INC_2LAB__FIGURE_H
#define INC_2LAB__FIGURE_H

#include "Polygon.h"

/*!
 * \breif Базовый класс для фигуры.
 *
 * Содержит метод, возвращающий вектор полигонов
 */
class Figure {
public:
    virtual std::vector<Polygon> polygons() = 0;
};

#endif //INC_2LAB__FIGURE_H
