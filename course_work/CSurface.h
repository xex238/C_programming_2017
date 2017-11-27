#ifndef _CSURFACE_H_
#define _CSURFACE_H_

#include "SDL.h"

class CSurface // Создание текстур
{
public:
	CSurface();

	static SDL_Surface* OnLoad(char* File); // Загрузка

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y); // Рисование целой картинки

	static bool OnDraw(SDL_Surface* Surf_Dest, SDL_Surface* Surf_Src, int X, int Y, int X2, int Y2, int W, int H); // Рисование части картинки
};

#endif
