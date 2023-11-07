#include "util.h"

void SetMaze(char Maze[21][21], tPPOINT pPlayerPos, tPPOINT pStartPos, tPPOINT pEndPos);
void Output(char Maze[21][21], tPPOINT pPlayerPos);
void MoveUp(char Maze[21][21], tPPOINT pPlayerPos);
void MoveDown(char Maze[21][21], tPPOINT pPlayerPos);
void MoveRight(char Maze[21][21], tPPOINT pPlayerPos);
void MoveLeft(char Maze[21][21], tPPOINT pPlayerPos);
void MovePlayer(char Maze[21][21], tPPOINT pPlayerPos, char clnput);
void MoveMenu();


void MoveMenu() {
	gotoxy(42, 1);
	printf("□□□□□□□□\n");
	gotoxy(42, 2);
	printf("□            □\n");
	gotoxy(42, 3);
	printf("□  w: 위     □\n");
	gotoxy(42, 4);
	printf("□  a: 왼쪽   □ \n");
	gotoxy(42, 5);
	printf("□  s: 아래   □ \n");
	gotoxy(42, 6);
	printf("□  d: 오른쪽 □\n");
	gotoxy(42, 7);
	printf("□  q: 종료   □\n");
	gotoxy(42, 8);
	printf("□            □\n");
	gotoxy(42, 9);
	printf("□□□□□□□□\n");

}




void MoveUp(char Maze[21][21], tPPOINT pPlayerPos) {

	if (pPlayerPos->y - 1 >= 0) {

		//벽인지 체크
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0') {
			--pPlayerPos->y;
		}
	}

}


void MoveDown(char Maze[21][21], tPPOINT pPlayerPos) {

	if (pPlayerPos->y + 1 < 20) {

		//벽인지 체크
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0') {
			++pPlayerPos->y;
		}
	}

}


void MoveRight(char Maze[21][21], tPPOINT pPlayerPos) {

	if (pPlayerPos->x + 1 < 20) {

		//벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0') {
			++pPlayerPos->x;
		}
	}

}


void MoveLeft(char Maze[21][21], tPPOINT pPlayerPos) {

	if (pPlayerPos->x - 1 >= 0) {

		//벽인지 체크
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0') {
			--pPlayerPos->x;
		}
	}

}


void MovePlayer(char Maze[21][21], tPPOINT pPlayerPos, char clnput) {

	switch (clnput) {

	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}

}


void CursorView(char show)
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}


void Output(char Maze[21][21], tPPOINT pPlayerPos) {



	for (int i = 0; i < 20; ++i) {

		for (int j = 0; j < 20; ++j) {

			if (pPlayerPos->x == j && pPlayerPos->y == i)
				printf("☆");

			else if (Maze[i][j] == '0')
				printf("■");

			else if (Maze[i][j] == '1')
				printf("  ");

			else if (Maze[i][j] == '2')
				printf("★");

			else if (Maze[i][j] == '3')
				printf("◎");
		}
		printf("\n");
	}
	MoveMenu();
}

/*
void SetMaze(char Maze[21][21], tPPOINT pPlayerPos, tPPOINT pStartPos, tPPOINT pEndPos) {

	FILE* pFile = NULL;

	fopen_s(&pFile, "Maze1.txt", "rt");

	if (pFile) {

		//미로의 세로줄 수만큼 반복.
		for (int i = 0; i < 20; i++) {
			fread(Maze[i], 1, 21, pFile);

			//현재 줄의 미로를 검사하여 시작점 혹은 도착점이 있는지를 판단한다.
			for (int j = 0; j < 20; j++) {
				//시작점일 경우
				if (Maze[i][j] == '2') {
					pStartPos->x = j;
					pStartPos->y = i;

					*pPlayerPos = *pStartPos;

				}
				else if (Maze[i][j] == '3') {
					pEndPos->x = j;
					pEndPos->y = i;
				}
			}

		}

		fclose(pFile);
	}

}*/

void SetMaze(char Maze[21][21], tPPOINT pPlayerPos, tPPOINT pStartPos, tPPOINT pEndPos) {

	pStartPos->x = 1;
	pStartPos->y = 1;

	pEndPos->x = 18;
	pEndPos->y = 18;

	*pPlayerPos = *pStartPos;
	strcpy(Maze[0], "00000000000000000000");
	strcpy(Maze[1], "02111111111111111110");
	strcpy(Maze[2], "01001000001000000010");
	strcpy(Maze[3], "01111100011111111010");
	strcpy(Maze[4], "00000100000000000010");
	strcpy(Maze[5], "01111111111111111110");
	strcpy(Maze[6], "01000100000100000010");
	strcpy(Maze[7], "01000100000100000010");
	strcpy(Maze[8], "01111100000100000010");
	strcpy(Maze[9], "01000000000111111110");
	strcpy(Maze[10], "01000111110000000010");
	strcpy(Maze[11], "01000100010000000110");
	strcpy(Maze[12], "01111100010000000100");
	strcpy(Maze[13], "00000000011111111100");
	strcpy(Maze[14], "00000000000000100000");
	strcpy(Maze[15], "01111001111111100000");
	strcpy(Maze[16], "01000001000000100000");
	strcpy(Maze[17], "01000001000000100000");
	strcpy(Maze[18], "01111111000000111130");
	strcpy(Maze[19], "00000000000000000000");

}
