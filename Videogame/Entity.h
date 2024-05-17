//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_ENTITY_H
#define VIDEOGAME_ENTITY_H
#include "SFML/Graphics.hpp"

class Entity {
public:
    Entity(sf::Vector2f position, float angle) : position(position), angle(angle) {}
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;

    sf::Vector2f position;
    float angle;
};


#endif //VIDEOGAME_ENTITY_H
