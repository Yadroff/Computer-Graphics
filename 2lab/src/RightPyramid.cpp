#include "RightPyramid.h"
RightPyramid::RightPyramid(const int &n, const int &side, const int &height) : n_(n), side_(side), height_(height) {
  double alpha = 2 * M_PI / n;
  double x, y = 0, z = 0;
  for (int i = 0; i < n; ++i) {
	x = cos(i * alpha);
	z = sin(i * alpha);
	x = round(x * 100) / 100;
	z = round(z * 100) / 100;
	vertexes_.emplace_back(x, y, z);
  }

  vertexes_.emplace_back(0, 1, 0);
}
std::vector<sf::Glsl::Vec4> RightPyramid::vertexes() {
  std::vector<sf::Glsl::Vec4> ans(n_ + 1);
  float x, z;
  for (int i = 0; i < n_; ++i) {
	x = vertexes_[i].x;
	z = vertexes_[i].z;
	ans[i] = {static_cast<float>(side_) * x, 0, static_cast<float>(side_) * z, 0};
  }
  ans[n_] = {0, static_cast<float>(height_), 0, 0};
  return ans;
}
