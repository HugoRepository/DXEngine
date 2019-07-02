#include "AppWindow.h"
#include "Engine.h"

AppWindow* app = NULL;

// ������ �޽��� ���ν���(�޽��� ó����).
LRESULT CALLBACK WindowProcessor(
	HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam
)
{
	if (app != NULL)
		return app->MessageProcessor(hwnd, msg, wParam, lParam);
	else
		return DefWindowProc(hwnd, msg, wParam, lParam);
}

AppWindow::AppWindow(HINSTANCE hinstance)
{
	hwnd = NULL;
	this->hintance = hinstance;
	screenWidth = 1600;
	screenHeight = 900;
	applicationName = TEXT("Engine00 - Window Setup");
	windowStyle = WS_OVERLAPPEDWINDOW;
	app = this;
}

AppWindow::~AppWindow()
{
}

int AppWindow::Run(Engine * engine)
{	
	MSG msg;						// �޽��� ����
	ZeroMemory(&msg, sizeof(MSG));	// �޸� �ʱ�ȭ.

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			engine->Update();
			engine->Render();
		}
	}

	return 0;
}

bool AppWindow::InitializeWindow()
{
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));

	// â ����ü �� ����.

	return true;
}

LRESULT AppWindow::MessageProcessor(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return LRESULT();
}
