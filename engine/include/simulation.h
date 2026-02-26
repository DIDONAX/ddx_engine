#pragma once

#include "engine.h"
#include "object.h"
#include "renderer.h"
#include "types.h"

struct Simulation {
    Engine* engine_;
    Renderer* renderer_;
    std::vector<RObject*> scene_;

    Simulation(Engine& e, Renderer& r);

    void register_sys(RObject& o, Force& f); 

    void start();
};
