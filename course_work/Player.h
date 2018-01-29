#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Car.h"
#include "Menu.h"
#include "Music.h"
#include "Level.h"

#ifndef Player_
#define Player_

class Player
{
public:
	Player();

	~Player() = default;

	void Refresh(const RenderWindow& window);

	void Update_pos(const RenderWindow& window);

	void Game_event(RenderWindow& window, Event& event);

	void Draw_graphics(RenderWindow& window);

	void Move_car_on_rows();
private:
	Level level_1; // <- Переменная уровня

	Menu menu; // <- Переменная меню

	Car car; // <- Переменная машинки

	Musics my_music; // <- Переменная музыки

	Vector2i pixel_pos; // <- Координаты мыши в пикселях
	Vector2f pos; // <- Координаты мыши
};

#endif // !Player_
