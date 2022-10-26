#include <stdexcept>
#include "Polygon.h"

Polygon::Polygon(const Math::Vec4 &first, const Math::Vec4 &second, const Math::Vec4 &third) {
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
    return points_;
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
    Math::Vec4 v1 = points_[1] - points_[0], v2 = points_[2] - points_[0];
    Math::Vec3 left = {v1.x(), v1.y(), v1.z()};
    Math::Vec3 right = {v2.x(), v2.y(), v2.z()};
//    std::cout << left << std::endl << right << std::endl;
    normal_ = Math::toVec4(Math::crossProduct(left, right));
}

/*!
 * @return возвращает вектор нормали
 */
const Math::Vec4 &Polygon::normal() const {
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
        point.normalize();
        ans.emplace_back(
                sf::Vector2f(static_cast<float>(width) / 2 * (1 + static_cast<float>(point.x())),
                             static_cast<float>(height) / 2 * (1 + static_cast<float>(point.y()))),
                sf::Color::Black);
    }
    ans.emplace_back(ans[0]);
    return ans;
}

/*!
 * @param i - индекс вершины
 * @return i-ую вершину полигона
 */
Math::Vec4 &Polygon::operator[](const int &i) {
    if (i < 0 or i >= 3) {
        throw std::out_of_range("Index is " + std::to_string(i));
    }
    return points_[i];
}

void Polygon::transform(const Math::Mat4 &transform) {
    for (auto &point: points_) {
        point = transform * point;
    }
    calculateNormal();
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
    os << "POLYGON\n";
    for (const auto &point: polygon.points_) {
        os << point << std::endl;
    }
    os << "NORMAL\n" << polygon.normal_ << std::endl;
    return os;
}
