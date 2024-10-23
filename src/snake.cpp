#include "snake.hpp"

Snake::Snake() {
    snake_ = { {10, 10}, {11, 10}, {12, 10} };
}

Snake::~Snake() {
    snake_.clear();
}

// void Snake::moveUp() {
    
// }

// void Snake::moveDown() {
    
// }

// void Snake::moveRight() {
    
// }

// void Snake::moveLeft() {
    
// }

void Snake::printSnake(sf::RenderWindow& window) {
    for (const auto& pos : snake_) {
        sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
        cell.setPosition(pos.x * cellSize, pos.y * cellSize);
        cell.setFillColor(sf::Color::Green);
        window.draw(cell);
    }
}