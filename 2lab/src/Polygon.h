#ifndef INC_2LAB_SRC_POLYGON_H
#define INC_2LAB_SRC_POLYGON_H

#include <vector>
#include <algorithm>
#include <exception>

#include <SFML/Graphics/Vertex.hpp>

#include "Math.h"

/*!
 * \brief Класс полигона
 *
 * Полигон представляет собой треугольник из трех вершин\n
 * Хранит массив вершин, а также нормаль для определения ориентации треугольника
 */
class Polygon {
public:
    Polygon(const Math::Vec3 &first, const Math::Vec3 &second, const Math::Vec3 &third);

    std::vector<Math::Vec4> points();

    std::vector<sf::Vertex> toWindowCord(const int &width, const int &height);

    [[nodiscard]] const Math::Vec3 &normal() const;

    Math::Vec3 &operator[](const int &i);

private:
    void sort();

    void calculateNormal();

    std::vector<Math::Vec3> points_;
    Math::Vec3 normal_;
};

#endif //INC_2LAB_SRC_POLYGON_H
