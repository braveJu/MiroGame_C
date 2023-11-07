#include "util.h"

void start() {
	tPOINT tPlayerPos;
	tPOINT tStartPos;
	tPOINT tEndPos;
	CursorView(0);

	game_start();

	int choice = main_menu_Selector();

	if (choice == GAMESTART) {
		clear();
		init();
		title_Draw();
		DrawDifficultyMenu();
		int diff = Difficulty_Selector();
		if (diff == EASY) {

			char strMaze[21][21] = { {'.'} };
			system("cls");
			//미로 설정
			SetMaze(strMaze, &tPlayerPos, &tStartPos, &tEndPos);

			while (1) {


				//미로 출력
				gotoxy(1, 1);
				Output(strMaze, &tPlayerPos);

				if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y) {
					clear();
					printf("도착했습니다.");
					break;
				}
				char clnput = _getch();



				if (clnput == 'q' || clnput == 'Q')
					break;

				MovePlayer(strMaze, &tPlayerPos, clnput);
			}
		}

	}
	else if (choice == RANKING) {
		clear();
		printf("This Is Ranking Page");
	}
	else if (choice == EXIT) {
		clear();
		return 0;
	}

}