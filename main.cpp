#define WIN_MAX_X 660
#define WIN_MAX_Y 450
#define WIN_POS_X 0
#define WIN_POS_Y 0

#define POS_MAX_X 6600
#define POS_MAX_Y 4500
#define CELL 16
#define STAGE_MAX_X 6600/16
#define STAGE_MAX_Y 400/16

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
#include "Tit.h"
#include "Sta.h"

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
	Sta.Read();

	while (ScreenFlip() == 0 &&
		ClearDrawScreen() == 0 &&
		ProcessMessage() == 0 &&
		Key.Read() == 0 &&
		Key.Key[KEY_INPUT_ESCAPE] == 0) {
		switch (Sce) {
		case MEN::MEN_00_Title:
				Tit.Out();
				break;
		case MEN::MEN_01_Action:
				Sta.Out();
				break;
		}
	}

	DxLib_End();
	return EXIT_SUCCESS;
}

