#include <SFML/Graphics.hpp>
#include "Music.h"
#include "Level.h"
#include <vector>

#ifndef Car_
#define Car_

class Car
{
public:
	Car();
	~Car() = default;

	void Load_car(Level& lev);
	void Go_without_time();
	void Player_MouseButtonPressed(const Event& event, const Vector2f& pos);
	void Player_MouseButtonReleased(const Event& event, const Vector2f& pos);
	void Restart_time();
	void Draw_additional_arrows(RenderWindow& window);
	void Draw_arrows(RenderWindow& window);
	void Restart_level(Musics& my_music);
	void Pick_texture_for_car();
	void Set_enable_text_for_win(const bool& boolean);
	void Choose_arrow(const string& number, const int& x_, const int& y_);
	void Move_arrow(const Vector2f& pos);

	bool Return_enable_text_for_win();
	bool Check_collision_with_arrows_for_car_go();
	bool Check_collision_with_exit_for_car_go();
	bool Check_on_true_vector();

	Text Return_text_for_win();

	String Check_collision_with_plate(const Vector2f& pos, const String& number_arrow);

	Sprite Return_sprite_cars();
private:
	Texture texture_cars;
	Sprite sprite_cars;
	float x{ 0 }; // <- х-координата машинки
	float y{ 0 }; // <- у-координата машинки
	int vector{ -1 }; // 1 - right, 2 - down, 3 - left, 4 - up

	Texture arrows_texture;
	Sprite arrows_sprite;

	Clock clock; // Переменная времени
	float time{ 0.0 };

	float dx_car{ 0 }; // <- х-координата при передвижении машинки
	float dy_car{ 0 }; // <- у-координата при передвижении машинки

	Sprite* arrows; // <- Массив спрайтов для создания новых стрелочек при их перемещении на таблички
	int capacity_arrows{ 0 };  // <- Размер массива спрайтов
	int size_arrows{ -1 }; // <- Количество текущих значений в массиве (количество спрайтов)
	int number_of_move_arrow{ 0 };  // <- Номер текущего передвигаемого спрайта
	String vector_arrows_string{ "" }; // <- Хранение циферки для таблички на карте
	float dx_number_of_arrow{ 0 };  // <- х-позиция текущего передвигаемого спрайта
	float dy_number_of_arrow{ 0 };  // <- у-позиция текущего передвигаемого спрайта
	bool arrow_is_move{ false };  // <- Передвигаем ли мы спрайт

	Font font_for_text_for_win;
	Text text_for_win = Text("You are win!!!", font_for_text_for_win, 128);
	bool enable_text_for_win{ false };

	Object burn; // Объект точки рождения
	int burn_vector{ -1 }; // Вектор рождения

	Object exit; // Объект точки выхода

	std::vector<Object> obj; // Вектор объектов карты
	std::vector<Object> vector_of_right_direction; // Вектор первоначальных объектов с правильными направлениями
};

#endif // !Car
