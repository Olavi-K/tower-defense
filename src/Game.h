#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>

#include "level.h"
#include "levelTile.h"

/*
        Class that acts as the game engine.
        Wrapper class.
*/

class Game {
 private:
  // Variables
  // Window
  sf::RenderWindow* window;
  sf::VideoMode videoMode;
  sf::Event ev;
  int jumpback;

  sf::Font font;
  sf::Text guiText;
  sf::Text endGameText;

  std::shared_ptr<Level> level;

  std::shared_ptr<Level> level0;

  sf::Texture level1Texture;
  sf::Sprite level1Sprite;
  sf::Texture level2Texture;
  sf::Sprite level2Sprite;
  sf::Texture level3Texture;
  sf::Sprite level3Sprite;
  sf::Texture level4Texture;
  sf::Sprite level4Sprite;
  sf::Texture level5Texture;
  sf::Sprite level5Sprite;

  // Private functions
  void initVariables();
  void initWindow();
  void initLevel();
  void initFonts();
  void initGui();

 public:
  // Constructors / Destructors
  Game();
  virtual ~Game();

  // Accessors
  const bool running() const;

  // Functions
  void pollEvents();
  void updateGui();
  void update();
  void renderGui(sf::RenderTarget* target);
  void render();
};
