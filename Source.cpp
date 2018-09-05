#include<windows.h>
#include<tchar.h>

LRESULT CALLBACK WINAPI WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) 
{
	HWND hwnd;
	MSG msg;
	WNDCLASSEX w;

	memset(&w, 0, sizeof(WNDCLASS));
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.lpfnWndProc = WndProc;
	w.hInstance = hInstance;
	w.hbrBackground = (HBRUSH)(WHITE_BRUSH);;
	w.lpszClassName = "My Class";

	if (!RegisterClassEx(&w)) return FALSE;

	hwnd = CreateWindow("My Class", "User's Windows",
		WS_OVERLAPPEDWINDOW, 500, 300, 500, 300, NULL,
		NULL, hInstance, NULL);

	if (!hwnd) return FALSE;

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WINAPI WndProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) 
{
	switch (Message) 
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, Message, wparam, lparam);

	}
	return 0;
}