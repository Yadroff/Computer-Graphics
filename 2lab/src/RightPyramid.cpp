#include "RightPyramid.h"


RightPyramid::RightPyramid(const int &n, const int &radius, const int &height) :
        n_(n), radius_(radius), height_(height) {
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

std::vector<Polygon> RightPyramid::polygons() {
    std::vector<Polygon> ans;
    ans.reserve(2 * n_);
    sf::Glsl::Vec3 center(0, 0, 0), second, third, vert(0, static_cast<float>(height_), 0);
    copyVec(vertexes_[0], third);
    for (int i = 1; i < n_; ++i) {
        std::swap(second, third);
        copyVec(vertexes_[i], third);
        ans.emplace_back(center, second, third);
        ans.emplace_back(vert, second, third);
    }
    return std::move(ans);
}

void RightPyramid::copyVec(const Vec3 &vert, Vec3 &ans) const {
    ans.x = vert.x * static_cast<float>(radius_);
    ans.y = 0;
    ans.z = vert.z * static_cast<float>(radius_);
}
