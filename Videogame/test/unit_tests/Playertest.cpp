//
// Created by marco on 08/06/2024.
//

#include "gtest/gtest.h"
#include "../../Asteroids.h"
#include "../../Player.h"

TEST(PlayerTest, CollisionWithAsteroid) {
Player player;
Asteroids asteroid;

// Set the positions of the player and the asteroid so that they collide
player.position = sf::Vector2f(100.0f, 100.0f);
asteroid.position = sf::Vector2f(100.0f, 100.0f);

// Create a vector of entities containing the asteroid
std::vector<Entity*> entities;
entities.push_back(&asteroid);

// Call the update method of the Player class
// We expect the game to end because of the collision, so we catch the exit call
    player.update(0.0f, entities);
    EXPECT_TRUE(player.collided);
}
