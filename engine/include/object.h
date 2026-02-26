#pragma once

#include "models.h"
#include "vec2.h"
#include "SDL3/SDL_pixels.h"
#include "constants.h"
#include <string>


struct Object {
    float m_;
    vec2 p_;
    vec2 v_;
    vec2 a_;
};

struct RObject {
    Object* obj_;
    Circle shape_;
    std::string label_;
    SDL_FColor color_;
    RObject(Object& o, const SDL_FColor& c, float r, std::string l = "") : obj_(&o), shape_(o.p_ , r, c, 30), label_(l), color_(c) {}
};
