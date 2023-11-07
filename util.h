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
//Ŀ������
void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

//Ŀ�� ��ǥ�� x,y�� �̵��ϴ� �Լ�
void gotoxy(int x, int y)
{
	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//� Ű�� ���������˷��ִ� �� �� 

//wasd�� ������ ���� ~
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
//ó�� ȭ���� �ʱ�ȭ
void init() {
	//���� ���ϱ�
	system("title MiRoGaMe");// �ܼ�â ���� ���ϱ�
	system("mode con:cols=120 lines=40"); //�ܼ�â ȭ�� ũ�� 
}