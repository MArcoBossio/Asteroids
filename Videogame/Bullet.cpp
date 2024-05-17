//
// Created by marco on 17/05/2024.
//
#include "Entity.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"

#define BULLET_SPEED 350.0f

void Bullet::update(float deltaTime) {
    position += direction * BULLET_SPEED * deltaTime;
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(shape, sf::Transform().translate(position));
}