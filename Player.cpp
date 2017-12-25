#include "Player.h"
#include <SFML\Graphics.hpp>
using namespace sf;
//
//player::player()
//{
//	dx = 0;
//	dy = 0;
//	t_gor.loadFromFile("C:/3_semester/SFML_go/car_3_right.png");
//	s_gor.setTexture(t_gor);
//	t_ver.loadFromFile("C:/3_semester/SFML_go/car_3_up.png");
//	s_ver.setTexture(t_ver);
//
//	rec = FloatRect(50, 100, 33, 23);
//
//	s_gor.setPosition(rec.left, rec.top);
//}
//

//void player::update(float time)
//{
//	switch (vector)
//	{
//	case (1):
//	{
//		x += 0.1*time;
//		break;
//	}
//	case (2):
//	{
//		y -= 0.1*time;
//		break;
//	}
//	case (3):
//	{
//		x -= 0.1*time;
//		break;
//	}
//	case(4):
//	{
//		y += 0.1*time;
//		break;
//	}
//	default:
//		sp.setPosition(x, y);
//	}
//}

//void player::go(int vector, Time time)
//{
//	this->vector = vector;
//	switch (vector)
//	{
//	case (1):
//	{
//		sp.setTextureRect(IntRect(0, 34, 40, 22));
//		break;
//	}
//	case (2):
//	{
//		sp.setTextureRect(IntRect(0, 0, 22, 36));
//		break;
//	}
//	case (3):
//	{
//		sp.setTextureRect(IntRect(20, 0, 38, 24));
//		break;
//	}
//	case(4):
//	{
//		sp.setTextureRect(IntRect(56, 0, 22, 40));
//		break;
//	}
//	}
//}

Sprite player::Sp()
{
	return sp;
}

player::player(String s, int vector, float x, float y)
{
	this->x = x;
	this->y = y;
	this->vector = vector;
	heroimage.loadFromFile(s);
	tex.loadFromImage(heroimage);
	sp.setTexture(tex);
	sp.setPosition(x, y);
}
