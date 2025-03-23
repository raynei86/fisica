#ifndef BODY_HPP
#define BODY_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace fisica {
  struct Body {
    float mass;
    float radius;
    sf::Vector2f velocity;
    sf::CircleShape shape;
    
    explicit Body(float mass, float radius, sf::Vector2f velocity, sf::Vector2f position);
    [[nodiscard]] float distance(const Body& other) const;
        
  };
}
#endif
