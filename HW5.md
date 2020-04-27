# HW5

---

**1. 다음을 수행하는 프로그램 작성**


int a[10] 에는 2부터 시작해서 10개의 짝수를 저장 (for문 사용)
int b[10] 에는 1부터 시작해서 10개의 홀수를 저장 (for문 사용)
int c[10] 에는 a[i] * b[i]를 저장 (for문 사용)
int sum에는 c[0]부터 c[9]에 자장된 값을 합하여 저장 (while문 사용)

a, b, c, sum의 내용을 화면에 출력

```c
// 1번
#include <stdio.h>

int main(void) {
	int a[10], b[10], c[10];
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		a[i] = 2 * (i + 1);
		b[i] = 2 * i + 1;
		c[i] = a[i] * b[i];
	}

	int i = 0;
	while (i<10) {
		sum += c[i];
		i++;
	}

	printf("a\tb\tc\tsum = %d\n", sum);
	for (int i = 0; i < 10; i++) {
		printf("%d\t%d\t%d\n", a[i], b[i], c[i]);
	}

	return 0;
}
```

---

**2. 구구단 문제**

int gugu[8][9]에 다음과 같은 순서로 구구단 결과를 저장 (for문 혹은 while문 사용)
gugu[0][0] = 2 * 1
gugu[0][1] = 2 * 2
gugu[0][2] = 2 * 3
...
...
gugu[7][7] = 9 * 8
gugu[7][8] = 9 * 9

gugu의 내용을 화면에 출력

```c
// 2번
#include <stdio.h>

int main(void) {
	int gugu[8][9];

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 9; j++) {
			gugu[i][j] = (i + 2)*(j + 1);
			printf("%d\t", gugu[i][j]);
		}
		printf("\n");
	}

	return 0;
}
```

---

**3. 성적처리 문제**

scanf()를 사용하여
int score[10]에 10개의 성적을 입력받고 (성적은 0점부터 100점 사이 값만 허용)
\- 평균
\- 최소점수
\- 최대점수
를 출력하는 프로그램 작성

```c
// 3번
#include <stdio.h>

int main(void) {
	int score[10];
	int sum = 0;
	int min = 100, max = 0;

	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &score[i]);
		
		if (score[i] < 0 || score[i]>100)
			return -1;

		sum += score[i];

		if (min > score[i])
			min = score[i];

		if (max < score[i])
			max = score[i];

	}

	printf("average = %d\nmin = %d\nmax = %d\n", sum / 10, min, max);

	return 0;
}
```

---

**4. 랜덤 번호 생성**

int a[5]에 0부터 10사이의 랜덤한 번호를 저장
단 같은 번호가 2번 나오면 안됨

최종적으로 a의 내용을 화면에 출력

```c
// 4번
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	int a[5];
	
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		a[i] = rand() % 11;
		
		for (int j = 0; j < i; j++) {
			while (a[j] == a[i]) {
				a[i] = rand() % 11;
			}
		}
		printf("%d\t", a[i]);
	}

	return 0;
}
```

