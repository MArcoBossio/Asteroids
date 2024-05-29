//
// Created by marco on 17/05/2024.
//

#ifndef VIDEOGAME_ASTEROIDS_H
#define VIDEOGAME_ASTEROIDS_H


#include "SFML/Graphics.hpp"
#include "Entity.h"
#include <cmath>
#include <random>
#define ASTEROID_W 50.0f
#define ASTEROID_H 40.0f
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

class Asteroids : public Entity {
public:
    Asteroids(sf::Vector2f direction = Asteroids::randomDirection(),
              sf::Vector2f position = Asteroids::randomPosition())
    : Entity(sf::Vector2f (900, 300), 0), direction(direction), array(sf::LineStrip, 12){
        array[0].position = sf::Vector2f(-40, 40);
        array[1].position = sf::Vector2f(-50, 10);
        array[2].position = sf::Vector2f(-10, -20);
        array[3].position = sf::Vector2f(-20, -40);
        array[4].position = sf::Vector2f(10, -40);
        array[5].position = sf::Vector2f(40, -20);
        array[6].position = sf::Vector2f(40, -10);
        array[7].position = sf::Vector2f(10, 0);
        array[8].position = sf::Vector2f(40, 20);
        array[9].position = sf::Vector2f(20, 45);
        array[10].position = sf::Vector2f(0, 30);
        array[11].position = array[0].position;


        for (size_t i = 0; i < array.getVertexCount(); i++) {
            array[i].color = sf::Color::White;
        }
    }

    void render(sf::RenderWindow &window) override;

    void update(float deltaTime, std::vector<Entity*> &entities) override;

    static sf::Vector2f randomDirection() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> dist(0.0f, 2.0f * M_PI);

        float angle = dist(gen);
        return sf::Vector2f(cos(angle), sin(angle));
    }

    static sf::Vector2f randomPosition() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<float> xAxis(ASTEROID_W / 2.0f, SCREEN_WIDTH - ASTEROID_W / 2.0f);
        std::uniform_real_distribution<float> yAxis(ASTEROID_H / 2.0f, SCREEN_HEIGHT - ASTEROID_H / 2.0f);

        return sf::Vector2f(xAxis(gen), yAxis(gen));
    }

private:
    sf::VertexArray array;
    sf::Vector2f direction;
};


#endif //VIDEOGAME_ASTEROIDS_H
