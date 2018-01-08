#include "Music.h"
#include <SFML\Audio.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Musics::Musics(const String& s_SoundBuffer, const String& s_Music) // <- Стандартный конструктор
{
	game_over_music.openFromFile(s_SoundBuffer);
	game_over_music.setVolume(100);
	fon_music.openFromFile(s_Music);
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

void Musics::Fon_music_set_volume(const float & x)
{
	fon_music.setVolume(x);
}

float Musics::Fon_music_get_volume()
{
	return fon_music.getVolume();
}

void Musics::Stop_fon_music()
{
	fon_music.stop();
}

void Musics::Stop_game_over_music()
{
	game_over_music.stop();
}

void Musics::Game_over_music_set_volume(const float & x)
{
	game_over_music.setVolume(x);
}
