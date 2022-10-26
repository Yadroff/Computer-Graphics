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
    Polygon(const Math::Vec4 &first, const Math::Vec4 &second, const Math::Vec4 &third);

    std::vector<Math::Vec4> points();

    std::vector<sf::Vertex> toWindowCord(const int &width, const int &height);

    [[nodiscard]] const Math::Vec4 &normal() const;

    Math::Vec4 &operator[](const int &i);

    void transform(const Math::Mat4 &transform);

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon);
private:
    void sort();

    void calculateNormal();

    std::vector<Math::Vec4> points_;
    Math::Vec4 normal_;
};

#endif //INC_2LAB_SRC_POLYGON_H
