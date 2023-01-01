#pragma once
#include "projectile.hpp"

/**
 * @brief The projectile of the basic tower.
 *
 */
class Bullet : public Projectile {
 public:
  Bullet(sf::Vector2f target, int damage, sf::Vector2f position);
};