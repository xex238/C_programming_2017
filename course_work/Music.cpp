#include "Music.h"

Musics::Musics()
{
	game_over_music.openFromFile("music/game_over.ogg");
	game_over_music.setVolume(100);
	fon_music.openFromFile("music/fon_music.ogg");
	fon_music.setVolume(100);
}

void Musics::Replay() // <- Включение повторения музыки
{
	fon_music.setLoop(true);
}
void Musics::Play_fon_music()
{
	fon_music.play();
}
void Musics::Play_game_over_music()
{
	game_over_music.play();
}
void Musics::Stop_fon_music()
{
	fon_music.stop();
}
void Musics::Stop_game_over_music()
{
	game_over_music.stop();
}
void Musics::Fon_music_set_volume(const float& x)
{
	fon_music.setVolume(x);
}
void Musics::Game_over_music_set_volume(const float& x)
{
	game_over_music.setVolume(x);
}

float Musics::Fon_music_get_volume()
{
	return fon_music.getVolume();
}
