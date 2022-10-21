#include "RightTruncatedPyramid.h"

RightTruncatedPyramid::RightTruncatedPyramid(const int &n, const int &radiusDown, const int &radiusUp, const int &h) :
        n_(n), radiusDown_(radiusDown), radiusUp_(radiusUp), height_(h) {
    vertexes_.reserve(n_);
    auto alpha = static_cast<float>(2 * M_PI / n_);
    for (int i = 0; i < n; ++i) {
        float x = cosf(static_cast<float>(i) * alpha);
        float z = sinf(static_cast<float>(i) * alpha);
        float y = 0;
        vertexes_.emplace_back(x, y, z);
    }
}

std::vector<Polygon> RightTruncatedPyramid::polygons() {
    std::vector<Polygon> ans;
    ans.reserve(4 * n_);
    Vec3 centerDown(0, 0, 0), secondDown, thirdDown;
    Vec3 centerUp(0, static_cast<float>(height_), 0), secondUp, thirdUp;
    copyVecDown(vertexes_[0], thirdDown);
    copyVecUp(vertexes_[0], thirdUp);
    for (int i = 1; i < n_; ++i) {
        std::swap(thirdDown, secondDown);
        std::swap(thirdUp, secondUp);
        copyVecUp(vertexes_[i], thirdUp);
        copyVecDown(vertexes_[i], thirdDown);
        // основания пирамиды
        ans.emplace_back(centerDown, secondDown, thirdDown);
        ans.emplace_back(centerUp, secondUp, thirdUp);
        // грани пирамиды
        ans.emplace_back(secondUp, secondDown, thirdDown);
        ans.emplace_back(secondUp, thirdUp, thirdDown);
    }
}

void RightTruncatedPyramid::copyVecDown(const Vec3 &vert, Vec3 &ans) const {
    ans.x = vert.x * static_cast<float>(radiusDown_);
    ans.y = 0;
    ans.z = vert.z * static_cast<float>(radiusDown_);
}

void RightTruncatedPyramid::copyVecUp(const Vec3 &vert, Vec3 &ans) const {
    ans.x = vert.x * static_cast<float>(radiusUp_);
    ans.y = static_cast<float>(height_);
    ans.z = vert.z * static_cast<float>(radiusUp_);
}
