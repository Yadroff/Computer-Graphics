#include "Scene.h"

Scene::Scene(const Math::Vec3 &camera, const double &FOV, const double &Nearest, const double &Farthest,
             sf::RenderWindow *window) :
        observer_(camera, Math::Vec3({0, 0, -1}), FOV, Nearest, Farthest), window_(window) {}

Math::Vec3 Scene::cameraCords() const {
    return observer_.position();
}

void Scene::setCameraCords(const Math::Vec3 &CameraCords) {
    observer_.setPosition(CameraCords);
}

/*!
 * \breif Функция трансформирования всех объектов
 *
 * Вычисляет видовую матрицу и матрицу проекции.
 * \returns композицию преобразований
 */
Math::Mat4 Scene::transform() {
    auto size = window_->getSize();
    double aspect = static_cast<double>(size.x) / static_cast<double>(size.y);
    auto look = observer_.lookAtMatrix({0, 1, 0});
    auto projection = observer_.projectionMatrix(aspect);
    std::cout << look << projection;
    return projection * look;
}

void Scene::addObject(const Math::Vec3 &pos, std::shared_ptr<Figure> &model) {
    objects_.emplace_back(pos, Math::Vec3(1.0), Math::Vec3(0.0), model);
}

void
Scene::addObject(const Math::Vec3 &pos, const Math::Vec3 &scale, const Math::Vec3 &rotate,
                 std::shared_ptr<Figure> model) {
    objects_.emplace_back(pos, scale, rotate, model);
}

void Scene::draw() {
    auto transformMatrix = transform();
    window_->clear();
    for (const auto &object: objects_) {
        auto model = object.modelMatrix();
        std::cout << model;
        Math::Mat4 resMatrix = transformMatrix * object.modelMatrix();
        auto polygons = object.model()->polygons();
        for (auto &triangle: polygons) {
            std::cout << "BEFORE TRANSFORM\n" << triangle << std::endl;
            triangle.transform(resMatrix);
            std::cout << "AFTER TRANSFORM\n" << triangle << std::endl;
            double n = triangle.normal() * Math::Vec4{0, 0, 1};
            if (n < 0) {
                continue;
            }
            auto size = window_->getSize();
            std::vector<sf::Vertex> vertexes = triangle.toWindowCord(static_cast<int>(size.x),
                                                                     static_cast<int>(size.y));
            for (auto vertex: vertexes) {
                std::cout << vertex.position.x << " " << vertex.position.y << std::endl;
            }
            window_->draw(vertexes.data(), vertexes.size(), sf::Triangles);
        }
    }
}

