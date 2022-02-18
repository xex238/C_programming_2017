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
	void Car_go(RenderWindow& window);
	void Choose_level_for_load(Event& event);
	void Load_level(Level& level_, const String& string_level);
private:
	Level level_1; // <- Переменная уровня
	Level level_2;
	Level level_3;
	Level level_4;
	Level level_5;

	int level{ 0 };

	Menu menu; // <- Переменная меню (Инициализируется сразу)

	Car car; // <- Переменная машинки

	Musics my_music; // <- Переменная музыки (инициализируется сразу)

	Vector2i pixel_pos; // <- Координаты мыши в пикселях
	Vector2f pos; // <- Координаты мыши
};

#endif // !Player_
