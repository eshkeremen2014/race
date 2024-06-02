#include <SFML/Graphics.hpp>
#include "settings.h"
#include "payer.h"
#include "road.h"
#include "enemies.h"
#include"EManager.h"
using namespace sf;

int main()
{
    srand(time(0));
    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), TITLE);
    window.setFramerateLimit(FPS);
    Player player;
    Road road;
    EManager emanager;
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
        emanager.update();
        // ��������� ����
        window.clear();
        road.draw(window);
        player.draw(window);
        emanager.draw(window);
        window.display();

    }

    return 0;
}