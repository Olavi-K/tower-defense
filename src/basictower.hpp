#pragma once
#include "Enemy.h"
#include "bullet.hpp"
#include "tower.hpp"

/**
 * @brief class BasicTower is the most basic type of tower. It can hit any type
 * of enemy and does 1 HP of damage every hit.
 *
 *
 */

class BasicTower : public Tower {
 public:
  /**
   * @brief Construct a new Basic Tower object
   *
   * @param position
   */
  BasicTower(sf::Vector2i position);
  BasicTower(const BasicTower& tower);

  virtual std::shared_ptr<Projectile> Shoot(std::shared_ptr<Enemy> enemies);
};
