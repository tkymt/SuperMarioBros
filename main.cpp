#define WIN_MAX_X 660
#define WIN_MAX_Y 450
#define WIN_POS_X 0
#define WIN_POS_Y 0

#include "DxLib.h"

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	ChangeWindowMode(TRUE);
	if (DxLib_Init() == -1) {
		return EXIT_FAILURE;
	}

	// Windowの設定
	SetWindowInitPosition(WIN_POS_X, WIN_POS_Y); // ウインドウのポジション
	SetWindowText(_T("SPERMARIOBROS"));
	SetGraphMode(WIN_MAX_X, WIN_MAX_Y, 32);
	SetBackgroundColor(255, 255, 255);
	SetDrawScreen(DX_SCREEN_BACK);

	DrawPixel(320, 240, GetColor(255, 255, 255));
	WaitKey();
	DxLib_End();
	return EXIT_SUCCESS;
}

