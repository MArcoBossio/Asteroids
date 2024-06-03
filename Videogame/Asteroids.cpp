//
// Created by marco on 17/05/2024.
//

#include "Asteroids.h"
#include "Entity.h"
#include "SFML/Graphics.hpp"
#include <cmath>
#include <random>

#define ASTEROID_SPIN 25.0f
#define ASTEROID_SPEED 150.0f
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

sf::Vector2f Asteroids::randomDirection() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dist(0.0f, 2.0f * M_PI);

    float angle = dist(gen);
    return sf::Vector2f(cos(angle), sin(angle));
}

sf::Vector2f Asteroids::randomPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> xAxis(ASTEROID_W / 2.0f, SCREEN_WIDTH - ASTEROID_W / 2.0f);
    std::uniform_real_distribution<float> yAxis(ASTEROID_H / 2.0f, SCREEN_HEIGHT - ASTEROID_H / 2.0f);

    return sf::Vector2f(xAxis(gen), yAxis(gen));
}

const sf::VertexArray &Asteroids::getVertexArray() const {
    return array;
}

sf::CircleShape Asteroids::getBoundingCircle() const {
    sf::CircleShape circle(40.0f);
    circle.setPosition(position);
    return circle;
}