//
// Created by marco on 17/05/2024.
//
#include "Entity.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"

#define BULLET_SPEED 400.0f

void Bullet::update(float deltaTime, std::vector<Entity*> &entities) {
    position += direction * BULLET_SPEED * deltaTime;
}

void Bullet::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    window.draw(sprite);

}