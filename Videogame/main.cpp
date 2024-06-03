#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include "Asteroids.h"
#include "Game.h"
#include <cmath>
#include <vector>
#include <list>

#define ASTEROID_SPAWN_TIME 5.0f

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Asteroids!", sf::Style::Close | sf::Style::Titlebar);
    sf::Clock clock;

    Game::begin();

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        Game::update(window, deltaTime);

        window.display();
    }

    return 0;
}
