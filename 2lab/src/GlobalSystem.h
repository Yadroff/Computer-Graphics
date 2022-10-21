#ifndef INC_2LAB__GLOBALSYSTEM_H
#define INC_2LAB__GLOBALSYSTEM_H

#include "Object.h"
#include "Math.h"

using namespace sf::Glsl;

class GlobalSystem {
public:
    explicit GlobalSystem(const Vec3 &camera);

    void addObject(const Vec3 &pos, std::shared_ptr<Figure> model);

    void addObject(const Vec3 &pos, const Vec3 &scale, const Vec3 &rotate, std::shared_ptr<Figure> model);

    [[nodiscard]] const Vec3 &cameraCords() const;

    void setCameraCords(const Vec3 &CameraCords);

    Mat4 calculateLookAtMatrix();

private:
    Vec3 cameraCords_;
    std::vector<Object> objects_;
};

#endif //INC_2LAB__GLOBALSYSTEM_H
