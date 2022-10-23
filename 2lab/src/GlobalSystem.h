#ifndef INC_2LAB__GLOBALSYSTEM_H
#define INC_2LAB__GLOBALSYSTEM_H

#include "Object.h"
#include "Math.h"
#include "Observer.h"

/*!
 * \breif Класс мира
 *
 * Содержит наблюдателя (камеру) и объекты
 * Позволяет добавлять объекты, изменять значение камеры и тд
 */
class GlobalSystem {
public:
    GlobalSystem(const Math::Vec3 &camera, const float &FOV, const float &Nearest, const float &Farthest,
                 const int &width, const int &height);

    void addObject(const Math::Vec3 &pos, std::shared_ptr<Figure> model);

    void addObject(const Math::Vec3 &pos, const Math::Vec3 &scale, const Math::Vec3 &rotate, std::shared_ptr<Figure> model);

    void changeSize(const int &width, const int &height);

    void setCameraCords(const Math::Vec3 &CameraCords);

    void transform();

    [[nodiscard]] Math::Vec3 cameraCords() const;

private:
    Observer observer_;
    std::vector<Object> objects_;
    int width_;
    int height_;
};

#endif //INC_2LAB__GLOBALSYSTEM_H
