#include "models.h"
#include "constants.h"
#include <cmath>

Circle::Circle(const vec2 center, float r = 50, const SDL_FColor& color = kRed, int res = 30) {
    m_.center_ = center;
    float theta = 0;
    float x = center.x_;
    float y = center.y_;

    m_.vertices_.push_back({{x, y}, color, {}});
    m_.vertices_.push_back({{x+r, y}, color, {}});
    for (int i = 0; i < res-1; ++i) {
        theta+=2*pi/res;
        float x0 = std::cos(theta) * r;
        float y0 = std::sin(theta) * r;
        m_.vertices_.push_back({{x+x0, y-y0}, color, {}});
        int size = m_.vertices_.size();
        m_.indices_.insert(m_.indices_.end(), {0, size-2, size-1});
    }
    int size = m_.vertices_.size();
    m_.indices_.insert(m_.indices_.end(), {0, 1, size-1});
}
