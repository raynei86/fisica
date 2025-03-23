#include <vector>
#include <optional>
#include <ranges>

#include "body.hpp"

#include <fmt/core.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
  sf::RenderWindow window(sf::VideoMode({1200, 1200}), "Fisica");
  window.setFramerateLimit(60);

  std::vector<fisica::Body> bodies;
  
  bool pause = true;

  while (window.isOpen()) {
    
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
	window.close();
      }
      if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
	bodies.push_back(fisica::Body(5.f, 20.f, {5.f, 5.f}, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window))));
      }

      if (const auto* mouseWheel = event->getIf<sf::Event::MouseWheelScrolled>()) {
	if (mouseWheel->wheel == sf::Mouse::Wheel::Vertical)
	  for (auto& body : bodies) {
	    if (mouseWheel->delta > 0) {
	      body.velocity.x *= 1.05;
	      body.velocity.y *= 1.05;	      
	    }
	    if (mouseWheel->delta < 0) {
	      body.velocity.x *= 0.95;
	      body.velocity.y *= 0.95;	      
	    }
	  }
      }
    
      if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
	if (keyPressed->code == sf::Keyboard::Key::Space) {
	  pause = !pause;	  
	}
      }
    }
    
    if (!pause) {
      const auto [height, width] = window.getSize();

      for (auto& body : bodies) {
      const sf::Vector2f oldPosition = body.shape.getPosition();
      
      const sf::Vector2f newPosition = {oldPosition.x + body.velocity.x, oldPosition.y + body.velocity.y};
      if (newPosition.x <= 0 || (newPosition.x >= (width - 2 * body.radius))) { body.velocity.x *= -1; }
      if (newPosition.y <= 0 || (newPosition.y >= (height - 2 * body.radius))) { body.velocity.y *= -1; }

      const auto isColliding = [&body](fisica::Body& collidingBody) -> bool {
	return body.distance(collidingBody) <= (body.radius + collidingBody.radius);
      };
	
      if (auto collidingBody = std::ranges::find_if(bodies, isColliding); collidingBody != bodies.end()) {
	body.velocity.x *= -1, collidingBody->velocity.x *= -1;
	body.velocity.y *= -1, collidingBody->velocity.y *= -1;
      }
	
      body.shape.setPosition(newPosition);
      }
    }

    window.clear();
    for (const auto& body : bodies) {
      window.draw(body.shape);      
    }
    window.display();
  }
}
