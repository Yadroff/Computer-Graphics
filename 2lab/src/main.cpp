#include <iostream>

#include <SFML/Graphics.hpp>
#include <iomanip>

#include "Scene.h"
#include "RightPyramid.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

int main() {
//  for (int i = 0; i < 16; ++i) {
//	std::cout << std::setprecision(5) << std::setfill(' ') << array[i] << " ";
//	if ((i + 1) % 4 == 0) {
//	  std::cout << std::endl;
//	}
//  }
    std::shared_ptr<Figure> pnt = std::make_shared<RightPyramid>(4, 4, 4);
/*    auto vec = (*pnt).polygons();
    for (const auto &vert: vec) {
        std::cout << std::fixed;
        std::cout.precision(5);
        std::cout << vert.x << " " << vert.y << " " << vert.z << " " << vert.w << std::endl;
    }*/
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML");
    sf::Color bgColor = sf::Color::White;
    window.clear(bgColor);
    window.display();
    Scene scene(Math::Vec3{0, 0, 0}, M_PI_2, 0.1, 100, &window);
    scene.addObject(Math::Vec3{0, 0, 0}, pnt);
    scene.draw();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
/*        window.clear(bgColor);
        window.display();*/
    }
    return 0;
}
