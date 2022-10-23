#include "Observer.h"

Observer::Observer(const Math::Vec3 &position, const float &FOV, const float &Nearest, const float &Farthest) :
        position_(position), FOV_(FOV), Nearest_(Nearest), Farthest_(Farthest) {
    a_ = (Farthest_ + Nearest_) / (Farthest_ - Nearest_);
    b_ = -2 * Farthest_ * Nearest_ / (Farthest_ - Nearest_);
}

/*!
 * Функция вычисления видовой матрицы
 * @param vecUp - вектор, имеющий направление вверх в глобальной системе координат
 * @return матрицу преобразования координат из глобальной системы координат в систему координат наблюдателя
 */
Math::Mat4 Observer::lookAtMatrix(const Math::Vec3 &vecUp) const {
/*    Vec3 forward = Math::normalize(position_);
    Vec3 left = Math::normalize(Math::crossProduct(vecUp, forward));
    Vec3 up = Math::crossProduct(forward, left);

    float matrix[16];
    matrix[0] = left.x;
    matrix[4] = left.y;
    matrix[8] = left.z;
    matrix[1] = up.x;
    matrix[5] = up.y;
    matrix[9] = up.z;
    matrix[2] = forward.x;
    matrix[6] = forward.y;
    matrix[10] = forward.z;

    // set translation part
    matrix[12] = -Math::scalarProduct(left, position_);
    matrix[13] = -Math::scalarProduct(up, position_);
    matrix[14] = -Math::scalarProduct(forward, position_);
    Mat4 mat(matrix);
    return mat;*/
}

/*!
 * @return вектор позиции наблюдателя в глобальной системе координат
 */
Math::Vec3 Observer::position() const {
    return position_;
}

/*!
 * Устанавливает новую позицию наблюдателя в глобальной системе координат
 * @param newPosition - вектор новой позиции
 */
void Observer::setPosition(const Math::Vec3 &newPosition) {
    position_ = newPosition;
}

/*!
 * Функция вычисления проекционной матрицы
 * @param aspect - соотношение сторон окна
 * @return матрицу видовой проекции
 */
Math::Mat4 Observer::projectionMatrix(const float &aspect) const {
  /*  float matrix[16] = {1 / aspect / tanf(FOV_ / 2), 0, 0, 0,
                        0, 1 / tanf(FOV_ / 2), 0, 0,
                        0, 0, a_, b_,
                        0, 0, 1, 0
    };
    return Mat4(matrix);*/
}
