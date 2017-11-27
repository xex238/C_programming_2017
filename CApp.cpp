#include "CApp.h"

CApp::CApp() // ����� ������� ����
{
	Surf_Test = NULL;
	Surf_display = NULL;
	Running = true;
}

int CApp::OnExecute() // ������� ���� ����
{
	if (OnInit() == false) // ���� ���-�� �� ������������, �������� ����������� ����
	{
		return -1;
	}

	SDL_Event Event;

	while (Running)
	{
		while (SDL_WaitEvent(&Event)) // �������� � ���������� �������
		{
			OnEvent(&Event);
		}

		OnLoop();
		OnRender();
	}

	OnCleanup(); // ������� �������� ������

	return 0;
}

int main(int argc, char* argv[]) // ����� main ������
{
	CApp theApp; // ��� ����� �� ������ ����

	return theApp.OnExecute(); // ��������� ����
}