#include "RightTruncatedPyramid.h"

RightTruncatedPyramid::RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h) :
        n_(n), radiusDown_(radiusDown), radiusUp_(radiusUp), h_(h) {
    vertexes_.reserve(n_);
    auto alpha = static_cast<float>(2 * M_PI / n_);
    for (int i = 0; i < n; ++i) {
        float x = cosf(static_cast<float>(i) * alpha);
        float z = sinf(static_cast<float>(i) * alpha);
        float y = 0;
        vertexes_.emplace_back(x, y, z);
    }
}

std::vector<Vec4> RightTruncatedPyramid::vertexes() {
    std::vector<Vec4> ans;
    ans.reserve(2 * n_);
    // нижний многоульник
    for (const auto &vert: vertexes_) {
        float x, y = 0, z, w = 0;
        x = static_cast<float>(radiusDown_) * vert.x;
        z = static_cast<float>(radiusDown_) * vert.z;
        ans.emplace_back(x, y, z, w);
    }
    // верхний многоугольник, радиус другой, высота другая
    for (const auto &vert: vertexes_) {
        float x, y = static_cast<float>(h_), z, w;
        x = static_cast<float>(radiusUp_) * vert.x;
        y = static_cast<float>(radiusUp_) * vert.y;
        ans.emplace_back(x, y, z, w);
    }
    return std::move(ans);
}
