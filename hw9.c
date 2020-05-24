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


	// 지도 생성
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


	// 이름 저장
	scanf_s("%s", name, 128);

	// 시작 위치 설정
	x = rand() % 100;
	y = rand() % 100;
	while (field[y][x] != '_') {
		x = rand() % 100;
		y = rand() % 100;
	}

	do {
		system("cls");
		// 정보 출력
		printf("'%s'님의 현재 위치 (%d, %d)\n\n", name, x, y);

		// 주변 지도 출력
		print_map(field, x, y);

		move = getch();
		switch (move) {
		case 'a': {
			if (x == 0 || field[y][x - 1] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else {
				x--;
			}
			break;
		}
		case 'd': {
			if (x == SIZE-1 || field[y][x + 1] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else {
				x++;
			}
			break;
		}
		case 'w': {
			if (y == 0 || field[y - 1][x] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else {
				y--;
			}
			break;
		}
		case 's': {
			if (y == SIZE - 1 || field[y + 1][x] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
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


// 주변 지도 출력
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