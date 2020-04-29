# HW6

---

1. 다음을 수행하는 프로그램 작성

​    사용자로부터 이름(문자열) 5개를 입력 받아서 char names[5][80]에 저장.
​    names에 저장된 내용을 차례대로 출력.

​    사용자로부터 이름(문자열) 1개를 입력 받아서 char search[80] 에 저정.
​    names에 search와 같은 이름이 있으면, 몇번째 이름인지 출력.
​    names에 search와 같은 이름이 없으면, "없습니다" 출력.
​    이러한 검색을 "quit"이 입력될 때 까지 반복.

```c
// 1번
#include <stdio.h>
#include <string.h>

int main(void) {
	char names[5][80];
	char search[80];

	for (int i = 0; i < 5; i++) {
		scanf_s("%s", names[i], sizeof(names[i]));
		printf("%s\n", names[i]);
	}
	scanf_s("%s", &search, sizeof(search));

	while (strcmp(search, "quit") != 0) {
		for (int i = 0; i < 5; i++) {
			if (strcmp(search, names[i]) == 0) {
				printf("%d번째 이름입니다.\n", i + 1);
				break;
			}
			else if (i == 4 && strcmp(search, names[i]) != 0) {
				printf("없습니다.\n");
			}
		}

		scanf_s("%s", &search, sizeof(search));
	}

	return 0;
}
```

---

2. 다음을 수행하는 프로그램 작성

사용자로부터 이름(문자열), 나이(정수), 키(실수)를 입력받아서
각각 char name[80], int age, float height에 저장.
strcpy()와 strcat()를 사용하여
char result[200]에 다음과 같은 문자열을 저장
"[name] is [age] years old and his/her height is [height]"
(여기서 [name], [age], [height]는 각각 변수 name, age, height에 저장된 값을 의미함)
result의 문자열 내용을 출력


```c
// 2번
#include <stdio.h>
#include <string.h>

int main(void) {
	char name[80];
	int age;
	float height;
	char result[200];

	scanf_s("%s %d %f", name, sizeof(name), &age, &height);

	strcpy_s(result, sizeof(result), name);
	strcat_s(result, sizeof(result), " is ");

	char s1[80];
	sprintf_s(s1, sizeof(s1), "%d years old and his/her height is %.2f", age, height);
	strcat_s(result, sizeof(result), s1);
	

	printf("%s\n", result);


	return 0;
}
```

---

3. 다음을 수행하는 프로그램 작성

​    사용자로부터 이름(문자열), 나이(정수), 키(실수)를 입력받아서
​    char name[80], int age, float height 로 이루어진 구조체에 저장. 
​    구조체의 내용을 출력

```c
// 3번
#include <stdio.h>

struct Person {
	char name[80];
	int age;
	float height;
};

int main(void) {
	struct Person p1;
	
	scanf_s("%s %d %f", p1.name, sizeof(p1.name), &p1.age, &p1.height);
	printf("%s %d %f\n", p1.name, p1.age, p1.height);

	return 0;
}
```

