#include <SFML/Graphics.hpp>
using namespace sf;
#include "Map.h"
#include "Massiv_arrows.h"
#include "Music.h"
#include <string>
#ifndef Player_
#define Player_

class Player
{
public:
	Player(const String& string_for_load_car_texture, const String& string_for_load_arrows_texture, Map& map_1);

	~Player() = default;

	void Move_control();

	void Go_without_time(const int& vector, RenderWindow& window);

	void Go_with_time(const int& vector);

	void Player_MouseButtonPressed(const Event& event);

	void Player_MouseButtonReleased(const Event& event, const Map& map_1);

	void Restart_time();

	void Update_pos(RenderWindow& window);

	void Draw_arrows(RenderWindow& window);

	void Car_go(const Map& map_1, RenderWindow& window, Musics& my_music);

	Sprite Return_sprite_cars();

	void Go_to_vector_1(RenderWindow& window);

	void Restart_level(Map& map_1, Musics& my_music);

	bool Return_enable_text_for_win();

	Text Return_text_for_win();

private:
	Texture texture_cars;
	Sprite sprite_cars;
	float x{ 0 }; // <- х-координата машинки
	float y{ 0 }; // <- у-координата машинки
	int vector; // 1 - right, 2 - down, 3 - left, 4 - up

	Texture arrows_texture;
	Sprite arrows_sprite;

	Clock clock;
	float time;

	float dx_car{ 0 }; // <- х-координата при передвижении машинки
	float dy_car{ 0 }; // <- у-координата при передвижении машинки

	Vector2i pixel_pos; // <- Координаты мыши в пикселях
	Vector2f pos; // <- Координаты мыши

	Sprite* arrows;
	int capacity_arrows{ 0 };  // <- Размер массива спрайтов
	int size_arrows{ -1 }; // <- Количество текущих значений в массиве (количество спрайтов)
	int number_of_move_arrow{ 0 };  // <- Номер текущего передвигаемого спрайта
	String vector_arrows_string{ "" };
	int vector_of_arrows_int{ 0 };
	float dx_number_of_arrow{ 0 };  // <- х-позиция текущего передвигаемого спрайта
	float dy_number_of_arrow{ 0 };  // <- у-позиция текущего передвигаемого спрайта
	bool arrow_is_move = false;  // <- Передвигаем ли мы спрайт
	bool in_this_rectangle_has_arrow = false;  // Есть ли на позиции зажатой мыши спрайт

	Font font_for_text_for_win;
	Text text_for_win = Text("You are win!!!", font_for_text_for_win, 128);
	bool enable_text_for_win = false;
};

#endif // !Player
