#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

#define SIZE 100

void print_map(char field[SIZE][SIZE], int x, int y);

struct explorer {
	char name[128];
	int score;
	int gold;
	int food;
	int health;
	float luck;
};

int main(void) {
	struct explorer e1;
	char field[SIZE][SIZE];	// 지도
	char move;	// 이동(aswd)
	int x, y;	// 현재 좌표


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


	// 이름 저장 및 구조체 초기화
	printf("플레이어의 이름을 입력하세요: ");
	scanf_s("%s", e1.name, 128);
	e1.score = 0;
	e1.gold = 0;
	e1.food = 50;
	e1.health = 100;
	e1.luck = 0.01;

	// 시작 위치 설정
	x = rand() % 100;
	y = rand() % 100;
	while (field[y][x] != '_') {
		x = rand() % 100;
		y = rand() % 100;
	}

	// 이동
	do {
		system("cls");
		// 정보 출력
		printf("'%s'님의 현재 위치 (%d, %d)\n", e1.name, x, y);
		printf("점수: %4d\t돈: %4d\n식량: %4d\t체력:%4d\n운: %6.2f\n\n", e1.score, e1.gold, e1.food, e1.health, e1.luck);

		// 주변 지도 출력
		print_map(field, x, y);

		move = getch();
		switch (move) {
		case 'a': {
			if (x == 0) {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else if (field[y][x - 1] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
				e1.health -= 10;
			}
			else {
				x--;
			}
			break;
		}
		case 'd': {
			if (x == SIZE - 1) {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else if (field[y][x + 1] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
				e1.health -= 10;
			}
			else {
				x++;
			}
			break;
		}
		case 'w': {
			if (y == 0) {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else if (field[y - 1][x] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
				e1.health -= 10;
			}
			else {
				y--;
			}
			break;
		}
		case 's': {
			if (y == SIZE - 1) {
				printf("그 방향으로는 이동할 수 없습니다.\n");
			}
			else if (field[y + 1][x] == 'T') {
				printf("그 방향으로는 이동할 수 없습니다.\n");
				e1.health -= 10;
			}
			else {
				y++;
			}
			break;
		}
		default:
			continue;
		}

		e1.food--;

		// 금 or 다이아몬드 -> 돈 획득, 지형 변경, 점수
		if (field[y][x] == '+') {
			e1.gold += 10;
			field[y][x] = '_';
			e1.score += 5;
		}
		else if (field[y][x] == '*') {
			e1.gold += 50;
			field[y][x] = '_';
			e1.score += 20;
		}
		else {
			e1.score++;
		}

	} while (move != 'x' && e1.food > 0 && e1.health > 0);

	system("cls");
	printf("%s님의 최종 점수는 %d점입니다.\n\n", e1.name, e1.score + e1.gold * 2);


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