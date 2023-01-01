#include "bombtower.hpp"

BombTower::BombTower(sf::Vector2i position) : Tower(1, 200, 1, 300, 3, position) {
  setRadius(25.f);
  setFillColor(sf::Color::Black);
  setPosition(position.x, position.y);
  damage_buff_ = 1;
}

BombTower::BombTower(const BombTower& tower) : Tower(tower) {
  setRadius(20.f);
  setFillColor(sf::Color::Cyan);
  setPosition(tower.getPosition().x, tower.getPosition().y);
  damage_buff_ = 1;
}

std::shared_ptr<Projectile> BombTower::Shoot(
    std::shared_ptr<Enemy> enemy) {
  return std::make_shared<Bomb>(enemy->getPos(), damage_, getPosition());
}
