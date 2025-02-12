#include "snake.hpp"

Snake::Snake() {
  // Test numbers for the size of the Snake
  // Need to be deleted
  snake_ = {{10, 10}, {11, 10}};
}

Snake::~Snake() { snake_.clear(); }

void Snake::move(Direction direction) {
  sf::Vector2f head = snake_.front();

  switch (direction) {
  case Direction::Up:
    head.y -= 1;
    break;
  case Direction::Down:
    head.y += 1;
    break;
  case Direction::Left:
    head.x -= 1;
    break;
  case Direction::Right:
    head.x += 1;
    break;
  }

  // Move all snake cells
  for (size_t i = snake_.size() - 1; i > 0; --i) {
    snake_[i] = snake_[i - 1];
  }

  // Update head cords
  snake_[0] = head;
}

void Snake::drawSnake(sf::RenderWindow &window) {
  for (const auto &pos : snake_) {
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setPosition(pos.x * cellSize, pos.y * cellSize);
    cell.setFillColor(sf::Color::Green);
    window.draw(cell);
  }
}

bool Snake::isAlive() {
  sf::Vector2f head = snake_.front();
  return ((head.x == 0 || head.x == 80) || ((head.y == 0) || (head.y == 60)));
}

sf::Vector2f Snake::getHeadPosition() { return snake_.front(); }

void Snake::grow() { snake_.push_back(snake_.back()); }