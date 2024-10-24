#include "fruit.hpp"

Fruit::Fruit() {
  // Generator of random numbers
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  // Initialize the fruit shape
  fruit_.setSize(sf::Vector2f(fruitSize, fruitSize));
  fruit_.setFillColor(sf::Color::Red);
  fruit_.setPosition(0, 0);
}

void Fruit::spawnFruit(Snake &snake, const sf::Vector2u &windowSize) {
  // Get snake position
  sf::Vector2f snakeHeadPosition = snake.getHeadPosition();
  // Get fruit position
  sf::Vector2f fruitPosition = fruit_.getPosition();

  std::cout << "Snake cords: x = " << snakeHeadPosition.x
            << " y = " << snakeHeadPosition.y << std::endl;
  std::cout << "Frut cords: x = " << fruitPosition.x
            << " y = " << fruitPosition.y << std::endl;

  if (!fruitSpawned) {
    int randomX = std::rand() % (windowSize.x / fruitSize);
    int randomY = std::rand() % (windowSize.y / fruitSize);

    fruit_.setPosition(randomX * fruitSize, randomY * fruitSize);
    fruitSpawned = true;
  } else {
    if ((snakeHeadPosition.x == fruitPosition.x) &&
        (snakeHeadPosition.y == fruitPosition.y)) {
      int randomX = std::rand() % (windowSize.x / fruitSize);
      int randomY = std::rand() % (windowSize.y / fruitSize);

      fruit_.setPosition(randomX * fruitSize, randomY * fruitSize);
    }
  }
}

void Fruit::drawFruit(sf::RenderWindow &window) { window.draw(fruit_); }