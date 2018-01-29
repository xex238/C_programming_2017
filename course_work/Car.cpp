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

	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			obj[i].type = "-1";
		}
	}

	burn = lev.GetObject("burn"); // <- Объекту burn присваеваем одноимённый объект
	x = burn.rect.left + 5;
	y = burn.rect.top + 5;
	burn_vector = atoi(burn.type.c_str()); // <- Присваеваем вектор "рождения"
	vector = burn_vector;

	sprite_cars.setPosition(x, y);

	exit = lev.GetObject("exit"); // <- Объекту exit присваеваем одноимённый объект

	for (int i = 0; i < obj.size(); i++) // Считаем количество табличек
	{
		if (obj[i].name == "plate")
		{
			capacity_arrows++;
		}
	}
	Pick_texture_for_car();
	arrows = new Sprite[capacity_arrows + 1];
}

void Car::Move_control(const Vector2f& pos) // <- Выбор движения машинки или обработка передвижения стрелочки
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

void Car::Go_without_time(const int& vector/*, RenderWindow& window*/)
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
	//default:
	//{
	//	window.draw(sprite_cars);
	//	break;
	//}
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
				vector_arrows_string = '4';
				size_arrows++;
				number_of_move_arrow = size_arrows;
				arrows[number_of_move_arrow].setTexture(arrows_texture);
				arrows[number_of_move_arrow].setTextureRect(IntRect(0, 0, 32, 32));
				arrows[number_of_move_arrow].setPosition(512, 64);
				arrow_is_move = true;
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

void Car::Draw_additional_arrows(RenderWindow& window) // <- Отрисовка стрелочек
{
	for (int i = 0; i < size_arrows + 1; i++)
	{
		window.draw(arrows[i]);
	}
}

void Car::Draw_arrows(RenderWindow& window)
{
	arrows_sprite.setTextureRect(IntRect(32, 0, 32, 32));  // <- Загрузка текстур значков
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

void Car::Car_go(/*RenderWindow& window, */Musics& my_music) // <- Автоматическое движение машинки к финишу
{
	while (!(Check_collision_with_exit_for_car_go(x, y))) // Пока не дошли до выхода
	{
		// Пока не дошли до таблички и не дошли до выхода, идём вперёд по вектору
		while ((!Check_collision_with_arrows_for_car_go(x, y)) && (!Check_collision_with_exit_for_car_go(x, y)))
		{
			Go_without_time(vector/*, window*/);
		}
		// Если мы стоим на табличке и не стоим на выходе, то идём, пока не "не кончится" табличка
		if ((Check_on_true_vector(x, y)) && (!Check_collision_with_exit_for_car_go(x, y)))
		{
			while (Check_collision_with_arrows_for_car_go(x, y))
			{
				Go_without_time(vector/*, window*/);
			}
		}
		else
		{
			break;
		}
	}
	if (Check_collision_with_exit_for_car_go(x, y))
	{
		std::cout << "Yslovie vipolneno" << std::endl;
		my_music.Stop_fon_music();
		my_music.Play_game_over_music();
		enable_text_for_win = true;
	}
}

Sprite Car::Return_sprite_cars()
{
	return sprite_cars;
}

void Car::Restart_level(Musics& my_music)
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			obj[i].type = "-1";
		}
	}
	size_arrows = -1;
	x = burn.rect.left + 5;
	y = burn.rect.top + 5;
	burn_vector = atoi(burn.type.c_str());
	vector = burn_vector;
	Pick_texture_for_car();
	sprite_cars.setPosition(x, y);
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

bool Car::Check_collision_with_arrows_for_car_go(const float& x_, const float& y_)
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			if ((obj[i].rect.left < x_) && (obj[i].rect.left + obj[i].rect.width > x_) && (obj[i].rect.top < y_) && (obj[i].rect.top + obj[i].rect.height > y_))
			{
				return true;
			}
		}
	}
	return false;
}

bool Car::Check_collision_with_exit_for_car_go(const float& x_, const float& y_)
{
	if ((exit.rect.left < x_) && (exit.rect.left + exit.rect.width > x_) && (exit.rect.top < y_) && (exit.rect.top + exit.rect.height > y_))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::Check_on_true_vector(const float & x_, const float & y_)
{
	for (int i = 0; i < obj.size(); i++)
	{
		if (obj[i].name == "plate")
		{
			if ((obj[i].rect.left < x_) && (obj[i].rect.left + obj[i].rect.width > x_) && (obj[i].rect.top < y_) && (obj[i].rect.top + obj[i].rect.height > y_))
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

void Car::Pick_texture_for_car()
{
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
}
