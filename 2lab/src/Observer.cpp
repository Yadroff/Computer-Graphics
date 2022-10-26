#include "Observer.h"

Observer::Observer(const Math::Vec3 &position, const Math::Vec3 &target, const double &FOV, const double &Nearest,
                   const double &Farthest) :
        eye_(position), FOV_(FOV), Nearest_(Nearest), Farthest_(Farthest), target_(target) {
}

/*!
 * Функция вычисления видовой матрицы
 * @param vecUp - вектор, имеющий направление вверх в глобальной системе координат
 * @return матрицу преобразования координат из глобальной системы координат в систему координат наблюдателя
 */
Math::Mat4 Observer::lookAtMatrix(const Math::Vec3 &vecUp) const {
    Math::Mat4 translation = {{1, 0, 0, -eye_.x()},
                              {0, 1, 0, -eye_.y()},
                              {0, 0, 1, -eye_.z()},
                              {0, 0, 0, 1}};
    Math::Vec3 forward = eye_ - target_;
    forward.normalize();
    Math::Vec3 left = Math::crossProduct(vecUp, forward);
    left.normalize();
    Math::Vec3 up = Math::crossProduct(forward, left);
    Math::Mat4 rotation = {{left.x(),    left.y(),    left.z(),    0},
                           {up.x(),      up.y(),      up.z(),      0},
                           {forward.x(), forward.y(), forward.z(), 0},
                           {0,           0,           0,           1}};
    return rotation * translation;
}

/*!
 * @return вектор позиции наблюдателя в глобальной системе координат
 */
Math::Vec3 Observer::position() const {
    return eye_;
}

/*!
 * Устанавливает новую позицию наблюдателя в глобальной системе координат
 * @param newPosition - вектор новой позиции
 */
void Observer::setPosition(const Math::Vec3 &newPosition) {
    eye_ = newPosition;
}

/*!
 * Функция вычисления проекционной матрицы
 * @param aspect - соотношение сторон окна
 * @return матрицу видовой проекции
 */
Math::Mat4 Observer::projectionMatrix(const double &aspect) const {
    return {{1 / aspect / tan(FOV_ / 2), 0,                 0,                                                0},
            {0,                          1 / tan(FOV_ / 2), 0,                                                0},
            {0,                          0,                 -(Farthest_ + Nearest_) / (Farthest_ - Nearest_), -2 *
                                                                                                              Farthest_ *
                                                                                                              Nearest_ /
                                                                                                              (Farthest_ -
                                                                                                               Nearest_)},
            {0,                          0,                 -1,                                               0}};
}
