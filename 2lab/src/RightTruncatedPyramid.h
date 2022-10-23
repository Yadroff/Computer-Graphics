#ifndef INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
#define INC_2LAB_RIGHTTRUNCATEDPYRAMID_H

#include "Figure.h"

/*!
 * \breif Класс правильной усеченной пирамиды
 *
 * В качестве параметров усеченная пирамида имеет количество вершин, радиус окружностей, описанной вокруг оснований,
 * высоту верхнего основания
 */
class RightTruncatedPyramid : public Figure {
public:
    RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h);

    std::vector<Polygon> polygons() override;

private:
    int n_;
    int radiusDown_;
    int radiusUp_;
    int height_;
    std::vector<Math::Vec3> vertexes_;

    void copyVecDown(const Math::Vec3 &vert, Math::Vec3 &ans) const;

    void copyVecUp(const Math::Vec3 &vert, Math::Vec3 &ans) const;
};


#endif //INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
