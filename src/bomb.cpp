#include "bomb.hpp"

Bomb::Bomb(sf::Vector2f target, int damage, sf::Vector2f position)
    : Projectile(target, 10.f, damage, position, true) {
  setRadius(10);
  setFillColor(sf::Color::Black);
}