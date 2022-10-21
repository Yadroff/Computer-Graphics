#include "Polygon.h"

Polygon::Polygon(const Vec3 &first, const Vec3 &second, const Vec3 &third) {
    points_.reserve(3);
    points_.emplace_back(first);
    points_.emplace_back(second);
    points_.emplace_back(third);
    sort();
}

std::vector<Vec4> Polygon::points() {
    std::vector<Vec4> ans;
    ans.reserve(3);
    float x, y, z, w = 0;
    for (auto &vec: points_) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        ans.emplace_back(x, y, z, w);
    }
    return std::move(ans);
}

void Polygon::sort() {
    std::sort(points_.begin(), points_.end(),
              [](const auto &lhs, const auto &rhs) { return lhs.z < rhs.z; });
}
