/* les01 */
#include "windows.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG msg;

	// 1 注册窗口类
	WNDCLASSEX ws;

	ws.cbSize = sizeof(WNDCLASSEX);
	ws.style = 0; // 窗口样式
	ws.lpfnWndProc = WndProc;
	ws.cbClsExtra = 0;
	ws.cbWndExtra = 0;
	ws.hInstance = hThisInst;
	ws.hIcon = LoadIcon(NULL, IDI_HAND);
	ws.hIconSm = LoadIcon(NULL, IDI_HAND);
	ws.hCursor = LoadCursor(NULL, IDC_CROSS);
	ws.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	ws.lpszMenuName = NULL;
	ws.lpszClassName = L"MyWndClass";

	RegisterClassEx(&ws);

	// 2 创建窗口
	hWnd = CreateWindow(L"MyWndClass", L"My First Win32 Program",
		WS_OVERLAPPEDWINDOW, 100, 200, 400, 300, NULL, NULL, hThisInst, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	// 3 启动消息循环
	while(GetMessage(&msg, NULL, 0, 0))
	{
	    TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch(message)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, L"你按下了鼠标左键！",
			L"Demo MessageBox", MB_OK);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);    // 发送WM_QUIT消息
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
}
