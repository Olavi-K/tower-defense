#include "basictower.hpp"

BasicTower::BasicTower(sf::Vector2i position) : Tower(1, 200, 1, 200, 3, position) {
  setRadius(25.f);
  setFillColor(sf::Color::Yellow);
  setPosition(position.x, position.y);
  damage_buff_ = 1;
}

BasicTower::BasicTower(const BasicTower& tower) : Tower(tower) {
  setRadius(20.f);
  setFillColor(sf::Color::Yellow);
  setPosition(tower.getPosition().x, tower.getPosition().y);
  damage_buff_ = 1;
}

std::shared_ptr<Projectile> BasicTower::Shoot(
  std::shared_ptr<Enemy> enemy) {
  return std::make_shared<Bullet>(enemy->getPos(), damage_, getPosition());
}