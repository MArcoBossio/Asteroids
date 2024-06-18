//
// Created by marco on 17/06/2024.
//

#include "gtest/gtest.h"
#include "../src/Asteroids.h"
#include "../src/Bullet.h"

TEST(AsteroidsTest, CollisionWithBullet) {
    // Declare and initialize the variables before using them
    sf::Vector2f bulletPosition(100.0f, 100.0f);
    sf::Vector2f bulletDirection(1.0f, 0.0f); // Assuming bullet is moving in positive x direction

    // Make sure the Asteroids and Bullet classes are defined in the included header files
    Asteroids asteroid;
    Bullet bullet(bulletPosition, bulletDirection); // Corrected here

    // Set the positions of the asteroid and the bullet so that they collide
    asteroid.position = sf::Vector2f(100.0f, 100.0f);
    bullet.position = sf::Vector2f(100.0f, 100.0f); // Corrected here

    // Create a vector of entities containing the asteroid
    // Make sure the Entity class is defined and included in your test file
    std::vector<Entity*> entities;
    entities.push_back(&asteroid);

    // Call the update method of the Bullet class
    // We expect the bullet to be destroyed because of the collision
    bullet.update(0.0f, entities);
    EXPECT_EQ(entities.size(), 0);
}