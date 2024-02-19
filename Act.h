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
			int Y = POS_MAX_Y - 3 * CELL - 1;
			int Yin = POS_MAX_Y - 3 * CELL - 1;
			int X_Sta;
		}Pos;
		struct {
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}In;
		struct {
			int le_up = 0;
			int ri_up = 0;
			int le_do = 0;
			int ri_do = 0;
		}Out;
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

	// マリオ Xcal
	Mar.Pos.X_Sta = Mar.Pos.X + abs(_Sta.Pos.X);

	// ジャンプ
	if (Fla.Rev == 0 && Fla.Jum == 1) {
		Cou = Cou + 1;
		T = T_K * ((double)Cou / 60);
		Mov.Y = (int)(pow(T, 2.0));
		for (int y = 1; y <= Mov.Y; y++) {
			Mar.Pos.Y--;

			// マリオ当たり判定
			Mar.Out.le_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y - 1];
			Mar.Out.ri_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y - 1];

			if (Mov.Y_MAX == Mar.Pos.Yin - Mar.Pos.Y ||
				Mar.Out.le_up != 0 ||
				Mar.Out.ri_up != 0) {
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

			// マリオ当たり判定
			Mar.Out.le_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y + CELL];
			Mar.Out.ri_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y + CELL];

			if (Mar.Out.le_do != 0 ||
				Mar.Out.ri_do != 0) {

				Mar.Pos.Y = Mar.Pos.Y - 1;
				Mar.Pos.Yin = Mar.Pos.Y;
				Fla.Jum = 0;
				Fla.Rev = 0;
				Mov.Y = 0;
				Cou = 0;
				break;
			}
		}
	}

	// マリオとブロックの当たり判定（Out）
	Mar.Out.le_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y - 1];
	Mar.Out.ri_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y - 1];
	Mar.Out.le_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y + CELL];
	Mar.Out.ri_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y + CELL];

	// マリオとブロックの当たり判定（In）
	Mar.In.le_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y - 1];
	Mar.In.ri_up = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y - 1];
	Mar.In.le_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta][Mar.Pos.Y + CELL];
	Mar.In.ri_do = Sta.Blo.Type_Exp[Mar.Pos.X_Sta + CELL - 1][Mar.Pos.Y + CELL];

	// ブロック右
	if (Mar.In.ri_up != 0 || Mar.In.ri_do != 0) {
		if (_Sta.Pos.X == 0 || _Sta.Pos.X == -POS_MAX_X + WIN_MAX_X) {
			Mar.Pos.X = Mar.Pos.X - Mov.X;
		}
		if (Mar.Pos.X == WIN_MAX_X / 2) {
			_Sta.Pos.X = _Sta.Pos.X + Mov.X;
		}
	}

	// ブロック左
	if (Mar.In.le_up != 0 || Mar.In.le_do != 0) {
		if (_Sta.Pos.X == 0 || _Sta.Pos.X == -POS_MAX_X + WIN_MAX_X) {
			Mar.Pos.X = Mar.Pos.X + Mov.X;
		}
		if (Mar.Pos.X == WIN_MAX_X / 2) {
			_Sta.Pos.X = _Sta.Pos.X - Mov.X;
		}
	}
}

void ACTION::Cha() {
	Sta.Out(&_Sta.Pos.X);
	DrawGraph(Mar.Pos.X, Mar.Pos.Y, Pic.Mar, TRUE);

	Fla.Xpl = 0;
	Fla.Xmi = 0;
}

