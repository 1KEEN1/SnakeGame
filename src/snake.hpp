#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

enum class Direction { Up, Down, Left, Right };

class Snake {
public:
  Snake();
  ~Snake();

  void move(Direction direction);
  void drawSnake(sf::RenderWindow &window);
  bool isAlive();

  sf::Vector2f getHeadPosition();

private:
  // 2D Vector for snake cords
  std::vector<sf::Vector2i> snake_;
  int cellSize = 10;
};