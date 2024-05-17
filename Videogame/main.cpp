#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include <cmath>

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Asteroids!", sf::Style::Close | sf::Style::Titlebar);
    sf::Clock clock;
    Player player;

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        player.draw(window);
        window.display();
    }

    return 0;
}
