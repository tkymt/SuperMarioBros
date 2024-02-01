#pragma once

#include "DxLib.h"
#include "tchar.h"

class {
public:
	int Tit;
	int Bac;
	int Bl1;
	int Bl2;
	int Bl3;
	int Bl4;
	int Ene;
	int Mar;

	void Read() {
		Tit = LoadGraph(_T("Images/x2/Title.bmp"));
		Bac = LoadGraph(_T("Images/x2/Sky.bmp"));
		Bl1 = LoadGraph(_T("Images/x2/Brick.bmp"));
		Bl2 = LoadGraph(_T("Images/x2/Empty_block.bmp"));
		Bl3 = LoadGraph(_T("Images/x2/Floor.bmp"));
		Bl4 = LoadGraph(_T("Images/x2/Question_Block.bmp"));
		Ene = LoadGraph(_T("Images/x2/Enemy_Goomba.bmp"));
		Mar = LoadGraph(_T("Images/x2/Mario_Stand.bmp"));
	}
}Pic;

