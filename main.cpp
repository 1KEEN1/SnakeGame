#include "src/fruit.hpp"
#include "src/snake.hpp"
#include <SFML/Graphics.hpp>

int main() {
  // Create a window for the app
  sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

  Snake snake;
  Direction direction = Direction::Right;

  Fruit fruit;

  // Run the program as long as the window is open
  while (window.isOpen()) {
    // check all the window's events that were triggered since the last
    // iteration of the loop
    sf::Event event;
    while (window.pollEvent(event)) {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up)
          direction = Direction::Up;
        else if (event.key.code == sf::Keyboard::Down)
          direction = Direction::Down;
        else if (event.key.code == sf::Keyboard::Left)
          direction = Direction::Left;
        else if (event.key.code == sf::Keyboard::Right)
          direction = Direction::Right;
      }
    }

    snake.move(direction);

    // Checks if Snake didn't crashed into the wall
    if (snake.isAlive()) {
      window.close();
    }

    window.clear();

    sf::Vector2u windowSize = window.getSize();
    fruit.spawnFruit(snake, windowSize);
    fruit.drawFruit(window);
    snake.drawSnake(window);

    window.display();

    // Movement speed of the Snake
    sf::sleep(sf::milliseconds(100));
  }

  return 0;
}