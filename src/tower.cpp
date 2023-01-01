#include "tower.hpp"
#include <iostream>

Tower::Tower(int damage, int range, int firerate, int upgrade_cost, int max_level,
             sf::Vector2i position)
    : damage_(damage),
      range_(range),
      firerate_(firerate),
      upgrade_cost_(upgrade_cost),
      max_level_(max_level),
      level_(1) {
  setPosition(position.x, position.y);
}

Tower::Tower(const Tower& tower)
    : damage_(tower.damage_),
      range_(tower.range_),
      firerate_(tower.firerate_),
      upgrade_cost_(tower.upgrade_cost_),
      max_level_(tower.max_level_),
      level_(tower.level_) {
  setPosition(tower.getPosition().x, tower.getPosition().y);
}

Tower::~Tower() = default;

int Tower::GetDamage() const { return damage_; }

int Tower::GetRange() const { return range_; }

int Tower::GetLevel() const { return level_; }

int Tower::GetUpgradeCost() const { return upgrade_cost_; }

bool Tower::LevelUp() {
  if (level_ < max_level_) {
    level_ += 1;
    damage_ += damage_buff_;
    return true;
  }
  return false;
}

float Tower::DistanceTo(sf::Vector2f target) const {
  float exp = 0.5;
  return pow((target.x - getPosition().x) * (target.x - getPosition().x) +
                 (target.y - getPosition().y) * (target.y - getPosition().y),
             exp);
}


Tower& Tower::operator=(const Tower& tower) { return *this; }
