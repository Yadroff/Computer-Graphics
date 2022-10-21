#ifndef INC_2LAB__FIGURE_H
#define INC_2LAB__FIGURE_H

#include <vector>
#include <cmath>

#include <SFML/Graphics/Glsl.hpp>

#include "Polygon.h"

class Figure {
public:
    virtual std::vector<Polygon> polygons() = 0;
};

#endif //INC_2LAB__FIGURE_H
