//
// Created by marco on 17/05/2024.
//

#include "Player.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#define TURN_SPEED 180.0f
#define SPEED 150.0f

using namespace std;

void Player::draw(sf::RenderWindow &window) {
   sf::Transform transform;
   transform.translate(position).rotate(angle);
    window.draw(array, transform);
}

void Player::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        angle -= TURN_SPEED * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        angle += TURN_SPEED * deltaTime;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        float radiant = angle * (M_PI / 180.0f);
        position.x += cos(radiant) * SPEED * deltaTime;
        position.y -= sin(radiant) * SPEED * deltaTime;
    }
}