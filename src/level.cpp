#include "level.h"

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "levelTile.h"

Level::Level() {
  gridLenght = 10;
  money_ = 500;
  counter_ = 0;
}

Level::Level(std::string layout, std::string waves) {
  gameStatus = 2;

  std::ifstream ifs(layout);
  int gridLength = 10;
  map = "";
  if(ifs.is_open()) {
    ifs >> gridLength;
    for(int i = 0; i < gridLength; i++) {
      std::string line;
      ifs >> line;
      map = map + line;
    }
  }

  std::ifstream ifs2(waves);
  std::string str = "";
  if(ifs2.is_open()) {
    ifs2 >> str;
    if(str == "Enemies") {
      int amount;
      ifs2 >> amount;
      for (int i = 0; i < amount; i++) {
        int type;
        float time;
        ifs2 >> type >> time;
        wave.push(std::make_pair(type, time));
        //std::cout << "type: " << type <<  "time: "  << time << std::endl;
      }
    }
  }

  // wave.push(std::make_pair(EnemyType::BasicEnemy,0.3f));
  // wave.push(std::make_pair(EnemyType::SplittingEnemy, 2.f));
  // wave.push(std::make_pair(EnemyType::BulkyEnemy, 2.5f));
  // wave.push(std::make_pair(EnemyType::FlyingEnemy, 3.f));
  gridLenght = 10;
  setUpInitialState(map);
  money_ = 500;
  GuiBarTexture.loadFromFile("src/images/GuiBar.png");
  PlayButtonTexture.loadFromFile("src/images/start.png");
  BackButtonTexture.loadFromFile("src/images/back.png");
  font.loadFromFile("src/font/PixellettersFull.ttf");

  GuiBarSprite.setTexture(GuiBarTexture);
  GuiBarSprite.setPosition(sf::Vector2f(500.f,0.f));
  PlayButtonSprite.setTexture(PlayButtonTexture);
  PlayButtonSprite.setPosition(sf::Vector2f(540.f, 425.f));
  BackButtonSprite.setTexture(BackButtonTexture);
  BackButtonSprite.setPosition(sf::Vector2f(620.f, 425.f));
  BuyBasicButton.setRadius(25.f);
  BuyBombButton.setRadius(25.f);
  BuySlowButton.setRadius(25.f);
  BuyBasicButton.setFillColor(sf::Color::Yellow);
  BuyBombButton.setFillColor(sf::Color::Black);
  BuySlowButton.setFillColor(sf::Color::Cyan);
  BuyBasicButton.setPosition(sf::Vector2f(520.f,175.f));
  BuyBombButton.setPosition(sf::Vector2f(520.f,250.f));
  BuySlowButton.setPosition(sf::Vector2f(520.f,325.f));
  BasicCost.setString("Shooting Tower:\nPrice: $100\nUpgrade: $200");
  BasicCost.setFillColor(sf::Color::Black);
  BasicCost.setPosition(sf::Vector2f(575.f, 165.f));
  BasicCost.setFont(font);
  BasicCost.setCharacterSize(20);
  BombCost.setString("Bomb Tower:\nPrice: $200\nUpgrade: $300");
  BombCost.setFillColor(sf::Color::Black);
  BombCost.setPosition(sf::Vector2f(575.f, 240.f));
  BombCost.setFont(font);
  BombCost.setCharacterSize(20);
  SlowCost.setString("Slow Tower:\nPrice: $150\nUpgrade: NA");
  SlowCost.setFillColor(sf::Color::Black);
  SlowCost.setPosition(sf::Vector2f(575.f, 315.f));
  SlowCost.setFont(font);
  SlowCost.setCharacterSize(20);
  start_ = true;

  buffer_.loadFromFile("src/images/Pew!.wav");
  sound_.setBuffer(buffer_);
}

Level::~Level() {
  // for (auto tower : towers_) {
  //   delete tower;
  // }
  // for (auto projectile : projectiles_) {
  //   delete projectile;
  // }
  // for (auto enemy : enemies_) {
  //   delete enemy;
  // }
  // for (auto row : tiles) {
  //   for (auto tile : row) {
  //     delete tile;
  //   }
  // }
}

void Level::setUpInitialState(std::string map) {
  setUpTiles(map);
}

void Level::setUpTiles(std::string map) {
  tiles.clear();
  for (int i = 0; i < this->gridLenght; i++) {
    std::vector<std::shared_ptr<levelTile>> row;
    for (int j = 0; j < this->gridLenght; j++) {
      if (map[i * this->gridLenght + j] == '#') {
        row.push_back(std::make_shared<levelTile>(
            "src/images/grass.png", j * 50, i * 50, levelTileType::GRASS));
      } else if (map[i * this->gridLenght + j] == 'p') {
        row.push_back(std::make_shared<levelTile>("src/images/path.png", j * 50,
                                                  i * 50, levelTileType::PATH));
      } else if (map[i * this->gridLenght + j] == 'g') {
        row.push_back(std::make_shared<levelTile>("src/images/path.png", j * 50,
                                                  i * 50, levelTileType::HOME));
        sf::Vector2f vec(j * 50 + 25, i * 50 + 25);
        homePosition = vec;
      } else if (map[i * this->gridLenght + j] == '*') {
        row.push_back(std::make_shared<levelTile>(
            "src/images/path.png", j * 50, i * 50, levelTileType::TOWER_POINT));
      } else if (map[i * this->gridLenght + j] == '-') {
        row.push_back(std::make_shared<levelTile>(
            "src/images/path.png", j * 50, i * 50, levelTileType::SPAWN_POINT));
        sf::Vector2f vec(j * 50, i * 50);
        spwanPoints.push_back(vec);
      }
    }
    tiles.push_back(row);
  }

  // log the map
  // for (int i = 0; i < this->gridLenght; i++) {
  //   for (int j = 0; j < this->gridLenght; j++) {
  //     std::cout << tiles[i][j]->getType();
  //   }
  //     std::cout << std::endl;
  //   }
}

int Level::getLeftEmenies() const {
  return wave.size();
}

std::string Level::GetMap() const {
  return map;
}

int Level::getGameStatus() const { return gameStatus; }

sf::Vector2f Level::getHomePosition() const {
  return homePosition;
}

std::vector<sf::Vector2f> Level::getSpwanPoints() const {
  return spwanPoints;
}

int Level::getTileTypeByPos(const float x, const float y) const {
  return tiles[static_cast<int>(y / 50.f)][static_cast<int>(x / 50.f)]
      ->getType();
}

void Level::AddTower(std::shared_ptr<Tower> tower) { towers_.push_back(tower); }
int Level::GetTowerAmount() const { return towers_.size(); }
std::vector<std::shared_ptr<Tower>> Level::GetTowers() const { return towers_; }

void Level::AddEnemy(std::shared_ptr<Enemy> enemy) {
  enemies_.push_back(enemy);
}
std::vector<std::shared_ptr<Enemy>> Level::GetEnemies() const {
  return enemies_;
}

void Level::AddProjectile(std::shared_ptr<Projectile> projectile) {
  projectiles_.push_back(projectile);
}
int Level::GetProjectileAmount() const { return projectiles_.size(); }
std::vector<std::shared_ptr<Projectile>> Level::GetProjectiles() const {
  return projectiles_;
}

void Level::UpdateTowerType(std::string type) { towertype_ = type; }

std::string Level::GetTowerType() const { return towertype_; }

bool Level::UpdateMoney(int n) {
  if (money_ + n < 0) {
    return false;
  }
  money_ += n;
  return true;
}

int Level::GetMoney() const { return money_; }

void Level::updateEnemies() {
  
  if (!wave.empty()) {
    float tmpTime = clock.getElapsedTime().asSeconds();
    srand (time(0));
    while (ctime <= wave.front().second && tmpTime >= wave.front().second) {
      int index = rand() % spwanPoints.size();
      AddEnemy(std::make_shared<Enemy>(wave.front().first, spwanPoints[index].x, spwanPoints[index].y));    // spwan points can be optimzed
      wave.pop();
    }
    ctime = tmpTime;
  }

  for (int i = 0; i < enemies_.size(); i++) {
      float dir_x = enemies_[i]->getDirX();
      float dir_y = enemies_[i]->getDirY();
      float pos_x = enemies_[i]->getPos().x;
      float pos_y = enemies_[i]->getPos().y;
      float width = enemies_[i]->getBounds().width;
      float height = enemies_[i]->getBounds().height;
    if(enemies_[i]->getType() != EnemyType::FlyingEnemy) {
      float offset = 1.f;
      float boud_x = dir_x >= 0.f ? pos_x + width * dir_x : pos_x - offset;
      float boud_y = dir_y >= 0.f ? pos_y + height * dir_y : pos_y - offset;

      if (getTileTypeByPos(boud_x, boud_y) != levelTileType::PATH &&
          getTileTypeByPos(boud_x, boud_y) != levelTileType::HOME) {
        enemies_[i]->setMovementDirection(0.f, 0.f);
        if (dir_x == 0.f) {
          if (getTileTypeByPos(pos_x - offset, pos_y) == levelTileType::PATH) {
            enemies_[i]->setMovementDirection(-1.f, 0.f);
          } else if (getTileTypeByPos(pos_x + width + offset, pos_y) ==
                     levelTileType::PATH) {
            enemies_[i]->setMovementDirection(1.f, 0.f);
          }
        }
        if (dir_y == 0.f) {
          if (getTileTypeByPos(pos_x, pos_y - offset) == levelTileType::PATH) {
            enemies_[i]->setMovementDirection(0.f, -1.f);
          } else if (getTileTypeByPos(pos_x, pos_y + height + offset) ==
                     levelTileType::PATH) {
            // std::cout << "run";
            enemies_[i]->setMovementDirection(0.f, 1.f);
          }
        }
      }
    } 
    else {  // when it is flying enemy
      float total = pos_x  + width / 2 - homePosition.x + pos_y  + height / 2 - homePosition.y;
      enemies_[i]->setMovementDirection((pos_x + width / 2 - homePosition.x) / total, (pos_y + height / 2 - homePosition.y) / total);      // pos_x - homePosition.x 
      // std::cout << homePosition.x << homePosition.y ;
    }
    // stop moving when arriving home
    if (getTileTypeByPos(pos_x + width / 2, pos_y + height / 2) == levelTileType::HOME) {
      gameStatus = 0;
    }
    enemies_[i]->update();
    if (enemies_[i]->getHp() <= 0) {
      if (enemies_[i]->getType() == EnemyType::SplittingEnemy) {
        AddEnemy(std::make_shared<Enemy>(EnemyType::BasicEnemy,
                                         pos_x - dir_x * 20.f,
                                         pos_y - dir_y * 20.f, dir_x, dir_y));

        AddEnemy(std::make_shared<Enemy>(EnemyType::BasicEnemy, pos_x, pos_y,
                                         dir_x, dir_y));
      }
      this->enemies_.erase(this->enemies_.begin() + i);
      money_ += 50;
    }
  }

  //  when the wave and emenies are empty, the game is won
  if (enemies_.size() == 0 && wave.size() == 0) {
    gameStatus = 1;
  }
  if ((enemies_.size() == 0 && wave.size() > 0) && start_) {
      gameStatus = 3;
  }
}

void Level::render(sf::RenderTarget& target) {
  // Render map, should be the frist to avoid covering other things
  for (int i = 0; i < this->gridLenght; i++) {
    for (int j = 0; j < this->gridLenght; j++) {
      target.draw(this->tiles[i][j]->sprite);
    }
  }

  for (int i = 0; i < towers_.size(); i++) {
    target.draw((*towers_.at(i)));
  }

  for (int i = 0; i < projectiles_.size(); i++) {
    target.draw((*projectiles_.at(i)));
    if (projectiles_.at(i)->DistancteToTarget() <= 10.f) {
      if (enemies_.size() != 0) {
        if (projectiles_.at(i)->IsAOE()) {
          for (auto enemy : enemies_) {
            if (projectiles_.at(i)->DistanceTo(enemy->getPos()) < 30.f) {
              enemy->loseHp(projectiles_.at(i)->GetDamage());
            }
          }
        } else if (projectiles_.at(i)->GetDamage() == 0) {
          for (auto enemy : enemies_) {
            if (projectiles_.at(i)->DistanceTo(enemy->getPos()) < 50.f) {
              enemy->SlowDown();
              break;
            }
          } 
        } else {
          for (auto enemy : enemies_) {
            if (projectiles_.at(i)->DistanceTo(enemy->getPos()) < 50.f) {
              enemy->loseHp(projectiles_.at(i)->GetDamage());
              break;
          }
        }
      }
    }
      auto it = projectiles_.begin() + i;
      projectiles_.erase(it);
    }
  }

  // Render enimes
  for (auto enemy : this->enemies_) {
    enemy->render(target);
  }

  target.draw(GuiBarSprite);
  target.draw(PlayButtonSprite);
  target.draw(BackButtonSprite);
  target.draw(BuyBasicButton);
  target.draw(BuyBombButton);
  target.draw(BuySlowButton);
  target.draw(BasicCost);
  target.draw(BombCost);
  target.draw(SlowCost);
}

int Level::update(sf::RenderWindow& window) {

  if (gameStatus == 2) {
    updateEnemies();
    counter_ += 1;
    if ((counter_ % 60 == 0) && (enemies_.size() != 0)) {
      for (int i = 0; i < towers_.size(); i++) {
        for (auto enemy : enemies_){
          if (towers_.at(i)->DistanceTo(enemy->getPos()) < towers_.at(i)->GetRange()) {
            AddProjectile(towers_[i]->Shoot(enemy));
            sound_.play();
            break;
          }
        }
      }
    }
    for (int i = 0; i < projectiles_.size(); i++) {
      projectiles_[i]->UpdatePosition();
    }
  }
  if ((event_.type == sf::Event::MouseButtonPressed && PlayButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) && lock_click_ != true) {
    gameStatus = 2;
    start_ = false;
    clock.restart();
    }

  if ((event_.type == sf::Event::MouseButtonPressed && BackButtonSprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) && lock_click_ != true) {
      return 0;
    }
  
  if ((event_.type == sf::Event::MouseButtonPressed && BuyBasicButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) && lock_click_ != true) {
      UpdateTowerType("BasicTower");
    }

    else if ((event_.type == sf::Event::MouseButtonPressed && BuyBombButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) && lock_click_ != true) {
      UpdateTowerType("BombTower");
    }

    else if ((event_.type == sf::Event::MouseButtonPressed && BuySlowButton.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) && lock_click_ != true) {
      UpdateTowerType("SlowTower");
    }

    else if ((event_.type == sf::Event::KeyPressed) &&
             (event_.key.code == sf::Keyboard::Escape)) {
      UpdateTowerType("");
    }

    if ((event_.type == sf::Event::MouseButtonPressed && sf::Mouse::getPosition(window).x < 500) && lock_click_ != true) {
      if (GetTowerType() == "BasicTower") {
        if (UpdateMoney(-100)) {
          AddTower(
              std::make_shared<BasicTower>(sf::Mouse::getPosition(window) - sf::Vector2i(25.f,25.f)));
          UpdateTowerType("");
          lock_click_ = true;
        }
      } else if (GetTowerType() == "BombTower") {
        if (UpdateMoney(-200)) {
          AddTower(
              std::make_shared<BombTower>(sf::Mouse::getPosition(window) - sf::Vector2i(25.f,25.f)));
          UpdateTowerType("");
          lock_click_ = true;
        }
      } else if (GetTowerType() == "SlowTower") {
        if (UpdateMoney(-150)) {
          AddTower(
              std::make_shared<SlowTower>(sf::Mouse::getPosition(window) - sf::Vector2i(25.f,25.f)));
          UpdateTowerType("");
          lock_click_ = true;
        }
      }
    }

    if (event_.type == sf::Event::MouseButtonPressed && lock_click_ != true) {
      for (auto tower : towers_) {
        if (tower->getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
          if (UpdateMoney(-tower->GetUpgradeCost())) {
            if (!tower->LevelUp()) {
              UpdateMoney(tower->GetUpgradeCost());
            }
            lock_click_ = true;
          }
        }
      }
    }

    if (event_.type == sf::Event::MouseButtonReleased) {
      lock_click_ = false;
    }
    return 1;
}

void Level::UpdateEvent(sf::Event event) {
  event_ = event;
}
