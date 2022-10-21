#ifndef INC_2LAB__OBJECT_H
#define INC_2LAB__OBJECT_H

#include <memory>

#include "Figure.h"

using namespace sf;

class Object {
public:
    Object(const Glsl::Vec3 &coords, const Glsl::Vec3 &scale, const Glsl::Vec3 &rotate, std::shared_ptr<Figure> &model);

private:
    std::shared_ptr<Figure> model_;
    Glsl::Vec3 cords_;
    Glsl::Vec3 scale_;
    Glsl::Vec3 rotate_;
};

#endif //INC_2LAB__OBJECT_H
