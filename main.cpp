#define WIN_MAX_X 660
#define WIN_MAX_Y 450
#define WIN_POS_X 0
#define WIN_POS_Y 0

// Title scene switching
enum MEN {
	MEN_00_Title,
	MEN_01_Action
};

// Scene initial value substitution
int Sce = MEN::MEN_00_Title;

#include "DxLib.h"
#include "Sub.h"
#include "Pic.h"

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

	Col.Read();
	Fon.Read();
	Pic.Read();

	while (ScreenFlip == 0 &&
		ClearDrawScreen() == 0 &&
		ProcessMessage() == 0 &&
		Key.Read() == 0 &&
		Key.Key[KEY_INPUT_ESCAPE]) {
		switch (Sce) {
			case MEN::MEN_00_Title
				Tit.Out();
				break;
			case:MEN::MEN_01_Action
				Bat.Out();
				break;
		}
	}

	DrawPixel(320, 240, GetColor(255, 255, 255));
	WaitKey();
	DxLib_End();
	return EXIT_SUCCESS;
}

