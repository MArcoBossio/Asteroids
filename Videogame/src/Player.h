//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_PLAYER_H
#define VIDEOGAME_PLAYER_H
#include "SFML/Graphics.hpp"
#include "Entity.h"

class Player : public Entity {
public:
    Player() : Entity(sf::Vector2f (550, 500), 45), array(sf::Triangles, 3), shooterTimer() {
        array[0].position = sf::Vector2f(0, -20);
        array[1].position = sf::Vector2f(-20, 20);
        array[2].position = sf::Vector2f(20, 20);

        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }
    }

    ~Player() = default;

    bool collided = false;

    void render(sf::RenderWindow &window) override;

    void update(float deltaTime, std::vector<Entity*> &entities) override;

    sf::CircleShape getBoundingCircle() const;

private:
    sf::VertexArray array;
    float shooterTimer;
};


#endif //VIDEOGAME_PLAYER_H
