#pragma once

#include <SFML/Graphics.hpp>

enum EnemyType { BasicEnemy = 0, BulkyEnemy, SplittingEnemy, FlyingEnemy };

class Enemy {
 private:
  sf::Sprite sprite;
  sf::Texture texture;
  float dir_x;
  float dir_y;
  float movementSpeed;

  bool slow_;

  int hp;
  int hpMax;
  sf::RectangleShape hpBar;
  sf::RectangleShape hpBarBack;

  void initHp(float x, float y);
  void initTexture();
  void initSprite(float x, float y);

  int type;

 public:
  Enemy(int type = EnemyType::BasicEnemy, float x = 0, float y = 150.f,
        float dir_x = 1.f, float dir_y = 0.f, float movementSpeed = 1.f);
  ~Enemy();

  // Accessor
  const sf::Vector2f& getPos() const;
  const sf::FloatRect getBounds() const;
  const int& getHp() const;
  const int& getHpMax() const;

  // Modifiers
  void setPosition(const sf::Vector2f pos);
  void setPosition(const float x, const float y);
  void setHp(const int hp);
  void loseHp(const int value);

  // Functions
  int getType() const;
  float getDirX() const;
  float getDirY() const;
  void setMovementDirection(float dir_x, float dir_y);
  void move(const float dirX, const float dirY);

  void updateMovement();
  void updateHp();
  void update();
  void render(sf::RenderTarget& target);
  void SlowDown();
};
