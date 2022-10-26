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
    explicit Observer(const Math::Vec3 &position, const Math::Vec3 &target, const double &FOV, const double &Nearest,
                      const double &Farthest);

    [[nodiscard]] Math::Vec3 position() const;

    void setPosition(const Math::Vec3 &newPosition);

    [[nodiscard]] Math::Mat4 lookAtMatrix(const Math::Vec3 &upVec) const;

    [[nodiscard]] Math::Mat4 projectionMatrix(const double &aspect) const;

private:
    Math::Vec3 eye_;
    double FOV_;
    double Nearest_;
    double Farthest_;
    Math::Vec3 target_;
};


#endif //INC_2LAB_OBSERVER_H
