#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

class Body {
  float mass;
  sf::Vector2f velocity;
  sf::CircleShape shape;
};

#endif
