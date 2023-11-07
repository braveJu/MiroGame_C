#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include <conio.h>

enum { UP = 0, DOWN, LEFT, RIGHT, SUBMIT };

typedef struct {
	int x;
	int y;
}tPOINT;

typedef tPOINT* tPPOINT;


//main menu selection
#define GAMESTART 100
#define RANKING 101 
#define EXIT 102

//difficulty
#define EASY 501
#define NORMAL 502
#define HARD 503
//커서ㅡ이
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//커서 좌표를 x,y로 이동하는 함수
void gotoxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//어떤 키를 누르는지알려주는 함 수 

//wasd를 눌렀을 때만 ~
int KeyControl() {
	char pressed_key = _getch();

	if (pressed_key == 'w' || pressed_key == 'W') { // 1 
		return UP;
	}
	else if (pressed_key == 's' || pressed_key == 'S') { // 2
		return DOWN;
	}
	else if (pressed_key == 'a' || pressed_key == 'A') { //3
		return LEFT;
	}
	else if (pressed_key == 'd' || pressed_key == 'D') { // 3
		return RIGHT;
	}
	else if (pressed_key == ' ') { // 4
		return SUBMIT;
	}

}
//처음 화면을 초기화
void init() {
	//제목 정하기
	system("title MiRoGaMe");// 콘솔창 제목 정하기
	system("mode con:cols=120 lines=40"); //콘솔창 화면 크기 
}