#ifndef BOXCOLLIDER_H
#define BOXCOLLIDER_H

#include "entityx/Entity.h"

namespace arrakis
{

namespace components
{

struct Collision
{
    Collision(const struct BoxCollider & other_collider,
              const struct Position & other_position,
              const struct entityx::Entity & other_entity)
        : other_collider(other_collider),
          other_position(other_position),
          other_entity(other_entity) {}

    const BoxCollider & other_collider;
    const Position & other_position;
    const entityx::Entity & other_entity;
};

struct BoxCollider
{
    BoxCollider(float x_min, float x_max, float y_min, float y_max,
                bool enabled_vertical = true, bool enabled_horizontal = true,
                bool is_static = false)
        : x_min(x_min),
          x_max(x_max),
          y_min(y_min),
          y_max(y_max),
          enabled_vertical(enabled_vertical),
          enabled_horizontal(enabled_horizontal),
          is_static(is_static) {}

    bool is_static, enabled_vertical, enabled_horizontal;
    float x_min, x_max, y_min, y_max;

    std::function<void(Collision)> on_collision = nullptr;

    bool airborn;
};

} // end components
} // end arrakis

#endif // BOXCOLLIDER_H
