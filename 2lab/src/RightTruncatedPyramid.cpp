#include "RightTruncatedPyramid.h"

RightTruncatedPyramid::RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h) :
        n_(n), radiusDown_(radiusDown), radiusUp_(radiusUp), height_(h) {
    vertexes_.reserve(n_);
    auto alpha = static_cast<double>(2 * M_PI / n_);
    for (int i = 0; i < n; ++i) {
        double x = cos(static_cast<double>(i) * alpha);
        double y = sin(static_cast<double >(i) * alpha);
        double z = 0;
        vertexes_.emplace_back(x, y, z);
    }
}

/*!
 * \breif Функция, возвращающая полигоны данной модели.
 *
 * Полигоны находятся в системе координат модели (локальной)
 * Полигоны состоят из полигонов оснований (треугольники с одной стороной в центре и двумя другими из n-угольника) и граней
 * @return вектор полигонов пирамиды
 */
std::vector<Polygon> RightTruncatedPyramid::polygons() {
    std::vector<Polygon> ans;
    ans.reserve(4 * n_);
    Math::Vec3 centerDown(0.0, 0.0, 0.0), secondDown, thirdDown;
    Math::Vec3 centerUp(0.0, 0.0, static_cast<double>(height_)), secondUp, thirdUp;
    copyVecDown(vertexes_[0], thirdDown);
    copyVecUp(vertexes_[0], thirdUp);
    for (int i = 1; i < n_; ++i) {
        std::swap(thirdDown, secondDown);
        std::swap(thirdUp, secondUp);
        copyVecUp(vertexes_[i], thirdUp);
        copyVecDown(vertexes_[i], thirdDown);
        // основания пирамиды
        ans.emplace_back(centerDown, secondDown, thirdDown);
        ans.emplace_back(centerUp, secondUp, thirdUp);
        // грани пирамиды
        ans.emplace_back(secondUp, secondDown, thirdDown);
        ans.emplace_back(secondUp, thirdUp, thirdDown);
    }
}

/*!
 * Используется копирования вершины нижнего основания vert в ans
 * @param vert - вершина модели в координатах из отрезка [0;1]
 * @param ans - вершина модели в соответствующем размере
 */
void RightTruncatedPyramid::copyVecDown(const Math::Vec3 &vert, Math::Vec3 &ans) const {
    ans[0] = vert.x() * static_cast<double>(radiusDown_);
    ans[1] = vert.y() * static_cast<double>(radiusDown_);
    ans[2] = 0;
}

/*!
 * Используется копирования вершины верхнего основания vert в ans
 * @param vert - вершина модели в координатах из отрезка [0;1]
 * @param ans - вершина модели в соответствующем размере
 */
void RightTruncatedPyramid::copyVecUp(const Math::Vec3 &vert, Math::Vec3 &ans) const {
    ans[1] = vert.x() * static_cast<double>(radiusUp_);
    ans[2] = vert.y() * static_cast<double>(radiusUp_);
    ans[3] = static_cast<double >(height_);
}
