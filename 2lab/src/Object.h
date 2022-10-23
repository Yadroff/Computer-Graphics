#ifndef INC_2LAB__OBJECT_H
#define INC_2LAB__OBJECT_H

#include <memory>

#include "Figure.h"


class Object {
public:
    Object(Mat4 &modelMatrix, std::shared_ptr<Figure> &model);

    Mat4 modelMatrix();

    [[nodiscard]] const std::shared_ptr<Figure> &model() const;

private:
    std::shared_ptr<Figure> model_;
    Mat4 modelMatrix_;
};

#endif //INC_2LAB__OBJECT_H
