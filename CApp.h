#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"
#include "CSurface.h"

class CApp {
private:
	bool Running; // ���������� �������/�������� ����

	SDL_Surface* Surf_display;

	SDL_Surface* Surf_Test;
public:
	CApp();

	int OnExecute();

	bool OnInit(); // ��������� ������ � ������

	void OnEvent(SDL_Event* Event); // ���������� �������

	void OnLoop();

	void OnRender(); // ���������� ������������� ����

	void OnCleanup(); // �������� �����, ��� �� ������� (������� ������)
};

#endif