#include "renderer.h"

#include <print>
#include <unordered_map>
#include <vector>
#include <algorithm>

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_video.h"
#include "constants.h"
#include "models.h"
#include "object.h"
#include "types.h"

Renderer::Renderer(int scale) : scale_(scale) {
    init_sdl();
    init_window();
}

Renderer::~Renderer() {cleanup();}

void Renderer::clear() const {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}

void Renderer::render() const {
    SDL_RenderPresent(renderer_);
}

void Renderer::draw(RObject& ro) const {
    vec2 pos = ro.obj_->p_; 
    auto verts = ro.shape_.m_.vertices_;

    for (auto& v : verts) {
        float scaled_world_x = pos.x_ * scale_;
        float scaled_world_y = pos.y_ * scale_;

        v.position.x = center_.x_ + scaled_world_x + v.position.x;
        v.position.y = center_.y_ - (scaled_world_y + v.position.y);
    }

    auto& indices =  ro.shape_.m_.indices_;
    SDL_RenderGeometry(renderer_, ro.shape_.m_.texture_, verts.data(), verts.size(), indices.data(), indices.size());
}

void Renderer::init_window() {
        SDL_CreateWindowAndRenderer("fyzix engine", kW, kH, SDL_WINDOW_FULLSCREEN, &window_, &renderer_);
        SDL_SetWindowPosition(window_, SDL_WINDOWPOS_CENTERED , SDL_WINDOWPOS_CENTERED);
        int w, h;
        SDL_GetWindowSize(window_, &w, &h);
        center_ = {w/2.f, h/2.f};
}

void Renderer::init_sdl() {
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::println("Error: init_sdl()");
    }
}

void Renderer::cleanup() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

SDL_Window* Renderer::get_window() const {
    return window_;
}

SDL_Renderer* Renderer::data() const {
    return renderer_;
}
