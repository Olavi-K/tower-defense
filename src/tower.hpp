#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <memory>
#include <tuple>
#include <vector>

#include "Enemy.h"
#include "projectile.hpp"

/**
 * @brief class Tower is the abstract parent class of all different types of
 * towers. Each Tower object has a damage, a range, a position, and a level.
 *
 */

class Tower : public sf::CircleShape {
 public:
  /**
   * @brief Construct a new Tower object
   *
   * @param damage
   * @param range
   * @param position
   */
  Tower(int damage, int range, int firerate, int upgrade_cost, int max_level,
        sf::Vector2i position);

  /**
   * @brief Destroy the Tower object
   *
   */
  ~Tower();

  /**
   * @brief Copy constructor for a new Tower object
   *
   * @param tower
   */
  Tower(const Tower& tower);

  /**
   * @brief Get the Damage object
   *
   * @return int
   */
  int GetDamage() const;

  /**
   * @brief Get the Range object
   *
   * @return int
   */
  int GetRange() const;

  /**
   * @brief Get the Level object
   *
   * @return int
   */
  int GetLevel() const;

  int GetUpgradeCost() const;

  /**
   * @brief Upgrade the tower. Returns true if upgrade
   * was succesful, i.e. not already max level and player
   * has enough money.
   *
   * @return true
   * @return false
   */
  bool LevelUp();

  virtual std::shared_ptr<Projectile> Shoot(std::shared_ptr<Enemy>) = 0;

  /**
   * @brief Copy assignment operator.
   *
   * @param tower
   * @return Tower&
   */
  Tower& operator=(const Tower& tower);

  float DistanceTo(sf::Vector2f target) const;

 protected:
  int damage_;
  int range_;
  int firerate_;
  int max_level_;
  int level_;
  int damage_buff_;
  int upgrade_cost_;
};