#ifndef Map_
#define Map_
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Arrow.h"
#include "Massiv_arrows.h"
#include <string>

class Map
{
public:
	String** title_map_; // <- Копия исходной карты

	const String title_map_1[12] =
	{
		"NNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
		"N                           N",
		"N       JWWWWWWWWJ          N",
		"N       W        W          N",
		"NBWWWWWWJ        W          N",
		"N                W          N",
		"N                W          N",
		"N                JWWWWWX    N",
		"N                           N",
		"N                           N",
		"N                           N",
		"NNNNNNNNNNNNNNNNNNNNNNNNNNNNN"
	};

	~Map() = default;

	Map(const String& string_for_load_map_texture, const String& string_for_load_arrows_texture);

	void Draw_arrows(RenderWindow& window);

	void Load_map(RenderWindow& window);

	Texture Return_map_texture();

	int Return_H();

	int Return_W();

	int Return_vector();

	Vector2i Return_burn();
private:
	const int H = 12;
	const int W = 30;

	int vector{ 0 };

	Vector2i burn;

	Texture map_texture;
	Sprite map_sprite;

	Texture arrows_texture;
	Sprite arrows_sprite;
};

#endif // !Map
