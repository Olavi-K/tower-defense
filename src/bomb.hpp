#pragma once
#include "projectile.hpp"

/**
 * @brief The projectile of the bomb tower.
 *
 */
class Bomb : public Projectile {
 public:
  Bomb(sf::Vector2f target, int damage, sf::Vector2f position);
};