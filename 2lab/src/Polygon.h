#ifndef INC_2LAB_SRC_POLYGON_H
#define INC_2LAB_SRC_POLYGON_H

#include <vector>
#include <algorithm>

#include <SFML/Graphics/Glsl.hpp>

using namespace sf::Glsl;

class Polygon {
public:
    Polygon(const Vec3 &first, const Vec3 &second, const Vec3 &third);

    std::vector<Vec4> points();

private:
    void sort();

    std::vector<Vec3> points_;
};

#endif //INC_2LAB_SRC_POLYGON_H
