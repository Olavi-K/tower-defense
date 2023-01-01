#pragma once
#include <SFML/Graphics.hpp>

enum levelTileType {SPAWN_POINT = 0, HOME, PATH, TOWER_POINT, GRASS };

class levelTile {
 public:
  sf::Texture texture;
  sf::Sprite sprite;
  int type;

  levelTile(std::string, float, float, int);

  bool setUpSprite(std::string);

  const sf::FloatRect getGlobalBounds() const;
  int getType() const;
};