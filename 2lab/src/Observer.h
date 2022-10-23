#ifndef INC_2LAB_OBSERVER_H
#define INC_2LAB_OBSERVER_H

#include "Math.h"

/*!
 *@brief Класс наблюдателя (камеры)
 *
 * Используется для создания видовой матрицы и матрицы проекции
 */
class Observer {
public:
    explicit Observer(const Math::Vec3 &position, const float &FOV, const float &Nearest, const float &Farthest);


    [[nodiscard]] Math::Vec3 position() const;

    void setPosition(const Math::Vec3 &newPosition);

    [[nodiscard]] Math::Mat4 lookAtMatrix(const Math::Vec3 &upVec) const;

    [[nodiscard]] Math::Mat4 projectionMatrix(const float &aspect) const;

private:
    Math::Vec3 position_;
    float FOV_;
    float Nearest_;
    float Farthest_;
    float a_;
    float b_;
};


#endif //INC_2LAB_OBSERVER_H
