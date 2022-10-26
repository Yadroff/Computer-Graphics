#ifndef INC_2LAB__RIGHTPYRAMID_H
#define INC_2LAB__RIGHTPYRAMID_H

#include "Figure.h"

/*!
 * \brief Класс n-угольной правильной пирамиды (n >= 3)
 *
 * Содержит в себе координаты точек в нормированной системе координат,\n
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
    std::vector<Math::Vec3> vertexes_;

    void copyVec(const Math::Vec3 &vert, Math::Vec4 &ans) const;
};

#endif //INC_2LAB__RIGHTPYRAMID_H
