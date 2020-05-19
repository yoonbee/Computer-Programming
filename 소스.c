#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void print_map(char field[SIZE][SIZE], int x, int y);

int main(void) {
	char field[SIZE][SIZE];
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


	scanf_s("%d %d", &x, &y);
	print_map(field, x, y);

	return 0;
}


// 주변 지도 출력
void print_map(char field[SIZE][SIZE], int x, int y) {
	
	for (int i = y < 10 ? 0 : y - 10; i < (y < 90 ? y + 10 : 100); i++) {
		for (int j = x < 10 ? 0 : x - 10; j < (x < 90 ? x + 10 : 100); j++) {
			printf("%c ", field[i][j]);

			if (y == i + 1 && x == j + 1) {
				printf("o ");
				continue;
			}
		}
		printf("\n");
	}

}