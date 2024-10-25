#include "fruit.hpp"

Fruit::Fruit() {
  // Initialize the fruit shape
  fruit_.setSize(sf::Vector2f(fruitSize, fruitSize));
  fruit_.setFillColor(sf::Color::Red);
  fruit_.setPosition(0, 0);
}

void Fruit::generateFruit(Snake snake) {
  if (fruitSpawned)
    return;

  int randomX = 0;
  int randomY = 0;
  srand(time(0));

  randomX = 1 + rand() % (800 - 1);
  randomY = 1 + rand() % (600 - 1);

  fruit_.setPosition(randomX, randomY);

  fruitSpawned = true;
}

void Fruit::drawFruit(sf::RenderWindow &window) { window.draw(fruit_); }

sf::Vector2f Fruit::getFruitPositionInCells() const {
  sf::Vector2f fruitPosition = fruit_.getPosition();
  return sf::Vector2f(std::floor(fruitPosition.x / fruitSize),
                      std::floor(fruitPosition.y / fruitSize));
}

bool Fruit::isFruitSpawned() const { return fruitSpawned; }

void Fruit::resetFruit() { fruitSpawned = false; }