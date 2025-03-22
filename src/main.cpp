#include <optional>

#include <fmt/core.h>
#include <SFML/Window.hpp>

int main() {
  sf::Window window(sf::VideoMode({1200, 1200}), "Fisica");

  while (window.isOpen()) {
    while (const std::optional event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
	window.close();
      }
    }
  }
}
