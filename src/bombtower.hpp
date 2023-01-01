#pragma once
#include "bomb.hpp"
#include "tower.hpp"

/**
 * @brief class BombTower throws bombs that damages all enemies within a certain
 * range of the explosion. It can only hit grounded enemies and does 1 HP of
 * damage to everyone hit.
 *
 */
class BombTower : public Tower {
 public:
  /**
   * @brief Construct a new Bomb Tower object
   *
   * @param position
   */
  BombTower(sf::Vector2i position);
  BombTower(const BombTower& tower);

  virtual std::shared_ptr<Projectile> Shoot(std::shared_ptr<Enemy> enemy);
};