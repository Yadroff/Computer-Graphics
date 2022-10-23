#include "Object.h"

Object::Object(Mat4 &modelMatrix, std::shared_ptr<Figure> &model) : model_(model), modelMatrix_(modelMatrix) {}

Mat4 Object::modelMatrix() {
    return modelMatrix_;
}

const std::shared_ptr<Figure> &Object::model() const {
    return model_;
}
