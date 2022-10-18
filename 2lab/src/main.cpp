#include <iostream>

#include <SFML/Graphics.hpp>
#include <iomanip>

#include "GlobalSystem.h"
#include "RightPyramid.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main() {
  GlobalSystem system(Vec3(1, 1, 0));
  auto res = system.calculateLookAtMatrix();
  auto array = res.array;
  std::cout << std::fixed;
  std::cout.precision(3);
//  for (int i = 0; i < 16; ++i) {
//	std::cout << std::setprecision(5) << std::setfill(' ') << array[i] << " ";
//	if ((i + 1) % 4 == 0) {
//	  std::cout << std::endl;
//	}
//  }
  std::shared_ptr<Figure> pnt = std::make_shared<RightPyramid>(4, 4, 4);
  auto vec = (*pnt).vertexes();
  for (const auto &vert: vec){
	std::cout << std::fixed;
	std::cout.precision(5);
	std::cout << vert.x << " " << vert.y << " " << vert.z << " " << vert.w << std::endl;
  }
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
  sf::Color bgColor = sf::Color::White;

  while (window.isOpen()) {
	sf::Event event;
	while (window.pollEvent(event)) {
	  if (event.type == sf::Event::Closed) {
		window.close();
	  }
	}
	window.clear(bgColor);
	sf::ConvexShape triangle;
	triangle.setFillColor(sf::Color::Black);
	triangle.setPosition(200, 300);
	triangle.setPointCount(3);
	triangle.setPoint(0, {50, -20});
	triangle.setPoint(1, {50, 20});
	triangle.setPoint(2, {-100, 0});
	window.draw(triangle);
	window.display();
  }
  return 0;
}
