#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

#include "Enemy.h"
#include "basictower.hpp"
#include "bomb.hpp"
#include "bombtower.hpp"
#include "bullet.hpp"
#include "icebullet.hpp"
#include "levelTile.h"
#include "slowtower.hpp"

class Level {
  std::vector<std::shared_ptr<Tower>> towers_;
  bool lock_click_;
  int counter_;
  sf::Event event_;
  sf::Texture GuiBarTexture;
  sf::Sprite GuiBarSprite;
  sf::Texture PlayButtonTexture;
  sf::Sprite PlayButtonSprite;
  sf::Texture BackButtonTexture;
  sf::Sprite BackButtonSprite;
  bool start_;
  sf::CircleShape BuyBasicButton;
  sf::CircleShape BuyBombButton;
  sf::CircleShape BuySlowButton;
  sf::Text BasicCost;
  sf::Text BombCost;
  sf::Text SlowCost;
  sf::Font font;
  std::string map;
  sf::SoundBuffer buffer_;
  sf::Sound sound_;

  sf::Vector2f homePosition;
  std::vector<sf::Vector2f> spwanPoints;
  int gameStatus;  // 0 lost   1 win   2 palying

  sf::Clock clock;
  float ctime;

  std::queue<std::pair<int, float>> wave;
  std::vector<std::shared_ptr<Enemy>> enemies_;
  std::vector<std::shared_ptr<Projectile>> projectiles_;
  std::string towertype_;
  int money_;
  void setUpInitialState(std::string);
  void setUpTiles(std::string);

 public:
  std::vector<std::vector<std::shared_ptr<levelTile>>> tiles;
  int gridLenght;
  Level(std::string, std::string);
  Level();
  ~Level();
  sf::Vector2f getHomePosition() const;
  std::vector<sf::Vector2f> getSpwanPoints() const;
  int getLeftEmenies() const;
  int getGameStatus() const;
  void AddTower(std::shared_ptr<Tower>);
  int GetTowerAmount() const;
  std::vector<std::shared_ptr<Tower>> GetTowers() const;
  void AddEnemy(std::shared_ptr<Enemy>);
  std::vector<std::shared_ptr<Enemy>> GetEnemies() const;
  void AddProjectile(std::shared_ptr<Projectile>);
  int GetProjectileAmount() const;
  std::vector<std::shared_ptr<Projectile>> GetProjectiles() const;
  void UpdateTowerType(std::string);
  std::string GetTowerType() const;
  bool UpdateMoney(int);
  int GetMoney() const;

  /**
   * @brief Get the Tile Type By Pos object
   *
   * @param x
   * @param y
   * @return int
   */
  int getTileTypeByPos(const float x, const float y) const;
  void updateEnemies();
  int update(sf::RenderWindow& window);
  void render(sf::RenderTarget& target);

  void UpdateEvent(sf::Event event);

  std::string GetMap() const;
};
