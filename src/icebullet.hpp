#pragma once
#include "projectile.hpp"

/**
 * @brief The projectile of the slow tower.
 *
 */
class IceBullet : public Projectile {
 public:
  IceBullet(sf::Vector2f target, int damage, sf::Vector2f position);
};