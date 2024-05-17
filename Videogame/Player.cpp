//
// Created by marco on 17/05/2024.
//
#include "Entity.h"
#include "Player.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#define TURN_SPEED 180.0f
#define SPEED 150.0f
#define SHOOT_DELAY 0.2f

using namespace std;

void Player::render(sf::RenderWindow &window) {
    window.draw(array, sf::Transform().translate(position).rotate(angle));
}

void Player::update(float deltaTime, std::vector<Entity*> &entities) {
    float radiant = angle * (M_PI / 180.0f);

    shooterTimer -= deltaTime;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        angle -= TURN_SPEED * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        angle += TURN_SPEED * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        position.x += cos(radiant) * SPEED * deltaTime;
        position.y -= sin(radiant) * SPEED * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and shooterTimer <= 0) {
        sf::Vector2f bulletDirection = sf::Vector2f(cos(radiant), -sin(radiant)); // direction pointing in the direction of the top part of the triangle
        sf::Vector2f bulletPosition = position + sf::Vector2f(array[0].position.x, array[0].position.y);
        entities.push_back(new Bullet(bulletPosition, bulletDirection));
        shooterTimer = SHOOT_DELAY;
    }
}