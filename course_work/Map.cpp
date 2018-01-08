#include "Map.h"
#include "Arrow.h"
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace sf;

Map::Map(const String& string_for_load_map_texture, const String& string_for_load_arrows_texture) // <- Стандартный конструктор
{
	map_texture.loadFromFile(string_for_load_map_texture);
	map_sprite.setTexture(map_texture);

	arrows_texture.loadFromFile(string_for_load_arrows_texture);
	arrows_sprite.setTexture(arrows_texture);

	for (int i = 0; i < H; i++) // <- Проходимся по высоте (строки)
	{
		for (int j = 0; j < W - 1; j++) // <- Проходимся по ширине (стролбцы)
		{
			if (title_map_1[i][j] == 'B')
			{
				burn.x = j * 32;
				burn.y = i * 32;
				if (title_map_1[i][j + 1] == 'W')
					vector = 1;
				if (title_map_1[i + 1][j] == 'W')
					vector = 2;
				if (title_map_1[i][j - 1] == 'W')
					vector = 3;
				if (title_map_1[i - 1][j] == 'W')
					vector = 4;
			}
		}
	}

	title_map_ = new String*[H];
	for (int i = 0; i < H; i++)
	{
		title_map_[i] = new String[W];
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			title_map_[i][j] = title_map_1[i][j];
		}
	}
}

void Map::Draw_arrows(RenderWindow& window) // <- Загрузка стрелочек
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

void Map::Load_map(RenderWindow& window) // <- Загрузка карты
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W-1; j++)
		{
			if (title_map_1[i][j] == 'N')
			{
				map_sprite.setTextureRect(IntRect(194, 256, 32, 32));
			}
			else if ((title_map_1[i][j] == 'W') || (title_map_1[i][j] == 'B'))
			{
				map_sprite.setTextureRect(IntRect(295, 40, 32, 32));
			}
			else if (title_map_1[i][j] == 'X')
			{
				map_sprite.setTextureRect(IntRect(385, 255, 32, 35));
			}
			else if (title_map_1[i][j] == 'J')
			{
				map_sprite.setTextureRect(IntRect(545, 255, 32, 32));
			}
			else if (title_map_1[i][j] == 'P')
			{
				continue;
			}
			else if (title_map_1[i][j] == ' ')
			{
				map_sprite.setTextureRect(IntRect(0, 260, 32, 32));
			}
			map_sprite.setPosition((j * 32) + 64, (i * 32) + 128);
			window.draw(map_sprite);
		}
	}
}

Texture Map::Return_map_texture()
{
	return map_texture;
}

int Map::Return_H()
{
	return H;
}

int Map::Return_W()
{
	return W;
}

int Map::Return_vector()
{
	return vector;
}

Vector2i Map::Return_burn()
{
	return burn;
}
