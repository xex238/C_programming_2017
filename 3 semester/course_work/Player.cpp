#include "Player.h"
#include <thread>
#include <iostream>

Player::Player()
{ 
	my_music.Play_fon_music();
	Load_level(level_1, "maps/Map_for_game_1.tmx");
	Load_level(level_2, "maps/Map_for_game_2.tmx");
	Load_level(level_3, "maps/Map_for_game_3.tmx");
	Load_level(level_4, "maps/Map_for_game_4.tmx");
	Load_level(level_5, "maps/Map_for_game_5.tmx");
}

void Player::Refresh(const RenderWindow& window)
{
	my_music.Replay();
	car.Restart_time();
	Update_pos(window);
}
void Player::Update_pos(const RenderWindow& window)
{
	pixel_pos = Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixel_pos);
}
void Player::Game_event(RenderWindow& window, Event& event)
{
	if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
		window.close();
	//sf::Thread thread_(Player::Car_go, &window);
	//thread_.launch();
	if (menu.Return_screen_text() == "left.png") // <- Если мы в игре
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::G)
		{
			Car_go(window);

			if (car.Check_collision_with_exit_for_car_go())
			{
				my_music.Stop_fon_music();
				my_music.Play_game_over_music();
				car.Set_enable_text_for_win(true);
				menu.Set_play_game_over_music(true);
			}
		}
		menu.Restart_level(event, car, my_music, pos); // Если нажата кнопка перезапуска уровня
		menu.Return_to_main_menu(event, pos, car, level_1, my_music); // <- Если нажата кнопка назад
		car.Player_MouseButtonPressed(event, pos); // <- Если нажали на стрелочку и хотим её передвинуть
		car.Player_MouseButtonReleased(event, pos); // <- Если мы отпустили кнопку после передвижения стрелочки
	}
	if (menu.Return_screen_text() == "main.png") // <- Если мы в главном меню
	{
		menu.Menu_MouseButtonEvent(window, event, pos);
	}
	if (menu.Return_screen_text() == "settings.png") // <- Если мы в настройках
	{
		menu.Work_with_settings(event, my_music, pos);
	}
	if (menu.Return_screen_text() == "level_load") // <- Если выбираем, какой уровень загружать
	{
		Choose_level_for_load(event);
	}
}
void Player::Draw_graphics(RenderWindow& window)
{
	window.clear(Color::Cyan);
	if (menu.Return_screen_text() == "left.png")  // <- Если мы в игре
	{
		switch (level)
		{
		case 1:
		{
			level_1.Draw(window);
			break;
		}
		case 2:
		{
			level_2.Draw(window);
			break;
		}
		case 3:
		{
			level_3.Draw(window);
			break;
		}
		case 4:
		{
			level_4.Draw(window);
			break;
		}
		case 5:
			level_5.Draw(window);
			break;
		}
		car.Draw_arrows(window); // <- Рисуем четыре стрелочки
		car.Draw_additional_arrows(window);  // <- Рисуем все стрелочки с отдельными спрайтами
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
	if (menu.Return_screen_text() == "level_load")
	{
		window.draw(menu.Return_level_screen_sprite());
		window.draw(menu.Return_left_sprite());  // <- Рисуем спрайт кнопочки "назад"
	}
	car.Move_arrow(pos);
	window.display();
}
void Player::Car_go(RenderWindow& window)
{
	while (!(car.Check_collision_with_exit_for_car_go())) // Пока не дошли до выхода
	{
		// Пока не дошли до таблички и не дошли до выхода, идём вперёд по вектору
		while ((!car.Check_collision_with_arrows_for_car_go()) && (!car.Check_collision_with_exit_for_car_go()))
		{
			for (int i = 0; i < 100; i++)
			{
				car.Go_without_time();
				Draw_graphics(window);
			}
		}
		// Если мы стоим на табличке и не стоим на выходе, то идём, пока не "не кончится" табличка
		if ((car.Check_on_true_vector()) && (!car.Check_collision_with_exit_for_car_go()))
		{
			for (int i = 0; i < 100; i++)
			{
				car.Go_without_time();
				Draw_graphics(window);
			}
		}
		else
		{
			break;
		}
	}
}
void Player::Choose_level_for_load(Event& event)
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x > 100) && (pos.x < 200) && (pos.y > 100) && (pos.y < 200)) // 1 уровень
			{
				menu.Set_screen_text("left.png");
				car.Load_car(level_1);
				level = 1;
			}
			if ((pos.x > 250) && (pos.x < 350) && (pos.y > 100) && (pos.y < 200)) // 2 уровень
			{
				menu.Set_screen_text("left.png");
				car.Load_car(level_2);
				level = 2;
			}
			if ((pos.x > 400) && (pos.x < 500) && (pos.y > 100) && (pos.y < 200)) // 3 уровень
			{
				menu.Set_screen_text("left.png");
				car.Load_car(level_3);
				level = 3;
			}
			if ((pos.x > 550) && (pos.x < 650) && (pos.y > 100) && (pos.y < 200)) // 4 уровень
			{
				menu.Set_screen_text("left.png");
				car.Load_car(level_4);
				level = 4;
			}
			if ((pos.x > 700) && (pos.x < 800) && (pos.y > 100) && (pos.y < 200)) // 5 уровень
			{
				menu.Set_screen_text("left.png");
				car.Load_car(level_5);
				level = 5;
			}
			if ((pos.x < 32) && (pos.y < 32)) // Вернуться в главное меню
			{
				menu.Set_screen_text("main.png");
			}
		}
	}
}
void Player::Load_level(Level& level_, const String& string_level)
{
	level_.LoadFromFile(string_level); // Загружаем карту
	level_.Dislocate(64, 128); // Перемещаем карту
	level_.Dislocate_objects(64, 128); // Перемещаем объекты
}
