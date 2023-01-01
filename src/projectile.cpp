#include "projectile.hpp"

#include <cmath>
#include <iostream>

Projectile::Projectile() : target_(sf::Vector2f(500.f, 500.f)) {}

Projectile::Projectile(sf::Vector2f target, float speed, int damage,
                       sf::Vector2f position, bool aoe)
    : target_(target), speed_(speed), damage_(damage), aoe_(aoe) {
  setPosition(position.x, position.y);
}

Projectile::Projectile(const Projectile& projectile)
    : target_(projectile.target_),
      speed_(projectile.speed_),
      damage_(projectile.speed_) {
  setPosition(projectile.getPosition().x, projectile.getPosition().y);
}

sf::Vector2f Projectile::GetTarget() const { return target_; }

float Projectile::GetSpeed() const { return speed_; }

int Projectile::GetDamage() const { return damage_; }

void Projectile::UpdatePosition() {
  float exp = 0.5;
  float r =
      pow((target_.x - getPosition().x) * (target_.x - getPosition().x) +
              (target_.y - getPosition().y) * (target_.y - getPosition().y),
          exp);
  float x_move = speed_ * (target_.x - getPosition().x) / r;
  float y_move = speed_ * (target_.y - getPosition().y) / r;
  move(x_move, y_move);
}

float Projectile::DistancteToTarget() const {
  float exp = 0.5;
  return pow((target_.x - getPosition().x) * (target_.x - getPosition().x) +
                 (target_.y - getPosition().y) * (target_.y - getPosition().y),
             exp);
}

float Projectile::DistanceTo(sf::Vector2f target) const {
  float exp = 0.5;
  return pow((target.x - getPosition().x) * (target.x - getPosition().x) +
                 (target.y - getPosition().y) * (target.y - getPosition().y),
             exp);
}

bool Projectile::IsAOE() const { return aoe_; }

Projectile* Projectile::Clone() { return new Projectile(*this); }