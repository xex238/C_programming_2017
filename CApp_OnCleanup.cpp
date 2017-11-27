#include "CApp.h"

void CApp::OnCleanup()
{
	SDL_FreeSurface(Surf_Test);
	SDL_FreeSurface(Surf_display);
	SDL_Quit();
}