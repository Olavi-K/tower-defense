#include "icebullet.hpp"

IceBullet::IceBullet(sf::Vector2f target, int damage, sf::Vector2f position)
    : Projectile(target, 20.f, damage, position, false) {
  setRadius(10);
  setFillColor(sf::Color::Cyan);
}