#ifndef INC_2LAB__GLOBALSYSTEM_H
#define INC_2LAB__GLOBALSYSTEM_H

#include <SFML/Graphics.hpp>

#include "Object.h"
#include "Math.h"
#include "Observer.h"

/*!
 * \breif Класс мира
 *
 * Содержит наблюдателя (камеру) и объекты
 * Позволяет добавлять объекты, изменять значение камеры и тд
 */
class Scene {
public:
    Scene(const Math::Vec3 &camera, const double &FOV, const double &Nearest, const double &Farthest,
          sf::RenderWindow *window);

    void addObject(const Math::Vec3 &pos, std::shared_ptr<Figure> &model);

    void
    addObject(const Math::Vec3 &pos, const Math::Vec3 &scale, const Math::Vec3 &rotate, std::shared_ptr<Figure> model);

    void setCameraCords(const Math::Vec3 &CameraCords);

    Math::Mat4 transform();

    [[nodiscard]] Math::Vec3 cameraCords() const;

    void draw();

private:
    Observer observer_;
    std::vector<Object> objects_;
    sf::RenderWindow *window_;
};

#endif //INC_2LAB__GLOBALSYSTEM_H
