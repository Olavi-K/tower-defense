#include "slowtower.hpp"

SlowTower::SlowTower(sf::Vector2i position) : Tower(0, 300, 1, 0, 1, position) {
  setRadius(25.f);
  setFillColor(sf::Color::Cyan);
  setPosition(position.x, position.y);
  damage_buff_ = 0;
}

SlowTower::SlowTower(const SlowTower& tower) : Tower(tower) {
  setRadius(20.f);
  setFillColor(sf::Color::Cyan);
  setPosition(tower.getPosition().x, tower.getPosition().y);
  damage_buff_ = 1;
}

std::shared_ptr<Projectile> SlowTower::Shoot(
    std::shared_ptr<Enemy> enemy) {
  return std::make_shared<IceBullet>(enemy->getPos(), damage_, getPosition());
}