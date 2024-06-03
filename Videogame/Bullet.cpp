//
// Created by marco on 17/05/2024.
//
#include "Entity.h"
#include "Bullet.h"
#include "Game.h"
#include "Asteroids.h"
#include "SFML/Graphics.hpp"
#include <limits>

#define BULLET_SPEED 400.0f

void Bullet::update(float deltaTime, std::vector<Entity*> &entities) {
    position += direction * BULLET_SPEED * deltaTime;

    sf::CircleShape bulletCircle = getBoundingCircle();
    for (auto it = entities.begin(); it != entities.end(); ) {
        if (Asteroids* asteroid = dynamic_cast<Asteroids*>(*it)) {
            sf::CircleShape asteroidCircle = asteroid->getBoundingCircle();
            if (bulletCircle.getGlobalBounds().intersects(asteroidCircle.getGlobalBounds())) {
                // Collision detected, remove the bullet
                delete *it;
                it = entities.erase(it);
                return; // Bullet is destroyed, no need to check other asteroids
            } else {
                ++it;
            }
        } else {
            ++it;
        }
    }
}

void Bullet::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    window.draw(sprite);

}

sf::CircleShape Bullet::getBoundingCircle() const {
    sf::CircleShape circle(5.0f);
    circle.setPosition(position);
    return circle;
}