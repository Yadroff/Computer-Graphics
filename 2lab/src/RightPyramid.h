#ifndef INC_2LAB__RIGHTPYRAMID_H
#define INC_2LAB__RIGHTPYRAMID_H

#include "Figure.h"

/*!
 * Класс n-угольной правильной пирамиды (n >= 3)
 *
 * Содержит в себе координаты точек в нормированной системе координат,
 * представляющих вершины правильного n-угольника и одну ортогональную вершину пирамиды
 */
class RightPyramid: public Figure {
public:
  RightPyramid(const int &n, const int &side, const int &height);
  std::vector<sf::Glsl::Vec4> vertexes() override;
private:
  int n_;
  int side_;
  int height_;
  std::vector<sf::Glsl::Vec3> vertexes_;
};

#endif //INC_2LAB__RIGHTPYRAMID_H
