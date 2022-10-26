#ifndef INC_2LAB__MATH_H
#define INC_2LAB__MATH_H

#include <cmath>

#include "Matrix.h"
#include "Vector.h"

/*!
 * \brief Пространство имен математики
 *
 * Содержит в себе используемые матрицы, векторы, а также функции для работы с ними
 */
namespace Math {
    typedef Vector<double, 2> Vec2;
    typedef Vector<double, 3> Vec3;
    typedef Vector<double, 4> Vec4;

    typedef Matrix<double, 2> Mat2;
    typedef Matrix<double, 3> Mat3;
    typedef Matrix<double, 4> Mat4;

    Vec3 crossProduct(const Vec3 &left, const Vec3 &right);

    Vec4 toVec4(const Vec3 &vec);

    Vec3 toVec3(const Vec2 &vec);

    Mat4 rotate(const double &angle, const Vec3 &R);

    Mat4 scale(const Vec3 &vec);

    Mat4 shift(const Vec3 &vec);
}

#endif //INC_2LAB__MATH_H
