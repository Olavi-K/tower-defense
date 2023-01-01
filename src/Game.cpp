#include "Game.h"

// Private functions
void Game::initVariables() { this->window = nullptr; }

void Game::initLevel() {

  level0 = std::make_shared<Level>("src/configs/map0.ini","src/configs/level0.ini");
  // level1 = std::make_shared<Level>("src/configs/map1.ini","src/configs/level1.ini");
  // level2 = std::make_shared<Level>("src/configs/map2.ini","src/configs/level2.ini");
  // level3 = std::make_shared<Level>("src/configs/map1.ini","src/configs/level3.ini");
  // level4 = std::make_shared<Level>("src/configs/map1.ini","src/configs/level4.ini");
  // level5 = std::make_shared<Level>("src/configs/map1.ini","src/configs/level5.ini");

  this->level = level0;
  
  // this->level = new Level(
  //     "##########"
  //     "#ppp#ppp##"
  //     "#p#p#p#p##"
  //     "-p#ppp#p##"
  //     "#######p##"
  //     "###*#ppp##"
  //     "#####p####"
  //     "###*#ppp##"
  //     "#######p##"
  //     "#######g##");
}

void Game::initWindow() {
  this->videoMode.height = 500;
  this->videoMode.width = 700;

  this->window = new sf::RenderWindow(this->videoMode, "Game 1",
                                      sf::Style::Titlebar | sf::Style::Close);
  this->window->setFramerateLimit(60);
  window->setKeyRepeatEnabled(false);
}

void Game::initFonts() {
  if (!this->font.loadFromFile("src/font/PixellettersFull.ttf")) {
    std::cout
        << " ! ERROR::GAME::INITFONTS::COULD NOT LOAD PixellettersFull.ttf"
        << "\n";
  }
}

void Game::initGui() {
  // if
  // (!this->font.loadFromFile("C:/Users/kunre/Desktop/SFML_C-_Simple_Games-master/SFML_C++_Simple_Games/SFML_C++_Simple_Games/Fonts/PixellettersFull.ttf"))
  // {
  // 	std::cout << " ! ERROR::GAME::INITFONTS::COULD NOT LOAD
  // PixellettersFull.ttf" << "\n";
  // }
  this->guiText.setFont(this->font);
  this->guiText.setFillColor(sf::Color::Black);
  this->guiText.setCharacterSize(32);
  guiText.setPosition(sf::Vector2f(520.f,20.f));

  // End game text
  this->endGameText.setFont(this->font);
  this->endGameText.setFillColor(sf::Color::Black);
  this->endGameText.setCharacterSize(60);
  this->endGameText.setPosition(sf::Vector2f(20, 100));
  this->endGameText.setString("You lost!");

  level1Texture.loadFromFile("src/images/one.png");
  level2Texture.loadFromFile("src/images/two.png");
  level3Texture.loadFromFile("src/images/three.png");
  level4Texture.loadFromFile("src/images/four.png");
  level5Texture.loadFromFile("src/images/five.png");

  level1Sprite.setTexture(level1Texture);
  level1Sprite.setPosition(sf::Vector2f(100.f,200.f));
  level2Sprite.setTexture(level2Texture);
  level2Sprite.setPosition(sf::Vector2f(200.f,200.f));
  level3Sprite.setTexture(level3Texture);
  level3Sprite.setPosition(sf::Vector2f(300.f,200.f));
  level4Sprite.setTexture(level4Texture);
  level4Sprite.setPosition(sf::Vector2f(150.f,300.f));
  level5Sprite.setTexture(level5Texture);
  level5Sprite.setPosition(sf::Vector2f(250.f,300.f));
}

// Constructors / Destructors
Game::Game() {
  this->initVariables();
  this->initWindow();
  this->initFonts();
  this->initGui();
  this->initLevel();
  //level->AddTower(std::make_shared<BasicTower>(sf::Vector2i(100, 100)));
}

Game::~Game() { delete this->window; }

// Accessors
const bool Game::running() const { return this->window->isOpen(); }

// Functions
void Game::pollEvents() {
  // Event polling
  while (this->window->pollEvent(this->ev)) {
    switch (this->ev.type) {
      case sf::Event::Closed:
        this->window->close();
        break;
    }
  }
}

void Game::updateGui() {
  std::stringstream ss;

  ss << "Money: $" << level->GetMoney() << "\n";
  ss << "Approaching\nenemies: " << level->getLeftEmenies() << "\n";
  this->guiText.setString(ss.str());
}

void Game::update() {
  this->pollEvents();
  level->UpdateEvent(ev);
  jumpback = level->update(*window);
  this->updateGui();

  if (jumpback == 0) {
    level = level0;
  }
  if (level->GetMap() == level0->GetMap()){
  if (ev.type == sf::Event::MouseButtonPressed && level1Sprite.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
    level = std::make_shared<Level>("src/configs/map1.ini","src/configs/level1.ini");
  }
  if (ev.type == sf::Event::MouseButtonPressed && level2Sprite.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
    level = std::make_shared<Level>("src/configs/map2.ini","src/configs/level2.ini");
  }
  if (ev.type == sf::Event::MouseButtonPressed && level3Sprite.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
    level = std::make_shared<Level>("src/configs/map3.ini","src/configs/level3.ini");
  }
  if (ev.type == sf::Event::MouseButtonPressed && level4Sprite.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
    level = std::make_shared<Level>("src/configs/map4.ini","src/configs/level4.ini");
  }
  if (ev.type == sf::Event::MouseButtonPressed && level5Sprite.getGlobalBounds().contains(window->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
    level = std::make_shared<Level>("src/configs/map5.ini","src/configs/level5.ini");
  }
}
}

void Game::renderGui(sf::RenderTarget* target) {
  target->draw(this->guiText);
}

void Game::render() {
  /**
          @return void

          - clear old frame
          - render objects
          - display frame in window

          Renders the game objects.
  */
  this->window->clear();

  // this->window->draw(this->guiText);
  // render Level
  this->level->render(*this->window);

  if (level->getGameStatus() == 0) {
    this->endGameText.setString("You lost!");
    this->window->draw(this->endGameText);
  } else if (level->getGameStatus() == 1) {
    if (level->GetMap() == level0->GetMap()) {
      this->endGameText.setString("Press level number!");
    }
    else {
      this->endGameText.setString("You win!");
    }
    this->window->draw(this->endGameText);
  }

  this->renderGui(this->window);

  if (level->GetMap() == level0->GetMap()) {
    window->draw(level1Sprite);
    window->draw(level2Sprite);
    window->draw(level3Sprite);
    window->draw(level4Sprite);
    window->draw(level5Sprite);
  }

  this->window->display();
}