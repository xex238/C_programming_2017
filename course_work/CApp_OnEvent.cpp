#include "CApp.h" // Обработка событий

void CApp::OnEvent(SDL_Event* Event) 
{
	if (Event->type == SDL_QUIT)
	{
		Running = false;
	}
}
