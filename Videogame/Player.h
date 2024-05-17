//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_PLAYER_H
#define VIDEOGAME_PLAYER_H
#include "SFML/Graphics.hpp"

class Player {
public:
    Player() : position(550, 500), angle(45), array(sf::Quads, 4) {
        array[0].position = sf::Vector2f(0, -25);
        array[1].position = sf::Vector2f(-20, 20);
        array[2].position = sf::Vector2f(0, 10);
        array[3].position = sf::Vector2f(20, 20);

        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }
    }
    sf::Vector2f position;
    float angle;

    void draw(sf::RenderWindow &window);

private:
    sf::VertexArray array;

};


#endif //VIDEOGAME_PLAYER_H
