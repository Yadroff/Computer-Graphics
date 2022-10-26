#include "Object.h"

Object::Object(const Math::Vec3 &position, const Math::Vec3 &scale, const Math::Vec3 &rotate,
               std::shared_ptr<Figure> &model): model_(model) {
    modelMatrix_ = Math::rotate(rotate.x(), {1, 0, 0}) * Math::rotate(rotate.y(), {0, 1, 0}) *
                   Math::rotate(rotate.z(), {0, 0, 1}) * Math::scale(scale) * Math::shift(position);
}

const std::shared_ptr<Figure> &Object::model() const {
    return model_;
}

Math::Mat4 Object::modelMatrix() const{
    return modelMatrix_;
}

