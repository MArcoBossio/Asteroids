//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_ASTEROIDS_H
#define VIDEOGAME_ASTEROIDS_H


#include "SFML/Graphics.hpp"
#include "Entity.h"

class Asteroids : public Entity {
public:
    Asteroids(sf::Vector2f direction)
    : Entity(sf::Vector2f (900, 300), 0), direction(direction), array(sf::LineStrip, 12){
        array[0].position = sf::Vector2f(-40, 40);
        array[1].position = sf::Vector2f(-50, 10);
        array[2].position = sf::Vector2f(-10, -20);
        array[3].position = sf::Vector2f(-20, -40);
        array[4].position = sf::Vector2f(10, -40);
        array[5].position = sf::Vector2f(40, -20);
        array[6].position = sf::Vector2f(40, -10);
        array[7].position = sf::Vector2f(10, 0);
        array[8].position = sf::Vector2f(40, 20);
        array[9].position = sf::Vector2f(20, 45);
        array[10].position = sf::Vector2f(0, 30);
        array[11].position = array[0].position;


        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }
    }

    void render(sf::RenderWindow &window) override;

    void update(float deltaTime, std::vector<Entity*> &entities) override;

private:
    sf::VertexArray array;
    sf::Vector2f direction;
};


#endif //VIDEOGAME_ASTEROIDS_H
