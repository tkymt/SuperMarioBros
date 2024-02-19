#pragma once

#include <cstdio>

class STAGE{
public:
	struct
	{
		int Type[STAGE_MAX_X][STAGE_MAX_Y];
		int Type_Exp[POS_MAX_X][POS_MAX_Y];
	}Blo;

	void Read() {
		FILE* fp_stage_1_1;
		errno_t error;
		error = fopen_s(&fp_stage_1_1, "Stage/1_1.txt", "r");

		std::FILE* fp_block_exp;
		errno_t error_block_exp;
		fopen_s(&fp_block_exp, "Stage/block_exp.txt", "w");

		if (error != 0) return;
		// int i = 0;
		for (int y = 0; y < STAGE_MAX_Y; y++) {
			for (int x = 0; x < STAGE_MAX_X; x++) {
				fscanf_s(fp_stage_1_1, "%d",&Blo.Type[x][y]);

				/*
				if (Blo.Type[x][y] == IMAGE::IMAGE_07_Eenemy) {
					Enemy.Pos.x = x * CELL;
					Enemy.Pos.y = y * CELL;
					i++
				}
				*/
			}
		}

		for (int y = 0; y < STAGE_MAX_Y; y++) {
			for (int x = 0; x < STAGE_MAX_X; x++) {
				int ins = Blo.Type[x][y];
				std::fprintf(fp_block_exp, "(%d,%d)\n",x,y);
				for (int ye = 0; ye < CELL; ye++) {
					for (int xe = 0; xe < CELL; xe++) {
						Blo.Type_Exp[x * CELL + xe][y * CELL + ye] = ins;
						std::fprintf(fp_block_exp, "%d ", Blo.Type_Exp[x * CELL + xe][y * CELL + xe]);
					}
					std::fprintf(fp_block_exp, "\n");
				}
				
			}
		}

		fclose(fp_stage_1_1);
		std::fclose(fp_block_exp);
	}

	void Out(int* PosX) {
		int pic = 0;
		// Block‚Ì•`‰æ
		for (int y = 0; y < STAGE_MAX_Y; y++) {
			for (int x = 0; x < STAGE_MAX_X; x++) {
				switch (Blo.Type[x][y]) {
				case 0:
					pic = Pic.Bac;
					break;
				case 1:
					pic = Pic.Bl1;
					break;
				case 2:
					pic = Pic.Bl2;
					break;
				case 3:
					pic = Pic.Bl3;
					break;
				case 4:
					pic = Pic.Bl4;
					break;
				case 5:
					pic = Pic.Ene;
					break;
				}
				DrawGraph(CELL * x + *PosX, CELL * y, pic, TRUE);
			}
		}
	}
};

STAGE Sta;

