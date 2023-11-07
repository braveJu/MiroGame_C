#include "util.h"

//제목 아래 메뉴를 그리는 함수
void menu_Draw() {
	gotoxy(49, 20);
	printf("▷   게임 시작");

	gotoxy(51, 23);
	printf("    랭   킹");

	gotoxy(51, 26);
	printf("    나 가 기");
}

//제목을 그려주는 함수 -- 메인화면
void title_Draw() {
	printf("\n\n\n\n\n\n\n");
	printf("\t\t\t      #         #       #######        #######          ######  \n");
	printf("\t\t\t      # #     # #          #           #      #        #      # \n");
	printf("\t\t\t      #  #   #  #          #           #      #        #      # \n");
	printf("\t\t\t      #   # #   #          #           #######         #      # \n");
	printf("\t\t\t      #    #    #          #           #     #         #      # \n");
	printf("\t\t\t      #         #          #           #      #        #      # \n");
	printf("\t\t\t      #         #       #######        #       #        ######  \n");
}

int main_menu_Selector() {
	int x = 49, y = 20;
	gotoxy(x, y); // 메뉴 옆쪽으로 이동/

	//메뉴를 고를때까지 계속반복한다.
	while (1) {
		int n = KeyControl();

		switch (n) {
		case UP:
			if (y > 20) {
				gotoxy(x, y);
				printf("   ");
				gotoxy(x, y - 3);
				y -= 3;
				printf("▷");
			}
			break;

		case DOWN:
			if (y < 26) {
				gotoxy(x, y);
				printf("   ");
				gotoxy(x, y + 3);
				y += 3;
				printf("▷");
			}
			break;
		case SUBMIT:
			if (y == 20) {
				return GAMESTART;
			}
			else if (y == 23) {
				return RANKING;
			}
			else if (y == 26) {
				return EXIT;
			}
		}
	}
}

void game_start() {
	init();
	title_Draw();
	menu_Draw();

}

//처음 배경화면을 꾸며주는 함수
void init_background() {
	//titleDraw 게임 이름 그리기
	title_Draw();
	menu_Draw();

}
