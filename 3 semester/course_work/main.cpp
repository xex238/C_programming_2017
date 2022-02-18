#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Car.h"
#include "Menu.h"
#include "Music.h"
#include "Player.h"
using namespace sf;

#include "Level.h"
#include <vector>

int main()
{
	RenderWindow window(VideoMode(1366, 768), "Fast racing", Style::Fullscreen, ContextSettings());

	Player player;

	Event event;

	while (window.isOpen())
	{
		player.Refresh(window); // Обновление позиции мыши на экране

		while (window.pollEvent(event)) // <- Обработчик событий
		{
			player.Game_event(window, event);
		}

		player.Draw_graphics(window); // <- Отрисовка графики
	}
}
