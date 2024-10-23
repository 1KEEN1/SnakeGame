#include "snake.hpp"

Snake::Snake() {
    // Test numbers for the size of the Snake
    // Need to be deleted
    snake_ = { {10, 10}, {11, 10}, {12, 10} };
}

Snake::~Snake() {
    snake_.clear();
}

void Snake::move(Direction direction) {
    sf::Vector2i head = snake_.front();

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

void Snake::printSnake(sf::RenderWindow& window) {
    for (const auto& pos : snake_) {
        sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
        cell.setPosition(pos.x * cellSize, pos.y * cellSize);
        cell.setFillColor(sf::Color::Green);
        window.draw(cell);
    }
}