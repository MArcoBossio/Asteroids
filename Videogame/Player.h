//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_PLAYER_H
#define VIDEOGAME_PLAYER_H
#include "SFML/Graphics.hpp"
#include "Entity.h"

class Player : public Entity {
public:
    Player() : Entity(sf::Vector2f (550, 500), 0), array(sf::Quads, 4) {
        array[0].position = sf::Vector2f(-30, 0);
        array[1].position = sf::Vector2f(20, -20);
        array[2].position = sf::Vector2f(10, 0);
        array[3].position = sf::Vector2f(20, 20);

        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }
    }

    void render(sf::RenderWindow &window) override;

    void update(float deltaTime) override;

private:
    sf::VertexArray array;

};


#endif //VIDEOGAME_PLAYER_H
