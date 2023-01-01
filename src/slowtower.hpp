#pragma once
#include "icebullet.hpp"
#include "tower.hpp"

/**
 * @brief class SlowTower slows down the enemy that it hits. It can hit any type
 * of enemy and does no damage.
 *
 */
class SlowTower : public Tower {
 public:
  /**
   * @brief Construct a new Slow Tower object
   *
   * @param position
   */
  SlowTower(sf::Vector2i position);
  SlowTower(const SlowTower& tower);
  virtual std::shared_ptr<Projectile> Shoot(std::shared_ptr<Enemy> enemy);
};