//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_BULLET_H
#define VIDEOGAME_BULLET_H
#include "SFML/Graphics.hpp"
#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction) : shape(1.0f), direction(direction),
                                                            Entity(position, 0.0f){}

    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;

private:
    sf::Vector2f direction;
    sf::CircleShape shape;
};


#endif //VIDEOGAME_BULLET_H
