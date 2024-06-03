//
// Created by marco on 03/06/2024.
//

#ifndef VIDEOGAME_GAME_H
#define VIDEOGAME_GAME_H

#include <vector>
#include <list>
#include "Entity.h"

class Game {
public:
    static void begin();
    static void update(sf::RenderWindow &window, float deltaTime);

    static std::vector<Entity*> entities;
    static std::list<std::vector<Entity*>::const_iterator> toRemoveList;
    static std::list<Entity*> toAddList;

private:
    static float asteroidSpawnTime;
};


#endif //VIDEOGAME_GAME_H
