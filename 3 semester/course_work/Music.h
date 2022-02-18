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
	void Stop_fon_music();
	void Stop_game_over_music();
	void Fon_music_set_volume(const float& x);
	void Game_over_music_set_volume(const float& x);

	float Fon_music_get_volume();
private:
	Music game_over_music;   // <- Это музыка будет играть при победе
	Music fon_music;   // <- Это фоновая музыка
};

#endif // !Music
