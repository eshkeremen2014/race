#pragma once
#include"enemies.h"
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <list>
class EManager {
private:
	std::list<Enemy*> enemyCars;
public:
	EManager() {
	
	}
	void createEnemy() {
		sf::Texture texture;
		int choise = rand() % 2;
		if (choise == 1) {
			texture.loadFromFile("enemy1.png");
		}
		else {
			texture.loadFromFile("enemy2.png");
		}
		sf::Vector2f position{ rand() % (int)(SCREEN_WIDTH - ENEMY_WIDTH), -ENEMY_HEIGHT };
		int speedY = rand() % 4 + 2;
		Enemy* enemy = new Enemy(texture, speedY, position);
		enemyCars.push_back(enemy);
	}
	void update() {
		for (auto& enemy : enemyCars) {
			enemy->update();
		}
		enemyCars.remove_if([](Enemy* enemy) {return enemy->getPosition().y > SCREEN_HIGHT; });
	}
};

