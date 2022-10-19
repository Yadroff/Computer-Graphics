#ifndef INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
#define INC_2LAB_RIGHTTRUNCATEDPYRAMID_H

#include "Figure.h"

using namespace sf::Glsl;
class RightTruncatedPyramid: public Figure {
public:
    RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h);
    std::vector<sf::Glsl::Vec4> vertexes() override;
private:
    int n_;
    int radiusDown_;
    int radiusUp_;
    int h_;
    std::vector<Vec3> vertexes_;
};


#endif //INC_2LAB_RIGHTTRUNCATEDPYRAMID_H
