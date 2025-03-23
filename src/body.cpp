#include <cmath>

#include "body.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/CircleShape.hpp>

namespace fisica {
  Body::Body(float mass, float radius, sf::Vector2f velocity, sf::Vector2f position) : mass{mass}, radius{radius}, velocity{velocity} {
    shape = sf::CircleShape(radius);
    shape.setPosition(position);
  }

  [[nodiscard]] float Body::distance(const Body& other) const {
    const auto [x1, y1] = shape.getPosition();
    const auto [x2, y2] = other.shape.getPosition();
    
    return std::sqrt(((x2 * x2) - (x1 * x1)) + ((y2 * y2) - (y1 * y1)));
  }
}
