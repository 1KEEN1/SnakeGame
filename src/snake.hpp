#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int cellSize = 10;

enum class Direction { Up, Down, Left, Right };

class Snake {
public:
  Snake();
  ~Snake();

  void move(Direction direction);
  void printSnake(sf::RenderWindow &window);

private:
  // 2D Vector for snake cords
  std::vector<sf::Vector2i> snake_;
};