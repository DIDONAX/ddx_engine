#include "utils.h"

void to_cartesian(vec2& pos, int scale) {
    pos.x_ = (pos.x_ - center_x)/scale;
    pos.y_ = (center_y - pos.y_)/scale;
};
