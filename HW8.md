# 진격의 보물 탐험가 제1장

아드리아 왕국은 신비한 보물과 위험한 몬스터들로 가득찬 모험의 땅이다.경험많은 모험가인 당신은 이제 막 아드리아 왕국에 첫발을 내딛었다.목표는 더 많은 보물을 찾아 부를 쌓고, 몬스터들을 사냥해서 명성을 올리는 것!!당신의 모험가로서의 노련한 감각은 먼저 아드리아 왕국의 지도를 만들어야 한다고 말하고 있다.

**1. 아드리아 왕국의 random 지도 생성하기**
아드리아 왕국은 100 x 100의 영역으로 이루어져 있다. 
즉, 100행 100열의 2차원 배열로 표현 가능하다. (char field[100][100])
각 영역은 다음의 요소들과 출현 확률로 나타내어진다.

- 평지 ( _ ): 80%
- 산지 ( T ): 15%
- 금 ( + ): 2%
- 다이아몬드 ( * ) : 1%
- 유적 ( ? ): 1%
- 마을 ( # ): 1%
field 배열에 위와 같은 지형을 확률에 따라 생성하라.
힌트: 난수생성함수(rand())을 사용하여 확률에 따라 생성할 수 있음.
예를들어 1부터 100사이의 난수를 생성해서
1부터 80사이 값이면 평지 생성
81부터 95사이 값이면 산지 생성
96부터 97사이 값이면 다이아몬드 생성 등



**2. 내 주변 지도표시**
지도를 다 만들었으면 현재 내 위치(x: 0부터 99사이, y: 0부터 99사이)를 입력받아 
주변 상하좌우 10칸의 지도를 화면에 표출하자.
예를들어 내 위치가 x = 30, y = 30이 입력되면 다음과 같이 출력된다.
(참고로, 내 위치는 중앙에 o로 표시됨)

현재위치입력 (X Y) :30 30

```c
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
```

