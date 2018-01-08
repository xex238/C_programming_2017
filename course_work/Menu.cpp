#include "Menu.h"
#include <SFML\Graphics.hpp>
using namespace sf;

Menu::Menu(const String& main, const String& left, const String& settings, const String& rectangle, const String& string_for_restart_level) // <- Стандартный конструктор
{
	restart_level_texture.loadFromFile(string_for_restart_level);
	restart_level_sprite.setTexture(restart_level_texture);
	restart_level_sprite.setPosition(64, 0);

	main_texture.loadFromFile(main);
	main_sprite.setTexture(main_texture);

	left_texture.loadFromFile(left);
	left_sprite.setTexture(left_texture);
	left_sprite.setPosition(0, 0);

	settings_texture.loadFromFile(settings);
	settings_sprite.setTexture(settings_texture);

	rectangle_texture.loadFromFile(rectangle);
	rectangle_sprite.setTexture(rectangle_texture);

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

void Menu::Menu_MouseButtonReleased_left(RenderWindow & window) // <- Если отпущена кнопка в меню
{
	if ((pos.x > 500) && (pos.x < 750) && (pos.y > 130) && (pos.y < 190))
	{
		screen_text = "left.png";
	}
	if ((pos.x > 470) && (pos.x < 780) && (pos.y > 340) && (pos.y < 390))
	{
		window.close();
	}
	if ((pos.x > 510) && (pos.x < 725) && (pos.y > 235) && (pos.y < 290))
	{
		screen_text = "settings.png";
	}
	enable_rectangle_sprite = false;
}

void Menu::Menu_MouseButtonPressed_left(const RenderWindow& window) // <- Если нажата кнопка в меню
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

void Menu::Menu_MouseButtonEvent(RenderWindow& window, const Event& event) // <- Нажата ли кнопка или отпущена
{
	Menu_MouseButtonPressed_left(window);
	if ((event.type == Event::MouseButtonReleased) && (event.key.code == Mouse::Left))
	{
		Menu_MouseButtonReleased_left(window);
	}
}

void Menu::Work_with_settings(const Event& event, Musics& my_music) // <- Работа с громкостью звука в настройках
{
	int text_int_settings[3]{ 0, 0, 0 };
	std::string txt = "";  // третья цифра тут - первая на консоли // 48 is number 0, 49 is number 1, 53 is number 5
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x > 950) && (pos.y > 150) && (pos.x < 1080) && (pos.y < 250))
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
			if (sound_bufer_volume == 0)
			{
				if ((pos.x > 625) && (pos.x < 675) && (pos.y > 185) && (pos.y < 235))
				{
					if ((text_int_real[2] == 0) && (text_int_real[0] == 0))
					{
						text_int_real[2] = 5;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() + 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() + 5);
					}
					else if ((text_int_real[2] == 5) && (text_int_real[1] < 9))
					{
						text_int_real[2] = 0;
						text_int_real[1] = text_int_real[1] + 1;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() + 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() + 5);
					}
					else if ((text_int_real[2] == 5) && (text_int_real[1] == 9))
					{
						text_int_real[0] = 1;
						text_int_real[1] = 0;
						text_int_real[2] = 0;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() + 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() + 5);
					}
				}
				if ((pos.x > 835) && (pos.x < 885) && (pos.y > 185) && (pos.y < 235))
				{
					if ((text_int_real[2] == 5) && (text_int_real[1] > 0))
					{
						text_int_real[2] = text_int_real[2] - 5;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() - 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() - 5);
					}
					else if ((text_int_real[2] == 0) && (text_int_real[1] > 0))
					{
						text_int_real[2] = 5;
						text_int_real[1] = text_int_real[1] - 1;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() - 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() - 5);
					}
					else if ((text_int_real[1] == 0) && (text_int_real[0] == 1))
					{
						text_int_real[0] = 0;
						text_int_real[1] = 9;
						text_int_real[2] = 5;
						my_music.Fon_music_set_volume(my_music.Fon_music_get_volume() - 5);
						my_music.Game_over_music_set_volume(my_music.Fon_music_get_volume() - 5);
					}
				}
				if (text_int_real[0] == 0)
					for (int i = 1; i < 3; i++)
					{
						text_int_settings[i] = text_int_real[i] + 48;
						txt += text_int_settings[i];
					}
				else
				{
					for (int i = 0; i < 3; i++)
					{
						text_int_settings[i] = text_int_real[i] + 48;
						txt += text_int_settings[i];
					}
				}
				text.setString(txt);
			}
		}
	}
	if (event.type == Event::MouseButtonReleased)
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

void Menu::Return_to_main_menu(const Event& event)
{
	if (event.type == Event::MouseButtonReleased)
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

void Menu::Update_pos(const RenderWindow& window) // <- Обновление позиции мыши на экране
{
	pixel_pos = Mouse::getPosition(window);
	pos = window.mapPixelToCoords(pixel_pos);
}

void Menu::Restart_level(const Event& event, Player& car, Map& map_1, Musics& my_music) // <- Перезагрузка уровня
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((pos.x > 64) && (pos.x < 96) && (pos.y < 32))
			{
				car.Restart_level(map_1, my_music);
			}
		}
	}
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

bool Menu::Return_enable_rectangle_sprite()
{
	return enable_rectangle_sprite;
}
