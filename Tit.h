#pragma once

#include "DxLib.h"
#include "tchar.h"
#include "Pic.h"

class {
public:
	void Out() {
		DrawGraph(0, 0, Pic.Tit, TRUE);
		DrawFormatStringToHandle(150, 300, Col.Bla, Fon.c[30], _T("Press Enter Key."));
		if (Key.Key[KEY_INPUT_NUMPADENTER] == 1) {
			// Music Play
			Sce = MEN::MEN_01_Action;
		}
	}
}Tit;

