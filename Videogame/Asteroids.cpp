//
// Created by marco on 17/05/2024.
//

#include "Asteroids.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <cmath>

#define ASTEROID_SPIN 25.0f
#define ASTEROID_SPEED 80.0f

using namespace std;

void Asteroids::render(sf::RenderWindow &window) {
    window.draw(array, sf::Transform().translate(position).rotate(angle));
}

void Asteroids::update(float deltaTime, std::vector<Entity*> &entities) {
    position += ASTEROID_SPEED * direction * deltaTime;
    angle += ASTEROID_SPIN * deltaTime;
}