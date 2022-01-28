#include <stdio.h>

// 2.상수와 데이터출력
// 기본적인 변환, 데이터타입(% d/c/s), 주석(// , /*)

int main_const_3213(void)
{

	// 1. printf 사용
	
	printf("%d\n", 10);      // %d = 정수(int)데이터 표현법
	printf("%.2lf\n", 3.5);  // %lf = 실수(float,long)데이터 표현법 ( .2 = 소수 2째자리까지 표현)
	printf("%d\n", 10 + 20); // %d 에는 계산식이 들어갈수 있다.

	int i = 10;
	int j = 20;
	printf("%d\n", i + j); // 변수도 계산식 사용 가능

	long a = 10.5;
	long b = 20.4;
	printf("%d\n", a + b); // 이래도 계산은 되지만 소수점이 버림된다 (30.9 -> 30)


	// 2. 진법

	printf("%d\n", 12);  // 10진수 12
	printf("%d\n", 014); //  8진수 12 0
	printf("%d\n", 0xc); // 16진수 12 0x


	// 3. 문자열

	printf("%c\n", 'A'); // %c = 문자(char) 표현 ('' 작은따옴표)
	printf("%s\n", "A"); // %s = 문자열(string) 표현 ("" 큰따옴표)
	printf("%c 은 %s 입니다\n", '1', "first");



	return 0;
}