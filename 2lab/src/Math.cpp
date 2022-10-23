#include "Math.h"

using namespace Math;

/*!
 * Функция векторного произведения left x right
 * @param left - левый вектор
 * @param right - правый вектор
 * @return Vec3 n = [left, right]
 */
Vec3 Math::crossProduct(const Math::Vec3 &left, const Math::Vec3 &right) {
    return {left.y() * right.z() - left.z() * right.y(),
            left.z() * right.x() - left.x() * right.z(),
            left.x() * right.y() - left.y() * right.x()};
}

/*!
 * Функция преобразования из Vec2 в Vec3
 * @param vec = (x, y)
 * @return (x, y, 0)
 */
Vec3 Math::toVec3(const Math::Vec2 &vec) {
    return {vec.x(), vec.y(), 0};
}

/*!
 * Функция преобразования из Vec2 в Vec4
 * @param vec = (x, y, z)
 * @return (x, y, z, abs(vec))
 */
Vec4 Math::toVec4(const Math::Vec3 &vec) {
    return {vec.x(), vec.y(), vec.z(), vec.magnitude()};
}
