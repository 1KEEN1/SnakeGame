#pragma once

#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "snake.hpp"

class Fruit {
public:
  Fruit();

  void spawnFruit(Snake &snake, const sf::Vector2u &windowSize);
  void drawFruit(sf::RenderWindow &window);

private:
  sf::RectangleShape fruit_;
  int fruitSize = 10;
  bool fruitSpawned = false;
};