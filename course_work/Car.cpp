#include "Car.h"

Car::Car(Map& map_1) // <- Стандартный конструктор
{
	x = map_1.Return_burn().x + 64 + 5;
	y = map_1.Return_burn().y + 128 + 5;
	vector = map_1.Return_vector();
	texture_cars.loadFromFile("pictures/sprite_list_cars.png");
	sprite_cars.setTexture(texture_cars);
	sprite_cars.setPosition(x, y);

	arrows_texture.loadFromFile("pictures/sprite_list_arrows.png");
	arrows_sprite.setTexture(arrows_texture);

	for (int i = 0; i < map_1.Return_H(); i++)
	{
		for (int j = 0; j < map_1.Return_W() - 1; j++)
		{
			if (map_1.title_map_1[i][j] == 'J')
			{
				capacity_arrows++;
			}
		}
	}

	switch (vector)
	{
	    case (1):
    	{
	    	sprite_cars.setTextureRect(IntRect(0, 34, 40, 22));
	    	break;
	    }
	    case (2):
	    {
		    sprite_cars.setTextureRect(IntRect(0, 0, 22, 36));
		    break;
    	}
	    case (3):
	    {
		    sprite_cars.setTextureRect(IntRect(20, 0, 38, 24));
		    break;
	    }
	    case(4):
	    {
		    sprite_cars.setTextureRect(IntRect(56, 0, 22, 40));
		    break;
	    }
	}

	arrows = new Sprite[capacity_arrows + 1];

	font_for_text_for_win.loadFromFile("font/font.ttf");
	text_for_win.setStyle(Text::Bold);
	text_for_win.setFillColor(Color::Red);
	text_for_win.Italic;
	text_for_win.setPosition(320, 0);
}

void Car::Move_control(Vector2f pos) // <- Выбор движения машинки или обработка передвижения стрелочки
{
	if (arrow_is_move)
	{
		arrows[number_of_move_arrow].setPosition(pos.x - dx_number_of_arrow, pos.y - dy_number_of_arrow);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		sprite_cars.setTextureRect(IntRect(0, 34, 40, 22));
		sprite_cars.move(0.1 * time, 0);
		x += 0.1 * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		sprite_cars.setTextureRect(IntRect(0, 0, 22, 36));
		sprite_cars.move(0, 0.1 * time);
		y += 0.1 * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		sprite_cars.setTextureRect(IntRect(20, 0, 38, 24));
		sprite_cars.move(-0.1 * time, 0);
		x += -0.1 * time;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		sprite_cars.setTextureRect(IntRect(56, 0, 22, 40));
		sprite_cars.move(0, -0.1 * time);
		y += -0.1 * time;
	}
}

void Car::Go_without_time(const int& vector, RenderWindow& window)
{
	this->vector = vector;
	switch (vector)
	{
	case (1):
	{
		sprite_cars.setTextureRect(IntRect(0, 34, 40, 22));
		sprite_cars.move(0.1, 0);
		x += 0.1;
		break;
	}
	case (2):
	{
		sprite_cars.setTextureRect(IntRect(0, 0, 22, 36));
		sprite_cars.move(0, 0.1);
		y += 0.1;
		break;
	}
	case (3):
	{
		sprite_cars.setTextureRect(IntRect(20, 0, 38, 24));
		sprite_cars.move(-0.1, 0);
		x += -0.1;
		break;
	}
	case(4):
	{
		sprite_cars.setTextureRect(IntRect(56, 0, 22, 40));
		sprite_cars.move(0, -0.1);
		y += -0.1;
		break;
	}
	default:
	{
		window.draw(sprite_cars);
		break;
	}
	}
}

void Car::Go_with_time(const int& vector)
{
	this->vector = vector;
	switch (vector)
	{
	case (1):
	{
		sprite_cars.setTextureRect(IntRect(0, 34, 40, 22));
		sprite_cars.move(0.1 * time, 0);
		x += 0.1 * time;
		break;
	}
	case (2):
	{
		sprite_cars.setTextureRect(IntRect(0, 0, 22, 36));
		sprite_cars.move(0, 0.1 * time);
		y += 0.1 * time;
		break;
	}
	case (3):
	{
		sprite_cars.setTextureRect(IntRect(20, 0, 38, 24));
		sprite_cars.move(-0.1 * time, 0);
		x += -0.1 * time;
		break;
	}
	case(4):
	{
		sprite_cars.setTextureRect(IntRect(56, 0, 22, 40));
		sprite_cars.move(0, -0.1 * time);
		y += -0.1 * time;
		break;
	}
	}
}

void Car::Player_MouseButtonPressed(const Event& event, Vector2f pos) // <- Обработка передвижения стрелочки
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((arrow_is_move) && (arrows[number_of_move_arrow].getGlobalBounds().contains(pos.x, pos.y))) // <- Если уже двигаем
			{
				dx_number_of_arrow = arrows[number_of_move_arrow].getPosition().x;
				dy_number_of_arrow = arrows[number_of_move_arrow].getPosition().y;
			}
			else if ((!arrow_is_move) && (pos.x > 320) && (pos.y > 64) && (pos.x < 352) && (pos.y < 96)) // <- Если на исходных 4-ёх стрелочках
			{
				vector_of_arrows_int = 1;
				vector_arrows_string = '1';
				size_arrows++;
				number_of_move_arrow = size_arrows;
				arrows[number_of_move_arrow].setTexture(arrows_texture);
				arrows[number_of_move_arrow].setTextureRect(IntRect(32, 0, 32, 32));
				arrows[number_of_move_arrow].setPosition(320, 64);
				arrow_is_move = true;
			}
			else if ((!arrow_is_move) && (pos.x > 384) && (pos.y > 64) && (pos.x < 416) && (pos.y < 96))
			{
				vector_of_arrows_int = 2;
				vector_arrows_string = '2';
				size_arrows++;
				number_of_move_arrow = size_arrows;
				arrows[number_of_move_arrow].setTexture(arrows_texture);
				arrows[number_of_move_arrow].setTextureRect(IntRect(32, 32, 32, 32));
				arrows[number_of_move_arrow].setPosition(384, 64);
				arrow_is_move = true;
			}
			else if ((!arrow_is_move) && (pos.x > 448) && (pos.y > 64) && (pos.x < 480) && (pos.y < 96))
			{
				vector_of_arrows_int = 3;
				vector_arrows_string = '3';
				size_arrows++;
				number_of_move_arrow = size_arrows;
				arrows[number_of_move_arrow].setTexture(arrows_texture);
				arrows[number_of_move_arrow].setTextureRect(IntRect(0, 32, 32, 32));
				arrows[number_of_move_arrow].setPosition(448, 64);
				arrow_is_move = true;
			}
			else if ((!arrow_is_move) && (pos.x > 512) && (pos.y > 64) && (pos.x < 544) && (pos.y < 96))
			{
				vector_of_arrows_int = 4;
				vector_arrows_string = '4';
				size_arrows++;
				number_of_move_arrow = size_arrows;
				arrows[number_of_move_arrow].setTexture(arrows_texture);
				arrows[number_of_move_arrow].setTextureRect(IntRect(0, 0, 32, 32));
				arrows[number_of_move_arrow].setPosition(512, 64);
				arrow_is_move = true;
			}
			else if ((!arrow_is_move)) // <- Если указатель мыши на созданных стрелочках
			{
				for (int i = 0; i < size_arrows + 1; i++) // <- Проверяем нажатие на i-ый спрайт
				{
					if (arrows[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						number_of_move_arrow = i;
						arrow_is_move = true;
						break;
					}
				}
			}
		}
	}
}

void Car::Player_MouseButtonReleased(const Event& event, const Map& map_1, Vector2f pos) // <- После отпускания кнопки мыши, которая тащила стрелочку
{
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.key.code == Mouse::Left)
		{
			if (arrow_is_move) // <- Для стрелочки
			{
				if ((pos.x > 64) && (pos.y > 128) && (pos.x < (960 + 32)) && (pos.y < (384 + 96)) && (map_1.title_map_1[(int)(arrows[number_of_move_arrow].getPosition().y / 32 - 4)][(int)(arrows[number_of_move_arrow].getPosition().x / 32 - 2)] == 'J'))
				{
					for (int i = 0; i < size_arrows; i++)  // <- Если на месте уже находится стрелочка, вернуть спрайт в исходную позицию
					{
						if (arrows[i].getGlobalBounds().contains(pos.x, pos.y))
						{
							in_this_rectangle_has_arrow = true;
							for (int j = number_of_move_arrow; j < size_arrows; j++)
							{
								arrows[i] = arrows[i + 1];
							}
							size_arrows--;
							break;
						}
					}
					if (!in_this_rectangle_has_arrow)
					{
						arrows[number_of_move_arrow].setPosition(((int)pos.x / 32) * 32, ((int)pos.y / 32) * 32);
						map_1.title_map_[(int)(arrows[number_of_move_arrow].getPosition().y / 32 - 4)][(int)(arrows[number_of_move_arrow].getPosition().x / 32 - 2)] = vector_arrows_string;
					}
				}
				else
				{
					for (int i = number_of_move_arrow; i < size_arrows; i++)
					{
						arrows[i] = arrows[i + 1];
					}
					size_arrows--;
				}
				arrow_is_move = false;
				in_this_rectangle_has_arrow = false;
			}
		}
	}
}

void Car::Restart_time() // <- Обновление времени
{
	time = clock.getElapsedTime().asMicroseconds();
	clock.restart();
	time = time / 800;
}

void Car::Draw_arrows(RenderWindow& window) // <- Отрисовка стрелочек
{
	for (int i = 0; i < size_arrows + 1; i++)
	{
		window.draw(arrows[i]);
	}
}

void Car::Car_go(const Map& map_1, RenderWindow& window, Musics& my_music) // <- Автоматическое движение машинки к финишу
{
	int vector_was{ vector };

	while ((map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'J') && (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X'))
	{
		Go_without_time(vector, window);
	}

	while (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X')
	{
		if (map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == '1')
		{
			if ((map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 1)] == 'W') && (vector_was != 3))
			{
				vector_was = 1;
				while (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'J')
				{
					Go_without_time(1, window);
				}
				while ((map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'J') && (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X'))
				{
					Go_without_time(1, window);
				}
			}
			else goto label;
		}
		if (map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == '2')
		{
			if ((map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 3)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'W') && (vector_was != 4))
			{
				vector_was = 2;
				while (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'J')
				{
					Go_without_time(2, window);
				}
				while ((map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'J') && (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X'))
				{
					Go_without_time(2, window);
				}
			}
			else goto label;
		}
		if (map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == '3')
		{
			if ((map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 3)] == 'W') && (vector_was != 1))
			{
				vector_was = 3;
				while (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'J')
				{
					Go_without_time(3, window);
				}
				while ((map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'J') && (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X'))
				{
					Go_without_time(3, window);
				}
			}
			else goto label;
		}
		if (map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == '4')
		{
			if ((map_1.title_map_[(int)(sprite_cars.getPosition().y / 32 - 5)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'W') && (vector_was != 2))
			{
				vector_was = 4;
				while (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'J')
				{
					Go_without_time(4, window);
				}
				while ((map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'J') && (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] != 'X'))
				{
					Go_without_time(4, window);
				}
			}
			else goto label;
		}
	}
label:
	if (map_1.title_map_1[(int)(sprite_cars.getPosition().y / 32 - 4)][(int)(sprite_cars.getPosition().x / 32 - 2)] == 'X')
	{
		my_music.Stop_fon_music();
		my_music.Play_game_over_music();
		enable_text_for_win = true;
	}
}

Sprite Car::Return_sprite_cars()
{
	return sprite_cars;
}

//void Car::Go_to_vector_1(RenderWindow& window)
//{
//	for (int i = 0; i < 320; i++)
//	{
//		Go_without_time(1, window);
//	}
//}

void Car::Restart_level(Map& map_1, Musics& my_music)
{
	size_arrows = -1;
	sprite_cars.setPosition(map_1.Return_burn().x + 64 + 5, map_1.Return_burn().y + 128 + 5);
	vector = map_1.Return_vector();
	my_music.Stop_game_over_music();
	my_music.Play_fon_music();
	enable_text_for_win = false;
}

bool Car::Return_enable_text_for_win()
{
	return enable_text_for_win;
}

Text Car::Return_text_for_win()
{
	return text_for_win;
}