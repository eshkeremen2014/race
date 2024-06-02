#pragma once
#include"enemies.h"
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <list>
class EManager {
private:
	std::list<Enemy*> enemyCars;
	sf::Clock clock;
	int timer;
public:
	EManager() {
		timer = clock.getElapsedTime().asMilliseconds();
	}
	void createEnemy() {
		sf::Texture texture;
		int choise = rand() % 2;
		if (choise == 1) {
			texture.loadFromFile("enemy1.png");
		}
		else {
			texture.loadFromFile("enemy 2.png");
		}
		sf::Vector2f position{ static_cast<float>(rand() % (SCREEN_WIDTH - static_cast<int>(ENEMY_WIDTH))),-ENEMY_HEIGHT};
		int speedY = rand() % 4 + 2;
		Enemy* enemy = new Enemy(texture, speedY, position);
		enemyCars.push_back(enemy);
	}
	void update() {
		int now = clock.getElapsedTime().asMilliseconds();
		if(now-timer>=1500){
			timer = now;
			createEnemy();
		}
		for (auto& enemy : enemyCars) {
			enemy->update();
		}
		enemyCars.remove_if([](Enemy* enemy) {return enemy->getPosition().y > SCREEN_HIGHT; });
		
	}
	void draw(sf::RenderWindow& window) {
		for (auto& enemy : enemyCars) { enemy->draw(window); };
	}
};

