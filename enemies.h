#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include<ctime>
class Enemy {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedY;
	
public:
	Enemy() {
		
	}
	Enemy(sf::Texture texture, int speedY, sf::Vector2f position) {
		sprite.setTexture(texture);
		this->speedY = speedY;
		sprite.setPosition(position);
	}
	sf::FloatRect getHitBox() {
		return sprite.getGlobalBounds();
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
	}
	void update() {
		sprite.move(0, speedY);
		if (sprite.getPosition().y >= SCREEN_HIGHT) {
			
		}
	}
	sf::Vector2f getPosition() {
		return sprite.getPosition();
	}
	
};