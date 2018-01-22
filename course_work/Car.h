#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Music.h"
#ifndef Car_
#define Car_

class Car
{
public:
	Car(Map& map_1);

	~Car() = default;

	void Move_control(Vector2f pos);

	void Go_without_time(const int& vector, RenderWindow& window);

	void Go_with_time(const int& vector);

	void Player_MouseButtonPressed(const Event& event, Vector2f pos);

	void Player_MouseButtonReleased(const Event& event, const Map& map_1, Vector2f pos);

	void Restart_time();

	void Draw_arrows(RenderWindow& window);

	void Car_go(const Map& map_1, RenderWindow& window, Musics& my_music);

	Sprite Return_sprite_cars();

	//void Go_to_vector_1(RenderWindow& window);

	void Restart_level(Map& map_1, Musics& my_music);

	bool Return_enable_text_for_win();

	Text Return_text_for_win();

private:
	Texture texture_cars;
	Sprite sprite_cars;
	float x{ 0 }; // <- �-���������� �������
	float y{ 0 }; // <- �-���������� �������
	int vector; // 1 - right, 2 - down, 3 - left, 4 - up

	Texture arrows_texture;
	Sprite arrows_sprite;

	Clock clock;
	float time;

	float dx_car{ 0 }; // <- �-���������� ��� ������������ �������
	float dy_car{ 0 }; // <- �-���������� ��� ������������ �������

	Sprite* arrows;
	int capacity_arrows{ 0 };  // <- ������ ������� ��������
	int size_arrows{ -1 }; // <- ���������� ������� �������� � ������� (���������� ��������)
	int number_of_move_arrow{ 0 };  // <- ����� �������� �������������� �������
	String vector_arrows_string{ "" };
	int vector_of_arrows_int{ 0 };
	float dx_number_of_arrow{ 0 };  // <- �-������� �������� �������������� �������
	float dy_number_of_arrow{ 0 };  // <- �-������� �������� �������������� �������
	bool arrow_is_move = false;  // <- ����������� �� �� ������
	bool in_this_rectangle_has_arrow = false;  // ���� �� �� ������� ������� ���� ������

	Font font_for_text_for_win;
	Text text_for_win = Text("You are win!!!", font_for_text_for_win, 128);
	bool enable_text_for_win = false;
};

#endif // !Car