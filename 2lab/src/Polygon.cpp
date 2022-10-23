#include <stdexcept>
#include "Polygon.h"

Polygon::Polygon(const Math::Vec3 &first, const Math::Vec3 &second, const Math::Vec3 &third) {
    points_.reserve(3);
    points_.emplace_back(first);
    points_.emplace_back(second);
    points_.emplace_back(third);
    sort();
    calculateNormal();
}

/*!
 * Функция преобразования массива вершин в массив 4-х мерных точек
 * @return std::vector<Math::Vec4> состоящий из вершин полигона
 */
std::vector<Math::Vec4> Polygon::points() {
    std::vector<Math::Vec4> ans;
    ans.reserve(3);
    double x, y, z, w;
    for (auto &vec: points_) {
        x = vec.x();
        y = vec.y();
        z = vec.z();
        w = vec.magnitude();
        ans.emplace_back(x, y, z, w);
    }
    return std::move(ans);
}

/*!
 * Функция сортировки вершин по величине z - глубине
 */
void Polygon::sort() {
    std::sort(points_.begin(), points_.end(),
              [](const auto &lhs, const auto &rhs) { return lhs.z() < rhs.z(); });
}

/*!
 * Функция вычисления нормали
 */
void Polygon::calculateNormal() {
    Math::Vec3 v1 = points_[1] - points_[0], v2 = points_[2] - points_[0];
    normal_ = Math::crossProduct(v1, v2);
}

/*!
 * @return возвращает вектор нормали
 */
const Math::Vec3 &Polygon::normal() const {
    return normal_;
}

/*!
 * Функция преобразования вершин в экранные координаты
 * @param width - ширина окна
 * @param height - высота окна
 * @return std::vector<sf::Vertex>, состоящий из вершин треугольника
 */
std::vector<sf::Vertex> Polygon::toWindowCord(const int &width, const int &height) {
    std::vector<sf::Vertex> ans;
    ans.reserve(4);
    for (auto &point: points_) {
        ans.emplace_back(
                sf::Vector2f(static_cast<float>(width) / 2 * (1 + static_cast<float>(point.x())),
                             static_cast<float>(height) / 2 * (1 + static_cast<float>(point.y()))),
                sf::Color::Black);
    }
    ans.emplace_back(ans[0]);
}

/*!
 * @param i - индекс вершины
 * @return i-ую вершину полигона
 */
Math::Vec3 &Polygon::operator[](const int &i) {
    if (i < 0 or i >= 3) {
        throw std::out_of_range("Index is " + std::to_string(i));
    }
    return points_[i];
}
