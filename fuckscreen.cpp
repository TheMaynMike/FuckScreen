#include <windows.h>
#include <time.h>
#include <iostream>

HWND DESK = GetDesktopWindow(); HDC hdc = GetDC(DESK);

int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);

	int ScrW = GetSystemMetrics(SM_CXSCREEN);
	int ScrH = GetSystemMetrics(SM_CYSCREEN);

	while (true)
	{
		for (int i = 0;; i++, i %= 5)
		{
			//if (!i)RedrawWindow(0, 0, 0, 133);
			HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
			for (int c = 0; c < rand() % 30; c++)
			{
				int x = rand() % ScrW, y = rand() % ScrH, sx = rand() % 21 - 10, sy = rand() % 21 - 10; HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
				BitBlt(hdc, x, y, 369, 369, hdc, x + sx, y + sy, SRCCOPY);
			}
			SelectObject(hdc, brush);
			PatBlt(hdc, 0, 0, ScrW, ScrH, PATINVERT);
		}
	}

	return 0;
}
