#pragma once
#include <SFML/Graphics.hpp>
class Road {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Road() {
		texture.loadFromFile("road (1) (1).png");
		sprite.setTexture(texture);
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
};