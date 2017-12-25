#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include <string>
using namespace sf;

int main()
{
	bool b;

	RenderWindow window(VideoMode(1000, 600), "New_Window", Style::Fullscreen);

	String s_hero = "C:/3_semester/SFML_go/sprite.png";
	String s_map = "C:/3_semester/SFML_go/sprite_list.png";

	player car(s_hero, 1, 50, 135);
	car.sp.setTextureRect(IntRect(0, 34, 40, 22));

	Map_ map_1(s_map);

	Clock clock;
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		Event event;
		while (window.pollEvent(event))
		{
			if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			car.sp.setTextureRect(IntRect(20, 0, 38, 24));
			car.sp.move(-0.1*time, 0);
			car.x += -0.1*time;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			car.sp.setTextureRect(IntRect(0, 34, 40, 22));
			car.sp.move(0.1*time, 0);
			car.x += 0.1*time;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			car.sp.setTextureRect(IntRect(0, 0, 22, 36));
			car.sp.move(0, 0.1*time);
			car.y += 0.1*time;
		}

		else if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			car.sp.setTextureRect(IntRect(56, 0, 22, 40));
			car.sp.move(0, -0.1 * time);
			car.y += -0.1*time;
		}

		window.clear();
		map_1.Load_map(window);
		window.draw(car.sp);
		window.display();
	}
}
