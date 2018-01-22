#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include "Car.h"
#include "Map.h"
#include "Menu.h"
#include "Music.h"
using namespace sf;
#ifndef Player_
#define Player_

class Player
{
public:
	Player(const int x);

	~Player() = default;

	void Refresh(RenderWindow& window);

	void Update_pos(RenderWindow& window);

	void Game_event(RenderWindow& window, Event& event);

	void Draw_graphics(RenderWindow& window);

	void Move_car_on_rows();


	//void Music_on_victory();
	//protected:
	Menu menu;

	Map map_1;

	Car car = Car(map_1);

	Musics my_music;

	Event event;

	Vector2i pixel_pos; // <- Координаты мыши в пикселях
	Vector2f pos; // <- Координаты мыши
};

#endif // !Player_
