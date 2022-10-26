#ifndef INC_2LAB__OBJECT_H
#define INC_2LAB__OBJECT_H

#include <memory>

#include "Figure.h"


class Object {
public:
    Object(const Math::Vec3 &position, const Math::Vec3 &scale, const Math::Vec3 &rotate, std::shared_ptr<Figure> &model);

    [[nodiscard]] Math::Mat4 modelMatrix() const;

    [[nodiscard]] const std::shared_ptr<Figure> &model() const;

private:
    std::shared_ptr<Figure> model_;
    Math::Mat4 modelMatrix_;
};

#endif //INC_2LAB__OBJECT_H
