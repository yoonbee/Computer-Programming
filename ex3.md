# 문제3

 

* 다음 튜터링 시간까지 풀어보고 소스코드를 튜터링 시간에 보여주세요! 각 문제당 걸린 시간을 코드에 주석으로 달아주세요. 틀려도 좋으니 본인의 힘으로 풀어보고 모르는 것을 질문해주세요.

 

1. 10개의 수를 입력 받아서 이들 중에서 같은 것이 있는지 검사하는 프로그램을 작성하세요. 힌트: 10개의 수를 배열에 저장한 다음에 각 배열 원소를 앞에 있는 배열 원소들과 비교한다.

 ```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int num[10];
	int dupli = 0;

	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num[i]);
		
		for (int j = 0; j < i; j++) { 
			// i = 0인 경우: 검사 X
			// i = 1인 경우: j = 0 검사
			// i = 2인 경우: j = 0, 1 검사
			if (num[i] == num[j])
				dupli++;
		}
	}

	
	if(dupli!=0)
		printf("같은 수가 존재합니다.\n");

	return 0;
}
 ```

2. 1번과 비슷하게 10개의 문자열을 입력 받아서, 이들 중에서 같은 것이 있는지 검사하는 프로그램을 작성하세요.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcmp를 사용하기 위해서 필요한 헤더 파일

int main(void) {
	char words[10][100];
	int dupli = 0;

	for (int i = 0; i < 10; i++) {
		scanf_s("%s", words[i], 100);	// 문자열 입력: scanf("%s", words[i])와 동일

		for (int j = 0; j < i; j++) {
			if(strcmp(words[i], words[j])==0) // 문자열 비교: words[i]와 words[j]가 같으면 0 반환
				dupli++;
		}
	}
	if (dupli != 0)
		printf("같은 수가 존재합니다.\n");

	return 0;
}
```

3. 특정 단어(quit)가 입력되기 전까지 단어를 입력 받고 그 문자열의 크기를 출력하세요.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void) {
	char word[100];

	scanf_s("%s", word, 100);	// 문자열 입력: scanf("%s", word);와 동일
	while (strcmp(word, "quit") != 0) { // 문자열 비교
		// 입력 받은 word와 "quit"가 같으면 0 반환 -> while문 실행 불가
		printf("%d\n", strlen(word)); // 문자열 길이
		scanf_s("%s", word, 100);
	}

	return 0;
}
```

4. 두 문자열을 입력 받아서 문자 배열 a, b에 각각 저장한 후, 두 문자열을 비교하여 작은 것은 a에, 큰 것은 b에 저장하고 두 문자 배열의 내용을 출력하는 프로그램을 작성하세요. 힌트: 두
배열의 내용을 교환하기 위해서 임시 저장 배열이 필요하다.

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(void) {
	char a[100], b[100], c[100];

	scanf_s("%s", a, 100);	// 문자열 입력: scanf("%s", a);와 동일
	scanf_s("%s", b, 100);

	if (strcmp(a, b) > 0) {	// 문자열 비교: a>b이면 => a, b 교환
		char temp[100];

		strcpy_s(temp, 100, a);	// 문자열 복사: strcpy(temp, a)와 동일
		strcpy_s(a, 100, b);
		strcpy_s(b, 100, temp);
	}

	strcpy_s(c, 100, a); 
	strcat_s(c, 100, b); // 문자열 연결: strcat(c, b)와 동일
	printf("%s", c, 100); // 문자열 출력: printf("%s", c)와 동일

	return 0;
}
```

