#ifndef INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
#define INC_2LAB_RIGHTTRUNCATEDPYRAMID_H

#include "Figure.h"

using namespace sf::Glsl;

class RightTruncatedPyramid : public Figure {
public:
    RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h);

    std::vector<Polygon> polygons() override;

private:
    int n_;
    int radiusDown_;
    int radiusUp_;
    int height_;
    std::vector<Vec3> vertexes_;

    void copyVecDown(const Vec3 &vert, Vec3 &ans) const;

    void copyVecUp(const Vec3 &vert, Vec3 &ans) const;
};


#endif //INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
