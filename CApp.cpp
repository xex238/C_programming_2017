#include "CApp.h"

CApp::CApp() // Метод запуска игры
{
	Surf_Test = NULL;
	Surf_display = NULL;
	Running = true;
}

int CApp::OnExecute() // Главное тело игры
{
	if (OnInit() == false) // Если что-то не прогрузилось, аварийно заканчиваем игру
	{
		return -1;
	}

	SDL_Event Event;

	while (Running)
	{
		while (SDL_WaitEvent(&Event)) // Ожидание и считывание события
		{
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup(); // Очистка ресурсов памяти

	return 0;
}

int main(int argc, char* argv[]) // метод main изменён
{
	CApp theApp; // Даём добро на запуск игры

	return theApp.OnExecute(); // Запускаем игру
}