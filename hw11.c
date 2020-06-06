#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <float.h>
#include <math.h>

#define SIZE 100

void print_map(char field[SIZE][SIZE], int x, int y);
void village(struct explorer e1, int x, int y);
void ruin(struct explorer e1, int x, int y);

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

	e1.luck = 0.08;

	// 이동
	do {
		system("cls");
		// 정보 출력
		printf("'%s'님의 현재 위치 (%d, %d)\n", e1.name, x, y);
		printf("점수: %4d\t돈: %4d\n식량: %4d\t체력:%4d\n운: %6.2f\n\n", e1.score, e1.gold, e1.food, e1.health, e1.luck);

		// 주변 지도 출력
		print_map(field, x, y);
		if (field[y][x] == '#') {
			char key = getch();
			if (key == 'e') {
				village(e1, x, y);
			}
		}
		else if (field[y][x] == '?') {
			char key = getch();
			if (key == 'e') {
				if(fabsf(e1.luck-0.08f)<=FLT_EPSILON){
					ruin(e1, x, y);
					field[y][x] = '!';
				}
				else {
					e1.health -= 30;
					printf("유적에 입장하실 수 없습니다.");
				}
			}
		}

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


// 마을 메뉴
void village(struct explorer e1, int x, int y) {
	char menu;

	do {
		system("cls");
		// 정보 출력
		printf("'%s'님의 현재 위치 (%d, %d)\n", e1.name, x, y);
		printf("점수: %4d\t돈: %4d\n식량: %4d\t체력:%4d\n운: %6.2f\n\n", e1.score, e1.gold, e1.food, e1.health, e1.luck);


		printf("[ 마을 ]\n");
		printf("1. Food 구입\n2. Health 회복\n3. Luck 증가\n4. 마을 떠나기\n");
		menu = getche();
		switch (menu) {
		case '1': {
			if (e1.food <= 98) {
				e1.food += 2;
				e1.gold--;
			}
			else {
				printf("Food는 100개 이상 보유할 수 없습니다.\n");
			}
			break;
		}
		case '2': {
			if (e1.health <= 95) {
				e1.health += 5;
				e1.gold--;
			}
			else {
				printf("Health는 100개 이상 보유할 수 없습니다.\n");
			}
			break;
		}
		case '3': {
			if (e1.luck <= 1) {
				e1.luck *= 2;
				e1.gold -= 100;
			}
			else {
				printf("Luck의 최대치는 1입니다.");
			}
			break;
		}
		}
	} while (menu != '4');
}


// 유적 메뉴
void ruin(struct explorer e1, int x, int y) {
	char menu;

	do {
		system("cls");
		// 정보 출력
		printf("'%s'님의 현재 위치 (%d, %d)\n", e1.name, x, y);
		printf("점수: %4d\t돈: %4d\n식량: %4d\t체력:%4d\n운: %6.2f\n\n", e1.score, e1.gold, e1.food, e1.health, e1.luck);


		printf("[ 유적 ]\n");
		printf("1. Gold 획득\n2. Score 획득\n3. 유적 떠나기\n");
		menu = getche();
		switch (menu) {
		case '1': {
			e1.gold += 1000 * e1.luck;
			break;
		}
		case '2': {
			e1.score += 2000 * e1.luck;
			break;
		}
		}
	} while (menu != '3');
}