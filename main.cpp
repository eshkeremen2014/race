#include <SFML/Graphics.hpp>
#include "settings.h"
#include "payer.h"
#include "road.h"
#include "enemies.h"
using namespace sf;

int main()
{
    srand(time(0));
    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), TITLE);
    window.setFramerateLimit(FPS);
    Player player;
    Road road;
  // Enemy enemy;
    // ������� ���� ����������. �����������, ���� ������� ����
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
        }
        //update 
        player.update();
       // enemy.update();
        // ��������� ����
        window.clear();
        road.draw(window);
        player.draw(window);
       // enemy.draw(window);
        window.display();

    }

    return 0;
}