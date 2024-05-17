//
// Created by marco on 17/05/2024.
//

#include "Player.h"
#include "SFML/Graphics.hpp"

void Player::draw(sf::RenderWindow &window) {
   sf::Transform transform;
   transform.translate(position).rotate(angle);
    window.draw(array, transform);
}