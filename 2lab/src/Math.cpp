#include "Math.h"

Vec3 Math::normalize(const Vec3 &vec) {
    float x = vec.x, y = vec.y, z = vec.z;
    float len = sqrtf(powf(x, 2) + powf(y, 2) + powf(z, 2));
    return {x / len, y / len, z / len};
}

Vec3 Math::crossProduct(const Vec3 &left, const Vec3 &right) {
    return {left.y * right.z - right.y * left.z,
            right.x * left.z - left.x * right.z,
            left.x * right.y - right.x * left.y};
}
