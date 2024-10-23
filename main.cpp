#include <SFML/Graphics.hpp>
#include "src/snake.hpp"

int main()
{
    Snake snake;

    // Create a window for the app
    sf::RenderWindow window(sf::VideoMode(800, 600), "Snake Game");

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        snake.printSnake(window);

        window.display();
    }

    return 0;
}