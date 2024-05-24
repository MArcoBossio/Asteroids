//
// Created by marco on 17/05/2024.
//

#include "Asteroids.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <cmath>

#define ASTEROID_SPIN 25.0f
#define ASTEROID_SPEED 280.0f
#define ASTEROID_W 50.0f
#define ASTEROID_H 40.0f
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

using namespace std;

void Asteroids::render(sf::RenderWindow &window) {
    window.draw(array, sf::Transform().translate(position).rotate(angle));
}

void Asteroids::update(float deltaTime, std::vector<Entity*> &entities) {
    position += ASTEROID_SPEED * direction * deltaTime;
    angle += ASTEROID_SPIN * deltaTime;

    if (position.x < ASTEROID_W / 2.0f) {
        direction.x = abs(direction.x);
    }
    else if (position.x > SCREEN_WIDTH - ASTEROID_W / 2.0f) {
        direction.x = -abs(direction.x);
    }

    if (position.y < ASTEROID_H / 2.0f) {
        direction.y = abs(direction.y);
    }
    else if (position.y > SCREEN_HEIGHT - ASTEROID_H / 2.0f) {
        direction.y = -abs(direction.y);
    }
}