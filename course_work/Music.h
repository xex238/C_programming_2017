#include <SFML\Audio.hpp>
using namespace sf;
#ifndef Musics_
#define Musics_

class Musics
{
public:
	Musics();

	~Musics() = default;

	void Replay();

	void Play_fon_music();

	void Play_game_over_music();

	void Fon_music_set_volume(const float& x);

	float Fon_music_get_volume();

	void Stop_fon_music();

	void Stop_game_over_music();

	void Game_over_music_set_volume(const float& x);

private:
	Music game_over_music;   // <- this is music for game over
	Music fon_music;   // <- this is fon music
};

#endif // !Music
