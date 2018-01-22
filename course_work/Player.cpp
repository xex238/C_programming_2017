#include "Player.h"

Player::Player(const int x)
{
	my_music.Play_fon_music();
}

void Player::Refresh(RenderWindow& window)
{
	my_music.Replay();
	car.Restart_time();
	Update_pos(window);
}

void Player::Update_pos(RenderWindow & window)
{
	pixel_pos = Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixel_pos);
}

void Player::Game_event(RenderWindow& window, Event& event)
{
	if ((event.type == Event::Closed) || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
		window.close();
	if (menu.Return_screen_text() == "left.png") // <- Если мы в игре
	{
		if (event.type == Event::KeyPressed && event.key.code == Keyboard::G)
		{
			car.Car_go(map_1, window, my_music);
		}
		menu.Restart_level(event, car, map_1, my_music, pos);
		menu.Return_to_main_menu(event, pos); // <- Если нажата кнопка назад
		car.Player_MouseButtonPressed(event, pos); // <- Если нажали на стрелочку и хотим её передвинуть
		car.Player_MouseButtonReleased(event, map_1, pos); // <- Если мы отпустили кнопку после передвижения стрелочки
	}
	if (menu.Return_screen_text() == "main.png") // <- Если мы в главном меню
	{
		menu.Menu_MouseButtonEvent(window, event, pos);
	}
	if (menu.Return_screen_text() == "settings.png") // <- если мы в настройках
	{
		menu.Work_with_settings(event, my_music, pos);
	}
}

void Player::Draw_graphics(RenderWindow& window)
{
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
}

void Player::Move_car_on_rows()
{
	if (menu.Return_screen_text() == "left.png") // <- Если мы в игре, обрабатываем движение машинки и стрелочки
	{
		car.Move_control(pos);
	}
}

//void Player::Music_on_victory()
//{
//	my_music.Stop_fon_music();
//	my_music.Play_game_over_music();
//}
