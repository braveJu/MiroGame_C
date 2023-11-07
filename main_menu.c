#include "util.h"

//���� �Ʒ� �޴��� �׸��� �Լ�
void menu_Draw() {
	gotoxy(49, 20);
	printf("��   ���� ����");

	gotoxy(51, 23);
	printf("    ��   ŷ");

	gotoxy(51, 26);
	printf("    �� �� ��");
}

//������ �׷��ִ� �Լ� -- ����ȭ��
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
	gotoxy(x, y); // �޴� �������� �̵�/

	//�޴��� �������� ��ӹݺ��Ѵ�.
	while (1) {
		int n = KeyControl();

		switch (n) {
		case UP:
			if (y > 20) {
				gotoxy(x, y);
				printf("   ");
				gotoxy(x, y - 3);
				y -= 3;
				printf("��");
			}
			break;

		case DOWN:
			if (y < 26) {
				gotoxy(x, y);
				printf("   ");
				gotoxy(x, y + 3);
				y += 3;
				printf("��");
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

//ó�� ���ȭ���� �ٸ��ִ� �Լ�
void init_background() {
	//titleDraw ���� �̸� �׸���
	title_Draw();
	menu_Draw();

}
