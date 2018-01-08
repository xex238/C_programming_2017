#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Player.h"
#include "Map.h"
#include "Menu.h"
#include "Music.h"
#include <string>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(1366, 768), "New_Window", Style::Fullscreen, ContextSettings());

	Menu menu("pictures/main_menu.png", "pictures/arrow_back.png", "pictures/settings.png", "pictures/rectangle.png", "pictures/restart_level.png");

	Map map_1("pictures/sprite_list_textures.png", "pictures/sprite_list_arrows.png");

	Player car("pictures/sprite_list_cars.png", "pictures/sprite_list_arrows.png", map_1);

	Musics my_music("music/game_over.ogg", "music/fon_music.ogg");
	my_music.Play_fon_music();

	Thread move_control_thread(&Player::Move_control, &car);

	while (window.isOpen())
	{
		my_music.Replay();

		car.Restart_time();

		car.Update_pos(window);
		menu.Update_pos(window);

		Event event;

		while (window.pollEvent(event)) // <- Обработчик событий
		{
			if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
				window.close();
			if (menu.Return_screen_text() == "left.png") // <- Если мы в игре
			{
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::G)
				{
					car.Car_go(map_1, window, my_music);
				}
				//if (event.type == Event::KeyPressed && event.key.code == Keyboard::J)
				//{
				//	car.Go_to_vector_1(window);
				//}
				menu.Restart_level(event, car, map_1, my_music);
				menu.Return_to_main_menu(event); // <- Если нажата кнопка назад
				car.Player_MouseButtonPressed(event); // <- Если нажали на стрелочку и хотим её передвинуть
				car.Player_MouseButtonReleased(event, map_1); // <- Если мы отпустили кнопку после передвижения стрелочки
			}
			if (menu.Return_screen_text() == "main.png") // <- Если мы в главном меню
			{
				menu.Menu_MouseButtonEvent(window, event);
			}
			if (menu.Return_screen_text() == "settings.png") // <- если мы в настройках
			{
				menu.Work_with_settings(event, my_music);
			}
		}

		if (menu.Return_screen_text() == "left.png") // <- Если мы в игре, обрабатываем движение машинки и стрелочки
		{
			move_control_thread.launch(); // <- Обрабатываем движения машинки и стрелочки в новом потоке
		}

		window.clear(Color::Cyan);

		// <- Отрисовка графики
		if (menu.Return_screen_text() == "left.png")  // <- Если мы в игре
		{
			map_1.Load_map(window);  // <- Рисуем карту
			map_1.Draw_arrows(window); // <- Рисуем четыре стрелочки
			car.Draw_arrows(window);  // <- Рисуем все стрелочки с отдельными спрайтами
			window.draw(car.Return_sprite_cars());  // <- Рисуем спрайт машинки
			window.draw(menu.Return_left_sprite());  // <- Рисуем спрайт кнопочки "назад"
			window.draw(menu.Return_restart_level_sprite()); // <- Рисуем кнопку перезапуска уровня
			if (car.Return_enable_text_for_win())
			{
				window.draw(car.Return_text_for_win());
			}
		}
		if (menu.Return_screen_text() == "main.png")  // <- Если мы в главном меню
		{
			window.draw(menu.Return_main_sprite());
			if (menu.Return_enable_rectangle_sprite())
			{
				window.draw(menu.Return_rectangle_sprite());
			}
		}
		if (menu.Return_screen_text() == "settings.png")  // <- Если мы в настройках
		{
			window.draw(menu.Return_settings_sprite());
			window.draw(menu.Return_left_sprite());
			window.draw(menu.Return_text());
			window.draw(menu.Return_sounds_enable_list_sprite());
		}

		window.display();
	}
}
