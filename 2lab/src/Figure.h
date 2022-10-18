#ifndef INC_2LAB__FIGURE_H
#define INC_2LAB__FIGURE_H

#include <vector>
#include <cmath>

#include <SFML/Graphics/Glsl.hpp>

class Figure {
public:
  virtual std::vector<sf::Glsl::Vec4> vertexes() = 0;
};

#endif //INC_2LAB__FIGURE_H
