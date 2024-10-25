#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <iostream>
#include <stdlib.h>

#include "snake.hpp"

class Fruit {
public:
  Fruit();

  void generateFruit(Snake snake);
  void drawFruit(sf::RenderWindow &window);

  bool isFruitSpawned() const;
  void resetFruit();

  sf::Vector2f getFruitPositionInCells() const;

private:
  sf::RectangleShape fruit_;
  int fruitSize = 10;
  bool fruitSpawned = false;
};