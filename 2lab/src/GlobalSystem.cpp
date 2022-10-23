#include "GlobalSystem.h"

GlobalSystem::GlobalSystem(const Math::Vec3 &camera, const float &FOV, const float &Nearest, const float &Farthest,
                           const int &width, const int &height) :
        observer_(camera, FOV, Nearest, Farthest), width_(width), height_(height) {}

Math::Vec3 GlobalSystem::cameraCords() const {
    return observer_.position();
}

void GlobalSystem::setCameraCords(const Math::Vec3 &CameraCords) {
    observer_.setPosition(CameraCords);
}

void GlobalSystem::changeSize(const int &width, const int &height) {
    width_ = width;
    height_ = height;
}

/*!
 * \breif Функция трансформирования всех объектов
 *
 * Переносит все объекты в глобальную систему координат, вычисляет видовую и проекционную матрицу.\n
 * Затем применяет все преобразования к объектам
 */
void GlobalSystem::transform() {
    float aspect = static_cast<float>(width_) / static_cast<float>(height_);
    auto look = observer_.lookAtMatrix({0, 1, 0});
    auto project = observer_.projectionMatrix(aspect);
}

void GlobalSystem::addObject(const Math::Vec3 &pos, std::shared_ptr<Figure> model) {

}

void
GlobalSystem::addObject(const Math::Vec3 &pos, const Math::Vec3 &scale, const Math::Vec3 &rotate,
                        std::shared_ptr<Figure> model) {

}

