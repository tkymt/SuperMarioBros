#pragma once

#include "DxLib.h"

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
		Tit = LoadGraph(_T("Images/Title.bmp"));
		Bac = LoadGraph(_T("Images/Sky.bmp"));
		Bl1 = LoadGraph(_T("Images/Brick.bmp"));
		Bl2 = LoadGraph(_T("Images/Empty_block.bmp"));
		Bl3 = LoadGraph(_T("Images/Floor.bmp"));
		Bl4 = LoadGraph(_T("Images/Question_Block.bmp"));
		Ene = LoadGraph(_T("Images/Enemy_Goomba.bmp"));
		Mar = LoadGraph(_T("Images/Title.bmp"));
	}
}Pic;

