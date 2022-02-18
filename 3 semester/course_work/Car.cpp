#include "Car.h"

Car::Car()
{
	texture_cars.loadFromFile("pictures/sprite_list_cars.png");
	sprite_cars.setTexture(texture_cars);

	arrows_texture.loadFromFile("pictures/sprite_list_arrows.png");
	arrows_sprite.setTexture(arrows_texture);

	font_for_text_for_win.loadFromFile("font/font.ttf");
	text_for_win.setStyle(Text::Bold);
	text_for_win.setFillColor(Color::Red);
	text_for_win.Italic;
	text_for_win.setPosition(320, 0);
}

void Car::Load_car(Level& lev) // <- Стандартный конструктор
{
	obj = lev.GetAllObjects(); // <- Делаем копию объектов карты
	vector_of_right_direction = obj; // <- Делаем вторую копию объектов карты
	burn = lev.GetObject("burn"); // <- Объекту burn присваеваем одноимённый объект
	exit = lev.GetObject("exit"); // <- Объекту exit присваеваем одноимённый объект

	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			obj[i].type = "-1";
			capacity_arrows++; // Считаем количество табличек
		}
	}

	burn_vector = atoi(burn.type.c_str()); // <- Присваеваем вектор "рождения"
	vector = burn_vector;
	if ((vector == 1) || (vector == 3))
	{
		x = burn.rect.left + 1;
		y = burn.rect.top + 7;
	}
	if ((vector == 2) || (vector == 4))
	{
		x = burn.rect.left + 7;
		y = burn.rect.top + 1;
	}
	sprite_cars.setPosition(x, y);

	Pick_texture_for_car();
	arrows = new Sprite[capacity_arrows + 1];
}
void Car::Go_without_time() // Обработка движений машинки к финишу
{
	float w = 0.32;
	switch (vector)
	{
	case (1):
	{
		sprite_cars.setTextureRect(IntRect(0, 34, 40, 22));
		sprite_cars.move(w, 0);
		x += w;
		break;
	}
	case (2):
	{
		sprite_cars.setTextureRect(IntRect(0, 0, 22, 36));
		sprite_cars.move(0, w);
		y += w;
		break;
	}
	case (3):
	{
		sprite_cars.setTextureRect(IntRect(20, 0, 38, 24));
		sprite_cars.move(-w, 0);
		x += -w;
		break;
	}
	case(4):
	{
		sprite_cars.setTextureRect(IntRect(56, 0, 22, 40));
		sprite_cars.move(0, -w);
		y += -w;
		break;
	}
	}
}
void Car::Player_MouseButtonPressed(const Event& event, const Vector2f& pos) // <- Обработка передвижения стрелочки
{
	if (event.type == Event::MouseButtonPressed)
	{
		if (event.key.code == Mouse::Left)
		{
			if ((arrow_is_move) && (arrows[number_of_move_arrow].getGlobalBounds().contains(pos.x, pos.y))) // <- Если уже двигаем (перемещаем стрелочку)
			{
				dx_number_of_arrow = arrows[number_of_move_arrow].getPosition().x;
				dy_number_of_arrow = arrows[number_of_move_arrow].getPosition().y;
			}
			else if ((!arrow_is_move) && (pos.x > 320) && (pos.y > 64) && (pos.x < 352) && (pos.y < 96)) // <- Если на исходных 4-ёх стрелочках
			{
				Choose_arrow("1", 32, 0);
			}
			else if ((!arrow_is_move) && (pos.x > 384) && (pos.y > 64) && (pos.x < 416) && (pos.y < 96))
			{
				Choose_arrow("2", 32, 32);
			}
			else if ((!arrow_is_move) && (pos.x > 448) && (pos.y > 64) && (pos.x < 480) && (pos.y < 96))
			{
				Choose_arrow("3", 0, 32);
			}
			else if ((!arrow_is_move) && (pos.x > 512) && (pos.y > 64) && (pos.x < 544) && (pos.y < 96))
			{
				Choose_arrow("4", 0, 0);
			}
			else if (!arrow_is_move) // <- Если указатель мыши на созданных стрелочках
			{
				for (int i = 0; i < size_arrows + 1; i++) // <- Проверяем нажатие на i-ый спрайт
				{
					if (arrows[i].getGlobalBounds().contains(pos.x, pos.y))
					{
						number_of_move_arrow = i;
						arrow_is_move = true;
						Check_collision_with_plate(pos, "-1"); // Находим табличку, что была на этом месте
						break;
					}
				}
			}
		}
	}
}
void Car::Player_MouseButtonReleased(const Event& event, const Vector2f& pos) // <- После отпускания кнопки мыши, которая тащила стрелочку
{
	if (event.type == Event::MouseButtonReleased)
	{
		if (event.key.code == Mouse::Left)
		{
			if (arrow_is_move) // <- Если мы передвигали стрелочку
			{
				// Если мышка в пределах экрана и на её позиции есть свободная табличка, устанавливаем её туда
				if ((pos.x > 64) && (pos.y > 128) && (pos.x < (960 + 32)) && (Check_collision_with_plate(pos, vector_arrows_string) == "-1")/*(pos.y < (384 + 96)) && (map_1.title_map_1[(int)(arrows[number_of_move_arrow].getPosition().y / 32 - 4)][(int)(arrows[number_of_move_arrow].getPosition().x / 32 - 2)] == 'J')*/) // Если мышка в пределах экрана и позиция не занята
				{
					arrows[number_of_move_arrow].setPosition(((int)pos.x / 32) * 32, ((int)pos.y / 32) * 32);
				}
				else // Убираем из массава ту стрелочку, что мы передвигали
				{
					for (int i = number_of_move_arrow; i < size_arrows; i++)
					{
						arrows[i] = arrows[i + 1];
					}
					size_arrows--;
				}
				arrow_is_move = false;
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
void Car::Draw_additional_arrows(RenderWindow& window) // <- Отрисовка дополнительных стрелочек
{
	for (int i = 0; i < size_arrows + 1; i++)
	{
		window.draw(arrows[i]);
	}
}
void Car::Draw_arrows(RenderWindow& window) // <- Загрузка текстур значков
{
	arrows_sprite.setTextureRect(IntRect(32, 0, 32, 32));
	arrows_sprite.setPosition(320, 64);
	window.draw(arrows_sprite);
	
	arrows_sprite.setTextureRect(IntRect(32, 32, 32, 32));
	arrows_sprite.setPosition(384, 64);
	window.draw(arrows_sprite);
	
	arrows_sprite.setTextureRect(IntRect(0, 32, 32, 32));
	arrows_sprite.setPosition(448, 64);
	window.draw(arrows_sprite);
	
	arrows_sprite.setTextureRect(IntRect(0, 0, 32, 32));
	arrows_sprite.setPosition(512, 64);
	window.draw(arrows_sprite);
}
void Car::Restart_level(Musics& my_music) // Перезапуск уровня
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			obj[i].type = "-1";
		}
	}
	size_arrows = -1;
	burn_vector = atoi(burn.type.c_str());
	vector = burn_vector;
	if ((vector == 1) || (vector == 3))
	{
		x = burn.rect.left + 1;
		y = burn.rect.top + 7;
	}
	if ((vector == 2) || (vector == 4))
	{
		x = burn.rect.left + 7;
		y = burn.rect.top + 1;
	}
	Pick_texture_for_car();
	sprite_cars.setPosition(x, y);
	my_music.Stop_game_over_music();
	my_music.Play_fon_music();
	enable_text_for_win = false;
}
void Car::Pick_texture_for_car()
{
	switch (vector)
	{
	case (1):
	{
		sprite_cars.setTextureRect(IntRect(0, 36, 33, 17));
		break;
	}
	case (2):
	{
		sprite_cars.setTextureRect(IntRect(3, 0, 17, 33));
		break;
	}
	case (3):
	{
		sprite_cars.setTextureRect(IntRect(23, 3, 33, 17));
		break;
	}
	case(4):
	{
		sprite_cars.setTextureRect(IntRect(59, 0, 17, 33));
		break;
	}
	}
}
void Car::Set_enable_text_for_win(const bool& boolean)
{
	enable_text_for_win = boolean;
}
void Car::Choose_arrow(const string& number, const int& x_, const int& y_)
{
	vector_arrows_string = number;
	size_arrows++;
	number_of_move_arrow = size_arrows;
	arrows[number_of_move_arrow].setTexture(arrows_texture);
	arrows[number_of_move_arrow].setTextureRect(IntRect(x_, y_, 32, 32));
	arrows[number_of_move_arrow].setPosition(320 + ((atoi(number.c_str()) - 1) * 64), 64);
	arrow_is_move = true;
}
void Car::Move_arrow(const Vector2f& pos)
{
	if (arrow_is_move)
	{
		arrows[number_of_move_arrow].setPosition(pos.x - dx_number_of_arrow, pos.y - dy_number_of_arrow);
	}
}

bool Car::Return_enable_text_for_win()
{
	return enable_text_for_win;
}
bool Car::Check_collision_with_arrows_for_car_go() // Проверка столкновений с табличками
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			if ((obj[i].rect.left < x) && (obj[i].rect.left + obj[i].rect.width > x) && (obj[i].rect.top < y) && (obj[i].rect.top + obj[i].rect.height > y))
			{
				return true;
			}
		}
	}
	return false;
}
bool Car::Check_collision_with_exit_for_car_go() // Проверка столкновения с выходом
{
	if ((exit.rect.left < x) && (exit.rect.left + exit.rect.width > x) && (exit.rect.top < y) && (exit.rect.top + exit.rect.height > y))
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Car::Check_on_true_vector() // Проверка на правильность выбранного напрапвления машинки на повороте
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			if ((obj[i].rect.left < x) && (obj[i].rect.left + obj[i].rect.width > x) && (obj[i].rect.top < y) && (obj[i].rect.top + obj[i].rect.height > y))
			{
				if (obj[i].type == vector_of_right_direction[i].type)
				{
					vector = atoi(obj[i].type.c_str());
					return true;
				}
				else
					return false;
			}
		}
	}
}

Text Car::Return_text_for_win()
{
	return text_for_win;
}

String Car::Check_collision_with_plate(const Vector2f& pos, const String& new_obj_type)
{
	String obj_type{ "" };

	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			if ((obj[i].rect.left < pos.x) && (obj[i].rect.left + obj[i].rect.width > pos.x) && (obj[i].rect.top < pos.y) && (obj[i].rect.top + obj[i].rect.height > pos.y))
			{
				obj_type = obj[i].type;
				obj[i].type = new_obj_type;
				return obj_type;
			}
		}
	}
	return obj_type;
}

Sprite Car::Return_sprite_cars()
{
	return sprite_cars;
}
