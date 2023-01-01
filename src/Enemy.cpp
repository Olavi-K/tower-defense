#include "Enemy.h"

#include <iostream>

void Enemy::initTexture() {
  // Load a texture from file
  if (this->type == EnemyType::BasicEnemy) {
    if (!this->texture.loadFromFile("src/images/BasicEnemy.png")) {
      std::cout << "ERROR::Enemy::INITTEXTURE::Could not load texture file."
                << "\n";
    }
  } else if (this->type == EnemyType::SplittingEnemy) {
    if (!this->texture.loadFromFile("src/images/SplittingEnemy.png")) {
      std::cout << "ERROR::Enemy::INITTEXTURE::Could not load texture file."
                << "\n";
    }
  } else if(this->type == EnemyType::BulkyEnemy) {
    if (!this->texture.loadFromFile("src/images/bulkyEnemy.png")) {
      std::cout << "ERROR::Enemy::INITTEXTURE::Could not load texture file."
                << "\n";
    }
  } else if(this->type == EnemyType::FlyingEnemy) {
    if (!this->texture.loadFromFile("src/images/flyingEnemy.png")) {
      std::cout << "ERROR::Enemy::INITTEXTURE::Could not load texture file."
                << "\n";
    }
  }
}

void Enemy::initSprite(float x, float y) {
  // Set the texture to the sprite
  this->sprite.setTexture(this->texture);
  this->sprite.setPosition(x, y);
  // Resize the sprite
  this->sprite.scale(1.f, 1.f);
}

void Enemy::initHp(float x, float y) {
  if (this->type == EnemyType::BasicEnemy ||
      this->type == EnemyType::SplittingEnemy ||
      this->type == EnemyType::FlyingEnemy) {
    this->hpMax = 3;
  } else {
    this->hpMax = 10;
  }

  this->hp = this->hpMax;

  this->hpBar.setSize(sf::Vector2f(50.f, 8.f));
  this->hpBar.setFillColor(sf::Color::Red);
  this->hpBar.setPosition(sf::Vector2f(x, y - 25.f));

  this->hpBarBack = this->hpBarBack;
  this->hpBarBack.setFillColor(sf::Color(25, 25, 25, 200));
}

float Enemy::getDirX() const { return this->dir_x; }
float Enemy::getDirY() const { return this->dir_y; }

Enemy::Enemy(int type, float x, float y, float dir_x, float dir_y,
             float movementSpeed) {
  this->type = type;
  this->movementSpeed = movementSpeed;
  this->dir_x = dir_x;
  this->dir_y = dir_y;

  this->hpMax = hpMax;
  this->hp = this->hpMax;
  this->slow_ = false;

  this->initTexture();
  this->initSprite(x, y);

  this->initHp(x, y);
}

Enemy::~Enemy() {}

const sf::Vector2f& Enemy::getPos() const { return this->sprite.getPosition(); }

const sf::FloatRect Enemy::getBounds() const {
  return this->sprite.getGlobalBounds();
}

const int& Enemy::getHp() const { return this->hp; }

const int& Enemy::getHpMax() const { return this->hpMax; }

void Enemy::setPosition(const sf::Vector2f pos) {
  this->sprite.setPosition(pos);
}

void Enemy::setPosition(const float x, const float y) {
  this->sprite.setPosition(x, y);
}

void Enemy::setHp(const int hp) { this->hp = hp; }

void Enemy::loseHp(const int value) {
  this->hp -= value;
  if (this->hp < 0) this->hp = 0;
}

int Enemy::getType() const { return this->type; }

void Enemy::setMovementDirection(float dir_x, float dir_y) {
  this->dir_x = dir_x;
  this->dir_y = dir_y;
}

void Enemy::updateMovement() {
  this->hpBar.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);
  this->hpBarBack.move(this->movementSpeed * dir_x,
                       this->movementSpeed * dir_y);
  this->sprite.move(this->movementSpeed * dir_x, this->movementSpeed * dir_y);
}

void Enemy::updateHp() {
  float hpPercent = static_cast<float>(hp) / hpMax;
  this->hpBar.setSize(sf::Vector2f(50.f * hpPercent, this->hpBar.getSize().y));
}

// Functions
void Enemy::update() {
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) move(-1.f, 0.f);
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) move(1.f, 0.f);
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) move(0.f, -1.f);
  // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) move(0.f, 1.f);
  updateMovement();
  updateHp();
}

void Enemy::render(sf::RenderTarget& target) {
  target.draw(this->sprite);
  target.draw(this->hpBar);
  target.draw(this->hpBarBack);
}

void Enemy::SlowDown() {
  if (!slow_) {
    slow_ = true;
    movementSpeed = 0.5 * movementSpeed;
  }
}