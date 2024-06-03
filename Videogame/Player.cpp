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
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900
#define PLAYER_W 50
#define PLAYER_H 50
#define BULLET_ANGLE 30.0f

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

        position.x = std::min(std::max(position.x, PLAYER_W / 2.0f), SCREEN_WIDTH - PLAYER_W / 2.0f);
        position.y = std::min(std::max(position.y, PLAYER_H / 2.0f), SCREEN_HEIGHT - PLAYER_H / 2.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and shooterTimer <= 0) {
        float bulletAngle = radiant + BULLET_ANGLE; // BULLET_ANGLE is the angle by which you want to rotate the bullet's position and direction

        sf::Vector2f bulletDirection = sf::Vector2f(cos(bulletAngle), sin(bulletAngle)); // direction pointing in the direction of the top part of the triangle

        sf::Vector2f topPart = sf::Vector2f(array[0].position.x, array[0].position.y);
        sf::Vector2f rotatedTopPart = sf::Vector2f(
                topPart.x * cos(bulletAngle) - topPart.y * sin(bulletAngle),
                topPart.x * sin(bulletAngle) + topPart.y * cos(bulletAngle)
        );
        sf::Vector2f bulletPosition = position + rotatedTopPart;

        entities.push_back(new Bullet(bulletPosition, bulletDirection));
        shooterTimer = SHOOT_DELAY;
    }
}