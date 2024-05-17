#ifndef VIDEOGAME_BULLET_H
#define VIDEOGAME_BULLET_H
#include "SFML/Graphics.hpp"
#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(sf::Vector2f position, sf::Vector2f direction) : direction(direction), Entity(position, 0.0f) {
        if (!texture.loadFromFile("assets/pew_pew.png")) {
            // handle error
        }
        sprite.setTexture(texture);
        sprite.setOrigin(texture.getSize().x / 2.0f, texture.getSize().y / 2.0f);
        sprite.scale(2.0f, 2.0f); // scale the sprite to make it bigger

        // adjust the initial position of the bullet
        float offset = 50.0f; // adjust this value as needed
        this->position = position + direction * offset;
    }

    void update(float deltaTime, std::vector<Entity*> &entities) override;
    void render(sf::RenderWindow &window) override;

private:
    sf::Vector2f direction;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::CircleShape shape;
};

#endif //VIDEOGAME_BULLET_H