#include "src/snake.hpp"
#include <SFML/Graphics.hpp>

int main() {
  // Create a window for the app
  sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

  Snake snake;
  Direction direction = Direction::Right;

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

    window.clear();
    snake.printSnake(window);
    window.display();

    // Movement speed of the Snake
    sf::sleep(sf::milliseconds(100));
  }

  return 0;
}