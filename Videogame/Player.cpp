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

using namespace std;

void Player::render(sf::RenderWindow &window) {
    sf::Transform transform;
   transform.translate(position).rotate(angle);
    window.draw(array, transform);

}

void Player::update(float deltaTime) {
    float radiant = angle * (M_PI / 180.0f);

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        std::vector<Entity*> entities{};
        entities.push_back(new Bullet(position, sf::Vector2f(cos(radiant), sin(radiant))));
    }
}