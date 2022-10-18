#include "GlobalSystem.h"

GlobalSystem::GlobalSystem(const Vec3 &camera) : cameraCords_(camera) {}

void GlobalSystem::addObject(const Vec3 &pos, std::shared_ptr<Figure> model) {
  objects_.emplace_back(pos, Vec3(1, 1, 1), Vec3(0, 0, 0), model);
}

void GlobalSystem::addObject(const Vec3 &pos, const Vec3 &scale, const Vec3 &rotate, std::shared_ptr<Figure> model) {
  objects_.emplace_back(pos, scale, rotate, model);
}
const Vec3 &GlobalSystem::cameraCords() const {
  return cameraCords_;
}
void GlobalSystem::setCameraCords(const Vec3 &CameraCords) {
  cameraCords_ = CameraCords;
}
Mat4 GlobalSystem::calculateLookAtMatrix() {
  Vec3 forward = Math::normalize(cameraCords_);
  Vec3 left = Math::normalize(Math::crossProduct(Vec3(0, 1, 0), forward));
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
  matrix[10]= forward.z;

  // set translation part
  matrix[12]= -left.x * cameraCords_.x - left.y * cameraCords_.y - left.z * cameraCords_.z;
  matrix[13]= -up.x * cameraCords_.x - up.y * cameraCords_.y - up.z * cameraCords_.z;
  matrix[14]= -forward.x * cameraCords_.x - forward.y * cameraCords_.y - forward.z * cameraCords_.z;
  Mat4 mat(matrix);
  return mat;
}
