# HW7

---

**1.  25인치(inch)의 길이를 센티미터(cm)로 계산하여 출력하는 프로그램을 완성하라. (10점)  **

```c
#include <stdio.h>

int main(void) {
	int inch = 25;
	float cm;

	cm = inch * 2.54;
	printf("%d inch는 %.2fcm입니다.\n", inch, cm);
	
	return 0;
}
```

---

**2. 다음은 화씨온도를 섭씨온도로 변환하는 프로그램이다. 그러나, 올바르지 않은 결과가 나온다. 어떤 올바르지 않은 결과가 나오는지 기술하고, 올바른 결과가 나오도록 수정하라. (10점)  **

```c
int main(void) { 
    int fahrenheit, celsius; 
 	fahrenheit = 72; 
    celsius = (5.0/9.0) * (fahrenheit - 32); 
 	printf("화씨온도 %f도는 섭씨온도 %f도입니다.\n", fahrenheit, celsius); 
    return 0; 
} 
```

''화씨온도 0.00000도는 섭씨온도 0.00000도입니다.'가 출력
1) celsius가 실수형이므로 정수형 int가 아니라 float로 선언해야함.
2) fahrenheit는 정수형이므로 형식지정자가 %f가 아니라 %d이어야 함.

```c
#include <stdio.h>

int main(void) {
	int fahrenheit;
	float celsius;

	fahrenheit = 72;
	celsius = (5.0 / 9.0)*(fahrenheit - 32);

	printf("화씨온도 %d도는 섭씨온도 %.2f도입니다.\n", fahrenheit, celsius);
	
	return 0;
}
```

---

**3. 삼각형의 밑변과 높이를 입력받아 넓이를 출력하는 프로그램을 작성하라 (10점, 완전한 형태로 작성)**

```c
#include <stdio.h>

int main(void) {
	int base, height;
	
	scanf_s("%d %d", &base, &height);
	printf("삼각형의 넓이: %.2f\n", (float)base*height / 2);
	
	return 0;
}
```

---

** 4. 다음 두 프로그램의 실행 결과를 각각 기술하라. (각 5점, 총 10점)**

```c
int main(void) { 
	int x = 3, y = 4; 
 	printf("%d\n", ++x * 2); 
 	printf("%d\n", y-- % 5); 
 	return 0; 
} 
```

8
4

```c
int main(void) { 
	int x = 5, y; 
	float z; 
	y = x/2; 
	printf("y = %d\n", y); 
	y = (float)x/2; 
	printf("y = %d\n", y);
   	z = x/2; 
    printf("z = %.1f\n", z); 
    z = (float)x/2; 
    printf("z = %.1f\n", z); 
    z = (float)(x/2); 
    printf("z = %.1f\n", z); 
 	return 0; 
}
```

y = 2
y = 2
z = 2.0
z = 2.5
z = 2.0

---

**5. 세 수를 입력받아 가장 큰 수를 출력하는 프로그램을 작성하라. (10점, 완전한 형태로 작성) **

```c
#include <stdio.h>
#include <limits.h>

int main(void) {
	int a, b, c;
	int max = INT_MIN;

	scanf_s("%d %d %d", &a, &b, &c);
	
	if (a > b) {
		if (a > c)
			max = a;
		else 
			max = c;
	}
	else if (b > a) {
		if (b > c) 
			max = b;
		else 
			max = c;
	}

	printf("가장 큰 수: %d\n", max);

	return 0;
}
```

---

**6. 다음 두 프로그램을 각각 if문이 한 번만 나타나도록 수정하라. (각 5점, 총 10점)**

1)

```c
if (x<10)     
	printf(“%d\n”, x); 
if (x>10)     
	printf(“%d\n”, x);
```

```c
if (x!=10)     
	printf(“%d\n”, x); 
```

2)

```c
if (x<10)  
	if (x>10)        
		printf(“%d\n”, x); 
```

```c
if (0)
	printf("%d\n", x);
```

---

**7. 양의 정수 하나를 입력받아서, 그 수가 소수(prime number)인지 판단하는 함수를 작성하라. (10점) **

/* 소수이면 1을, 소수가 아니면 0을 return 하는 함수 */

```c
int prime(int num) {
	if (num % 2 == 0)
		return 0;
	for (int i = 3; i < num; i += 2) {
		if (num%i == 0)
			return 0;
	}
	return 1;
}
```

---

**8. 다음은 main함수의 일부 코드이다. 잘못된 곳을 모두 찾고, 이유를 기술하라. (10점) **

```c
int i; 
int age[5] = 19, 22, 25, 17, 27; 
int m[][] = {{1, 2, 3}, {4, 5, 6}}; 
char title[5] = "C/C++"; 
 
for(i=1; i<=5; i++) {    
    print("%d \n", age[i]); 
} 
  
scanf("%s", title); 
scanf("%c", title[0]); 
```

1) age 선언할 때 괄호 없음 ->  int age[5] = { 19, 22, 25, 17, 27 };

2) m 선언할 때 배열의 크기를 지정해줘야 함	-> int m[][3] = {{1, 2, 3}, {4, 5, 6}};

3) for문 안에 조건이 잘못됐음 -> for(i=1; i<5; i++)

4) for문 안의 printf에 f가 없음 -> printf("%d \n", age[i]); 

5) 배열을 입력할 때 & 연산자가 있으면 안됨. 그리고 형식지정자가 %c임 -> scanf("%c", title); 

---

**9. 정수 배열 int socres[9]에 9명의 점수가 10, 8, 7, 9, 6, 10, 9, 8, 7 와 같이 저장되어 있을 때, 점수 하나를 추가로 입력받고 그 점수가 전체 중 몇 등인지 출력하는 함수를 작성하라. (10점)**

```c
int grade(int scores[]) {
	int score;
	int num = 1;

	scanf_s("%d", &score);

	for (int i = 0; i < 9; i++) {
		if (scores[i] > score) {
			num++;
		}
	}

	printf("%d점은 %d등 입니다.\n", score, num);
}
```

---

**10. 다음과 같은 데이터를 저장할 구조체를 만들고, 각각의 값을 입력받아 출력하는 프로그램을 작성하라. (10점, 완전한 형태로 작성) **

직원(employee) 데이터 
  - no : 사원번호 (7자리 숫자와 문자의 조합)
  - name: 이름 (최대 영문자 30글자) 
  - children: 자녀수
  -  pay: 기본급 

```c
#include <stdio.h>

struct Employee {
	char no[7];
	char name[30];
	int children;
	int pay;
};

int main(void) {
	struct Employee e1; 

	scanf_s("%s %s %d %d", e1.no, 7, e1.name, 30, &e1.children, &e1.pay);
	printf("사원번호\t%s\n이름\t%s\n자녀수\t%d\n기본급여\t%d\n", e1.no, e1.name, e1.children, e1.pay);

	return 0;
}

```



​    

​    

​    

​    