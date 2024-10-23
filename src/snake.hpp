#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

const int cellSize = 10;

class Snake {
    public:
        Snake();
        ~Snake();

        // void moveUp();
        // void moveDown();
        // void moveRight();
        // void moveLeft();

        void printSnake(sf::RenderWindow& window);

    private:
        // 2D Vector for snake cords
        std::vector<sf::Vector2i> snake_;
};