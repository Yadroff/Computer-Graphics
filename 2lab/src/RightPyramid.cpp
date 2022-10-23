#include "RightPyramid.h"


RightPyramid::RightPyramid(const int &n, const int &radius, const int &height) :
        n_(n), radius_(radius), height_(height) {
    double alpha = 2 * M_PI / n;
    double x, y, z = 0;
    for (int i = 0; i < n; ++i) {
        x = cos(i * alpha);
        y = sin(i * alpha);
        x = round(x * 100) / 100;
        y = round(z * 100) / 100;
        vertexes_.emplace_back(x, y, z);
    }
    // вершина пирамиды
    vertexes_.emplace_back(static_cast<double>(0), static_cast<double>(0), static_cast<double>(1));
}

/*!
 * \breif Функция, возвращающая полигоны данной модели.
 *
 * Полигоны находятся в системе координат модели (локальной)
 * Полигоны состоят из полигонов оснований (треугольники с одной стороной в центре и двумя другими из n-угольника) и граней
 * @return вектор полигонов пирамиды
 */
std::vector<Polygon> RightPyramid::polygons() {
    std::vector<Polygon> ans;
    ans.reserve(2 * n_);
    Math::Vec3 center(0.0, 0.0, 0.0), second, third, vert(0.0, 0.0, static_cast<double>(height_));
    copyVec(vertexes_[0], third);
    for (int i = 1; i < n_; ++i) {
        std::swap(second, third);
        copyVec(vertexes_[i], third);
        // основание пирамиды
        ans.emplace_back(center, second, third);
        // грани пирамиды
        ans.emplace_back(vert, second, third);
    }
    return std::move(ans);
}

/*!
 * Используется копирования вершины основания vert в ans
 * @param vert - вершина модели в координатах из отрезка [0;1]
 * @param ans - вершина модели в соответствующем размере
 */
void RightPyramid::copyVec(const Math::Vec3 &vert, Math::Vec3 &ans) const {
    ans[0] = vert.x() * static_cast<double >(radius_);
    ans[1] = vert.y() * static_cast<double >(radius_);
    ans[2] = 0;
}
