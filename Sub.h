#pragma once

#include "DxLib.h"

// Colorを取得する関数群
class {
public:
	int Whi;
	int Bla;
	int Red;
	int Gre;
	int Blu;

	void Read() {
		Whi = GetColor(255, 255, 255);
		Bla = GetColor(  0,   0,   0);
		Red = GetColor(255,   0,   0);
		Gre = GetColor(  0, 255,   0);
		Blu = GetColor(  0,   0, 255);
	}

}Col;

// 文字のフォントを取得する関数群
class {
public:
	int c[50 + 1];
	void Read() {
		for (int i = 0; i < 50 + 1; i++) {
			c[i] = CreateFontToHandle(_T("MSゴシック"), i, 6, DX_FONTTYPE_NORMAL);
		}
	}
}Fon;

class {
public:
	// Keyの押下時間情報
	int Key[256];
	// Key関数
	void Read() {
		char allKey[256];
		GetHitKeyStateAll(allKey);
		for (int i = 0; i < 256; i++) {
			if (allKey[i] == 1) {
				Key[i] = Key[i] + 1;
			}
			else if (allKey[i] = 0) {
				Key[i] = 0;
			}
		}
	}
}Key;

