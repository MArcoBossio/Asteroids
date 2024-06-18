//
// Created by marco on 03/06/2024.
//

#include "Game.h"
#include "Player.h"
#include "Asteroids.h"

#define ASTEROID_SPAWN_TIME 5.0f

std::vector<Entity*> Game::entities{};
std::list<std::vector<Entity*>::const_iterator> Game::toRemoveList{};
std::list<Entity*> Game::toAddList{};
float Game::asteroidSpawnTime{};

void Game::begin() {
    entities.push_back(new Player());
    asteroidSpawnTime = ASTEROID_SPAWN_TIME;
}

void Game::update(sf::RenderWindow & window, float deltaTime) {
    toAddList.clear();
    toRemoveList.clear();
    window.clear();

    asteroidSpawnTime -= deltaTime;

    for (size_t i = 0; i < entities.size(); i++) {
        entities[i]->update(deltaTime, entities);
        entities[i]->render(window);
    }

    for (const auto &it : toRemoveList) {
        delete* it;
        entities.erase(it);
    }

    for (auto &ptr : toAddList) {
        entities.push_back(ptr);
    }

    if (asteroidSpawnTime <= 0.0f) {
        entities.push_back(new Asteroids());
        asteroidSpawnTime = ASTEROID_SPAWN_TIME;
    }
}