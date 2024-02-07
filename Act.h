#pragma once

#include "Sta.h"
#include "Pic.h"
#include <math.h>

class ACTION {
public:
	void Out() {
		Cal();
		Cha();
	}
private:
	struct {
		struct {
			int X = 0;
			int Y = POS_MAX_Y - 3 * CELL;
			int Yin = POS_MAX_Y - 3 * CELL;
		}Pos;
	}Mar;

	struct {
		const int X = 1;
		int Y = 0;
		const int Y_MAX = CELL * 4;
	}Mov;

	struct {
		struct {
			int X;
			int Y;
		}Pos;
	}_Sta;

	struct {
		bool Xpl = 0;
		bool Xmi = 0;
		bool Jum = 0;
		bool Rev = 0;
	}Fla;

	int Cou = 0;
	double T = 0;
	double T_K = 10.0;

	void Cal();
	void Cha();
};

ACTION Act;

void ACTION::Cal() {
	if (Key.Key[KEY_INPUT_D] != 0) {
		Fla.Xpl = 1;
	}
	else if (Key.Key[KEY_INPUT_A] != 0) {
		Fla.Xmi = 1;
	}
	if (Key.Key[KEY_INPUT_W]) {
		Fla.Jum = 1;
		Mar.Pos.Yin = Mar.Pos.Y;
	}
	if (Fla.Xpl == 1) {
		if (_Sta.Pos.X == 0 || _Sta.Pos.X == -POS_MAX_X + WIN_MAX_X) {
			Mar.Pos.X = Mar.Pos.X + Mov.X;
		}
		if (Mar.Pos.X == WIN_MAX_X / 2) {
			_Sta.Pos.X = _Sta.Pos.X - Mov.X;
		}
	}
	else if (Fla.Xmi == 1) {
		if (_Sta.Pos.X == 0 || _Sta.Pos.X == -POS_MAX_X + WIN_MAX_X) {
			Mar.Pos.X = Mar.Pos.X - Mov.X;
		}
		if (Mar.Pos.X == WIN_MAX_X / 2) {
			_Sta.Pos.X = _Sta.Pos.X + Mov.X;
		}
	}

	// ƒWƒƒƒ“ƒv
	if (Fla.Rev == 0 && Fla.Jum == 1) {
		Cou = Cou + 1;
		T = T_K * ((double)Cou / 60);
		Mov.Y = (int)(pow(T, 2.0));
		for (int y = 1; y <= Mov.Y; y++) {
			Mar.Pos.Y--;
			if (Mov.Y_MAX == Mar.Pos.Yin - Mar.Pos.Y) {
				Fla.Rev = 1;
				Cou = 0;
				break;
			}
		}
	}
	else if (Fla.Rev == 1 && Fla.Jum == 1) {
		Cou++;
		T = T_K * ((double)Cou / 60);
		Mov.Y = (int)(pow(T, 2.0));
		for (int y = 0; y <= Mov.Y; y++) {
			Mar.Pos.Y++;
			if (Mar.Pos.Y == POS_MAX_Y - 3 * CELL) {
				Mar.Pos.Y = POS_MAX_Y - 3 * CELL;
				Mar.Pos.Yin = POS_MAX_Y - 3 * CELL;
				Fla.Jum = 0;
				Fla.Rev = 0;
				Mov.Y = 0;
				Cou = 0;
				break;
			}
		}
	}
}

void ACTION::Cha() {
	Sta.Out(&_Sta.Pos.X);
	DrawGraph(Mar.Pos.X, Mar.Pos.Y, Pic.Mar, TRUE);

	Fla.Xpl = 0;
	Fla.Xmi = 0;
}

