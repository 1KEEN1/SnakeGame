g++ -c main.cpp
g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system src/snake.cpp src/fruit.cpp
./sfml-app