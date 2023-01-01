#include "levelTile.h"

levelTile::levelTile(std::string textureName, float x, float y, int type) {
  if (!setUpSprite(textureName)) {
    return;
  }
  sprite.setPosition(sf::Vector2f(x, y));
  this->type = type;
}

bool levelTile::setUpSprite(std::string textureName) {
  if (!texture.loadFromFile(textureName)) {
    return false;
  }
  texture.setSmooth(true);
  sprite.setTexture(texture);
  // sprite.setTextureRect(sf::IntRect(0, 0, 50, 50));
  // this->sprite.scale(2.f, 2.f);
  return true;
}

int levelTile::getType() const {
  return this->type;
}

const sf::FloatRect levelTile::getGlobalBounds() const {
  return this->sprite.getGlobalBounds();
}