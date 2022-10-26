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

/*!
     * Функция вычисления матрицы поворота на угол alpha вокруг произвольной оси R
     * @param angle - угол поворота
     * @param R - вектор, задающий ось поворота
     * @return матрицу поворота
     */
Mat4 Math::rotate(const double &angle, const Math::Vec3 &R) {
    double cosa = std::cos(angle);
    double sina = std::sin(angle);

    double RxSin = R[0] * sina;
    double RySin = R[1] * sina;
    double RzSin = R[2] * sina;

    double Rx1Cos = R[0] * (1 - cosa);
    double Ry1Cos = R[1] * (1 - cosa);
    double Rz1Cos = R[2] * (1 - cosa);

    return {{cosa + R[0] * Rx1Cos,  R[0] * Ry1Cos - RzSin, R[0] * Rz1Cos + RySin, 0},
            {R[1] * Rx1Cos + RzSin, cosa + R[1] * Ry1Cos,  R[1] * Rz1Cos - RxSin, 0},
            {R[2] * Rx1Cos - RySin, R[2] * Ry1Cos + RxSin, cosa + R[2] * Rz1Cos,  0},
            {0,                     0,                     0,                     1}};
}

/*!
 * Функция вычисления матрицы масштабирования
 * @param vec - вектор размерности 3 с коэффициентами масштабирования
 * @return матрицу масштабирования
 */
Mat4 Math::scale(const Math::Vec3 &vec) {
    return {{vec.x(), 0,       0,       0},
            {0,       vec.y(), 0,       0},
            {0,       0,       vec.z(), 0, 0},
            {0,       0,       0,       1}};
}

Mat4 Math::shift(const Math::Vec3 &vec) {
    return {{1, 0, 0, vec.x()},
            {0, 1, 0, vec.y()},
            {0, 0, 1, vec.z()},
            {0, 0, 0, 1}};
}