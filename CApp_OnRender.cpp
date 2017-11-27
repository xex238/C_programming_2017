#include "CApp.h" 

void CApp::OnRender()
{
	CSurface::OnDraw(Surf_display, Surf_Test, 0, 0);

	SDL_Flip(Surf_display);
}