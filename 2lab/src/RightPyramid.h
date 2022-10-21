#ifndef INC_2LAB__RIGHTPYRAMID_H
#define INC_2LAB__RIGHTPYRAMID_H

#include "Figure.h"

/*!
 * Класс n-угольной правильной пирамиды (n >= 3)
 *
 * Содержит в себе координаты точек в нормированной системе координат,
 * представляющих вершины правильного n-угольника и одну ортогональную вершину пирамиды
 */
class RightPyramid : public Figure {
public:
    RightPyramid(const int &n, const int &radius, const int &height);

    std::vector<Polygon> polygons() override;

private:
    int n_;
    int radius_;
    int height_;
    std::vector<sf::Glsl::Vec3> vertexes_;

    void copyVec(const sf::Glsl::Vec3 &vert, sf::Glsl::Vec3 &ans) const;
};

#endif //INC_2LAB__RIGHTPYRAMID_H
