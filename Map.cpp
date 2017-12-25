#include "Map.h"
#include <SFML\Graphics.hpp>
using namespace sf;

Map_::Map_(String s)
{
	map_image.loadFromFile(s);
	map_texture.loadFromImage(map_image);
	map_sprite.setTexture(map_texture);
}

void Map_::Load_map(RenderWindow& window)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 29; j++)
		{
			if (title_map[i][j] == 'N')
			{
				map_sprite.setTextureRect(IntRect(194, 256, 32, 32));
			}
			else if (title_map[i][j] == 'W')
			{
				map_sprite.setTextureRect(IntRect(295, 40, 32, 32));
			}
			else if (title_map[i][j] == 'X')
			{
				map_sprite.setTextureRect(IntRect(385, 255, 30, 35));
			}
			else if (title_map[i][j] == 'J')
			{
				map_sprite.setTextureRect(IntRect(545, 255, 30, 30));
			}
			else if (title_map[i][j] = ' ')
			{
				map_sprite.setTextureRect(IntRect(0, 260, 32, 32));
			}
			map_sprite.setPosition(j * 32, i * 32);
			window.draw(map_sprite);
		}
	}
}
