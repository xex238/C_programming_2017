#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"
#include "CSurface.h"

class CApp {
private:
	bool Running; // Переменная запуска/окнчания игры

	SDL_Surface* Surf_display;

	SDL_Surface* Surf_Test;
public:
	CApp();

	int OnExecute();

	bool OnInit(); // Загружает данные в память

	void OnEvent(SDL_Event* Event); // Обработчик событий

	void OnLoop();

	void OnRender(); // Собственно отрисовывание сцен

	void OnCleanup(); // Удаление всего, что мы создали (очистка памяти)
};

#endif