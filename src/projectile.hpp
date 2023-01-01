#pragma once
#include <SFML/Graphics.hpp>

/**
 * @brief The projectile class defines objects that the towers shoot.
 *
 */
class Projectile : public sf::CircleShape {
 public:
  Projectile();

  ~Projectile() {}

  Projectile(sf::Vector2f target, float speed, int damage,
             sf::Vector2f position, bool aoe);
  Projectile(const Projectile& projectile);

  sf::Vector2f GetTarget() const;

  float GetSpeed() const;

  int GetDamage() const;

  void UpdatePosition();

  float DistancteToTarget() const;

  float DistanceTo(sf::Vector2f target) const;

  bool IsAOE() const;

  Projectile* Clone();

 private:
  sf::Vector2f target_;
  float speed_;
  int damage_;
  bool aoe_;
};