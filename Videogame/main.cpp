#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Entity.h"
#include "Bullet.h"
#include <cmath>
#include <vector>



int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 900), "Asteroids!", sf::Style::Close | sf::Style::Titlebar);
    sf::Clock clock;

    Player player;
    std::vector<Entity*> entities{};
    entities.push_back(new Player());

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        for (size_t i = 0; i < entities.size(); i++) {
            entities[i]->update(deltaTime);
            entities[i]->render(window);
        }
        window.display();
    }

    return 0;
}
