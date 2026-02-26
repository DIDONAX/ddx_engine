#pragma once

#include "SDL3/SDL_render.h"
#include <vector>
#include "vec2.h"

struct ModelInfo {
    std::vector<SDL_Vertex> vertices_;
    SDL_Texture* texture_{nullptr};
    std::vector<int> indices_;
    vec2 center_;
};

struct Circle {
    ModelInfo m_;
    Circle(const vec2 center, float r, const SDL_FColor& color, int res);
};
