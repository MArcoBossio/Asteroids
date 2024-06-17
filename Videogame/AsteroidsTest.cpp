//
// Created by marco on 17/06/2024.
//

#include "googletest/include/gtest/gtest.h"
#include "Asteroids.h"
#include "Bullet.h"

TEST(AsteroidsTest, CollisionWithBullet) {
    Asteroids asteroid;
    sf::Vector2f bulletPosition(100.0f, 100.0f);
    sf::Vector2f bulletDirection(1.0f, 0.0f); // Assuming bullet is moving in positive x direction
    Bullet bullet(bulletPosition, bulletDirection); // Corrected here

    // Set the positions of the asteroid and the bullet so that they collide
    asteroid.position = sf::Vector2f(100.0f, 100.0f);
    bullet.position = sf::Vector2f(100.0f, 100.0f); // Corrected here

    // Create a vector of entities containing the asteroid
    std::vector<Entity*> entities;
    entities.push_back(&asteroid);

    // Call the update method of the Bullet class
    // We expect the bullet to be destroyed because of the collision
    bullet.update(0.0f, entities);
    EXPECT_EQ(entities.size(), 0);
}