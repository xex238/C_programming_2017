#ifndef Map
#define Map
#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>

class Map_
{
	const int H = 12;
	const int W = 30;

	String title_map[12] =
	{
		"NNNNNNNNNNNNNNNNNNNNNNNNNNNNN",
		"N                           N",
		"N       JWWWWWWWWJ          N",
		"N       W        W          N",
		"NWWWWWWWJ        W          N",
		"N                W          N",
		"N                W          N",
		"N                JWWWWWX    N",
		"N                           N",
		"N                           N",
		"N                           N",
		"NNNNNNNNNNNNNNNNNNNNNNNNNNNNN"
	};
public:
	Image map_image;
	Texture map_texture;
	Sprite map_sprite;

	Map_(String s);

	void Load_map(RenderWindow& window);
};

#endif // !Map
