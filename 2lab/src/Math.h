#ifndef INC_2LAB__MATH_H
#define INC_2LAB__MATH_H

#include <cmath>
#include <SFML/Graphics/Glsl.hpp>

using namespace sf::Glsl;
namespace Math{
	Vec3 normalize(const Vec3 &vec);
	Vec3 crossProduct(const Vec3 &left, const Vec3 &right);
}

#endif //INC_2LAB__MATH_H
