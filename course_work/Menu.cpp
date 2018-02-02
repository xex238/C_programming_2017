#include "Menu.h"
#include <iostream>
#include <sstream>

Menu::Menu()
{
	restart_level_texture.loadFromFile("pictures/restart_level.png");
	restart_level_sprite.setTexture(restart_level_texture);
	restart_level_sprite.setPosition(64, 0);

	main_texture.loadFromFile("pictures/main_menu.png");
	main_sprite.setTexture(main_texture);

	left_texture.loadFromFile("pictures/arrow_back.png");
	left_sprite.setTexture(left_texture);
	left_sprite.setPosition(0, 0);

	settings_texture.loadFromFile("pictures/settings.png");
	settings_sprite.setTexture(settings_texture);

	rectangle_texture.loadFromFile("pictures/rectangle.png");
	rectangle_sprite.setTexture(rectangle_texture);

	level_screen_texture.loadFromFile("maps/Lev.png");
	level_screen_sprite.setTexture(level_screen_texture);

	sounds_enable_list_texture.loadFromFile("pictures/sprite_list_sign_of_the_volume_1.png");
	sounds_enable_list_sprite.setTexture(sounds_enable_list_texture);
	sounds_enable_list_sprite.setPosition(950, 150);
	sounds_enable_list_sprite.setTextureRect(IntRect(0, 0, 130, 110));

	screen_text = "main.png";

	font.loadFromFile("font/font.ttf");
	text.setStyle(Text::Bold);
	text.setFillColor(Color::Red);
	text.Italic;
	text.setPosition(750, 185);

	std::string txt_1;
	int txt[3]{ 48, 48, 49 };
	txt_1 += txt[2];
	txt_1 += txt[1];
	txt_1 += txt[0];
	text.setString(txt_1);
}

void Menu::Menu_MouseButtonReleased_left(RenderWindow& window, const Vector2f& pos) // <- Если отпущена кнопка в меню
{
	if ((pos.x > 500) && (pos.x < 750) && (pos.y > 130) && (pos.y < 190)) // Если мы нажали кнопку "Играть"
	{
		screen_text = "level_load";
	}
	if ((pos.x > 470) && (pos.x < 780) && (pos.y > 340) && (pos.y < 390)) // Если мы нажали кнопку "Выйти из игры"
	{
		window.close();
	}
	if ((pos.x > 510) && (pos.x < 725) && (pos.y > 235) && (pos.y < 290)) // Если мы нажали кнопку "Настройки"
	{
		screen_text = "settings.png";
	}
	enable_rectangle_sprite = false;
}
void Menu::Menu_MouseButtonPressed_left(const RenderWindow& window, const Vector2f& pos) // <- Если нажата кнопка в меню
{
	if ((pos.x > 500) && (pos.x < 750) && (pos.y > 130) && (pos.y < 190))
	{
		rectangle_sprite.setTextureRect(IntRect(0, 0, 245, 3));
		rectangle_sprite.setPosition(500, 180);
		enable_rectangle_sprite = true;
	}
	else if ((pos.x > 510) && (pos.x < 725) && (pos.y > 235) && (pos.y < 290))
	{
		rectangle_sprite.setTextureRect(IntRect(0, 0, 220, 3));
		rectangle_sprite.setPosition(510, 285);
		enable_rectangle_sprite = true;
	}
	else if ((pos.x > 470) && (pos.x < 780) && (pos.y > 340) && (pos.y < 390))
	{
		rectangle_sprite.setTextureRect(IntRect(0, 0, 276, 3));
		rectangle_sprite.setPosition(490, 390);
		enable_rectangle_sprite = true;
	}
	else
	{
		enable_rectangle_sprite = false;
	}
}
void Menu::Menu_MouseButtonEvent(RenderWindow& window, const Event& event, const Vector2f& pos) // <- Нажата ли кнопка или отпущена
{
	Menu_MouseButtonPressed_left(window, pos);
	if ((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left))
	{
		Menu_MouseButtonReleased_left(window, pos);
	}
}
void Menu::Work_with_settings(const Event& event, Musics& my_music, const Vector2f& pos) // <- Работа с громкостью звука в настройках
{
	int gromkost_int{ 0 }; // <- Величины для перехода от int к string
	stringstream gromkost_string;
	string gromkost;

	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x > 950) && (pos.y > 150) && (pos.x < 1080) && (pos.y < 250)) // Включить/выключить звук
			{
				if (sounds_enable)
				{
					sounds_enable_list_sprite.setTextureRect(IntRect(135, 0, 130, 110));
					sound_bufer_volume = my_music.Fon_music_get_volume();
					my_music.Fon_music_set_volume(0);
					my_music.Game_over_music_set_volume(0);
					sounds_enable = false;
				}
				else
				{
					sounds_enable_list_sprite.setTextureRect(IntRect(0, 0, 130, 110));
					my_music.Fon_music_set_volume(sound_bufer_volume);
					my_music.Game_over_music_set_volume(sound_bufer_volume);
					sound_bufer_volume = 0;
					sounds_enable = true;
				}
			}
			if (sounds_enable)
			{
				if ((pos.x > 625) && (pos.x < 675) && (pos.y > 185) && (pos.y < 235)) // Если прибавляем звук
				{
					if (my_music.Fon_music_get_volume() < 95)
					{
						my_music.Fon_music_set_volume((int)((int)(my_music.Fon_music_get_volume() + 0.5) + 5)); // Увеличиваем громкость звука на 5
						gromkost_int = my_music.Fon_music_get_volume(); // Получение громкости звука
						gromkost_string << gromkost_int;
						gromkost = gromkost_string.str();
						text.setString(gromkost);
					}
				}
				if ((pos.x > 835) && (pos.x < 885) && (pos.y > 185) && (pos.y < 235)) // Если убавляем звук
				{
					if (my_music.Fon_music_get_volume() > 5)
					{
						my_music.Fon_music_set_volume((int)((int)(my_music.Fon_music_get_volume() + 0.5) - 5)); // Уменьшаем громкость звука на 5
						gromkost_int = my_music.Fon_music_get_volume(); // Получение громкости звука
						gromkost_string << gromkost_int;
						gromkost = gromkost_string.str();
						text.setString(gromkost);
					}
				}
			}
		}
	}
	if (event.type == Event::MouseButtonReleased) // Если нажата кнопка "назад"
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x < 32) && (pos.y < 32))
			{
				screen_text = "main.png";
			}
		}
	}
}
void Menu::Return_to_main_menu(const Event& event, const Vector2f& pos, Car& car, Level& level, Musics& my_music) // Вернуться из игры к выбору уровней
{
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x < 32) && (pos.y < 32))
			{
				screen_text = "level_load";
				car.Set_enable_text_for_win(false);
				if (play_game_over_music)
				{
					my_music.Stop_game_over_music();
					my_music.Play_fon_music();
				}
				//car.~Car(); // Очистить память, связанную с машинкой
				//level_1.~Level(); // Очистить память, связанную с уровнем
			}
		}
	}
}
void Menu::Restart_level(const Event& event, Car& car, Musics& my_music, const Vector2f& pos) // <- Перезагрузка уровня
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x > 64) && (pos.x < 96) && (pos.y < 32))
			{
				car.Restart_level(my_music);
			}
		}
	}
} 
void Menu::Set_screen_text(const String& screen_text_)
{
	screen_text = screen_text_;
}
void Menu::Set_play_game_over_music(const bool& boolean)
{
	play_game_over_music = boolean;
}

bool Menu::Return_enable_rectangle_sprite()
{
	return enable_rectangle_sprite;
}

Text Menu::Return_text()
{
	return text;
}

String Menu::Return_screen_text()
{
	return screen_text;
}

Sprite Menu::Return_sounds_enable_list_sprite()
{
	return sounds_enable_list_sprite;
}
Sprite Menu::Return_main_sprite()
{
	return main_sprite;
}
Sprite Menu::Return_left_sprite()
{
	return left_sprite;
}
Sprite Menu::Return_settings_sprite()
{
	return settings_sprite;
}
Sprite Menu::Return_rectangle_sprite()
{
	return rectangle_sprite;
}
Sprite Menu::Return_restart_level_sprite()
{
	return restart_level_sprite;
}
Sprite Menu::Return_level_screen_sprite()
{
	return level_screen_sprite;
}
