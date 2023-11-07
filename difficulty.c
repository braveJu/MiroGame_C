#include "util.h"


int Difficulty_Selector() {

	int x = 52, y = 23;
	gotoxy(x, y);
	printf("▷ ");

	while (1) {
		int n = KeyControl();
		switch (n) {
		case UP:
			if (y > 23) {

				gotoxy(x, y);
				printf("  ");
				y -= 3;
				gotoxy(x, y);
				printf("▷ ");

			}
			break;

		case DOWN:
			if (y < 29) {

				gotoxy(x, y);
				printf("  ");
				y += 3;
				gotoxy(x, y);
				printf("▷  ");

			}
			break;

		case SUBMIT:
			if (y == 23) {
				return EASY;
			}
			else if (y == 26) {
				return NORMAL;
			}
			else if (y == 29) {
				return HARD;
			}
		}

	}

}


void DrawDifficultyMenu() {
	gotoxy(48, 20);
	printf("미로의 난이도를 선택해주세요.");
	gotoxy(58, 23);
	printf("EASY");
	gotoxy(58, 26);
	printf("NORMAL");
	gotoxy(58, 29);
	printf("HARD");
}