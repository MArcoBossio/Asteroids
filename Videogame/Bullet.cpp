//
// Created by marco on 17/05/2024.
//
#include "Entity.h"
#include "Bullet.h"
#include "Game.h"
#include "SFML/Graphics.hpp"
#include <limits>

#define BULLET_SPEED 400.0f

void Bullet::update(float deltaTime, std::vector<Entity*> &entities) {
    position += direction * BULLET_SPEED * deltaTime;
    //Game::toRemoveList.push_back(Game::entities.begin(), Game::entities.end(), this);
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