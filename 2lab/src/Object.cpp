#include "Object.h"
Object::Object(const Glsl::Vec3 &coords,
			   const Glsl::Vec3 &scale,
			   const Glsl::Vec3 &rotate,
			   std::shared_ptr<Figure> &model) :
			   cords_(coords), model_(model), scale_(scale), rotate_(rotate){}
