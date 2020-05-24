#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define SIZE 100

void print_map(char field[SIZE][SIZE], int x, int y);

int main(void) {
	char name[128];
	char field[SIZE][SIZE];
	char move;
	int x, y;


	// ���� ����
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {

			int rnd = rand() % 100;

			if (rnd < 80)
				field[i][j] = '_';
			else if (rnd < 95)
				field[i][j] = 'T';
			else if (rnd < 97)
				field[i][j] = '+';
			else if (rnd < 98)
				field[i][j] = '*';
			else if (rnd < 99)
				field[i][j] = '?';
			else
				field[i][j] = '#';

		}
	}


	// �̸� ����
	scanf_s("%s", name, 128);

	// ���� ��ġ ����
	x = rand() % 100;
	y = rand() % 100;
	while (field[y][x] != '_') {
		x = rand() % 100;
		y = rand() % 100;
	}

	do {
		system("cls");
		// ���� ���
		printf("'%s'���� ���� ��ġ (%d, %d)\n\n", name, x, y);

		// �ֺ� ���� ���
		print_map(field, x, y);

		move = getch();
		switch (move) {
		case 'a': {
			if (x == 0 || field[y][x - 1] == 'T') {
				printf("�� �������δ� �̵��� �� �����ϴ�.\n");
			}
			else {
				x--;
			}
			break;
		}
		case 'd': {
			if (x == SIZE-1 || field[y][x + 1] == 'T') {
				printf("�� �������δ� �̵��� �� �����ϴ�.\n");
			}
			else {
				x++;
			}
			break;
		}
		case 'w': {
			if (y == 0 || field[y - 1][x] == 'T') {
				printf("�� �������δ� �̵��� �� �����ϴ�.\n");
			}
			else {
				y--;
			}
			break;
		}
		case 's': {
			if (y == SIZE - 1 || field[y + 1][x] == 'T') {
				printf("�� �������δ� �̵��� �� �����ϴ�.\n");
			}
			else {
				y++;
			}
			break;
		}
		}

	} while (move != 'x');

	return 0;
}


// �ֺ� ���� ���
void print_map(char field[SIZE][SIZE], int x, int y) {

	for (int i = y < 10 ? 0 : y - 10; i <= (y < 90 ? y + 10 : SIZE - 1); i++) {
		for (int j = x < 10 ? 0 : x - 10; j <= (x < 90 ? x + 10 : SIZE - 1); j++) {
			if (y == i && x == j) {
				printf("o ");
				continue;
			}

			printf("%c ", field[i][j]);
		}
		printf("\n");
	}

}