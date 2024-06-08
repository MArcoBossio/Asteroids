//
// Created by marco on 08/06/2024.
//

#include "googletest/include/gtest/gtest.h"
#include "Player.h"
#include "Asteroids.h"

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
EXPECT_EXIT(player.update(0.0f, entities), ::testing::ExitedWithCode(0), "");
}