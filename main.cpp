#include <SFML/Graphics.hpp>
#include "settings.h"
#include "payer.h"
#include "road.h"
#include "enemies.h"
using namespace sf;

int main()
{
    srand(time(0));
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), TITLE);
    window.setFramerateLimit(FPS);
    Player player;
    Road road;
  // Enemy enemy;
    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
        //update 
        player.update();
       // enemy.update();
        // Отрисовка окна
        window.clear();
        road.draw(window);
        player.draw(window);
       // enemy.draw(window);
        window.display();

    }

    return 0;
}