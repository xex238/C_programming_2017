#include <SFML/Graphics.hpp>
using namespace sf;
#include <string>
#ifndef Player
#define Player

class player
{
public:
	//float dx, dy;
	float x, y;
	Image heroimage;
	Texture tex;
	Sprite sp;
	int vector; // 1 - right, 2 - down, 3 - left, 4 - up

	player() = default;

	player(String s, int vector, float x, float y);

	~player() = default;

	void update(float time);

	void go(int vector, Time time);

	Sprite Sp();
};

#endif // !Player
