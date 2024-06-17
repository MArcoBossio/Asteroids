//
// Created by marco on 17/06/2024.
//

#include "AsteroidsTest.h"
#include "googletest/include/gtest/gtest.h"

TEST(AsteroidsTest, CollisionWithBullet) {
    Asteroids asteroid;
    Bullet bullet;

    // Set the positions of the asteroid and the bullet so that they collide
    asteroid.position = sf::Vector2f(100.0f, 100.0f);
    bullet.position = sf::Vector2f(100.0f, 100.0f);

    // Create a vector of entities containing the asteroid
    std::vector<Entity*> entities;
    entities.push_back(&asteroid);

    // Call the update method of the Bullet class
    // We expect the bullet to be destroyed because of the collision
    bullet.update(0.0f, entities);
    EXPECT_EQ(entities.size(), 0);
}
