#include <stdio.h>

/*

문제 1-1

실수(정수가 아닌 실수이다) 두 개를 입력 받아서, 두 실수의 사칙연산 결과를 출력하는 프로그램을 작성하세요.

문제 1-1 실행의 예

두 개의 실수 입력: 3.7 2.5
덧셈 결과 : 6.200000
뺄셈 결과 : 1.200000
곱셈 결과 : 9. 250000
나눗셈 결과 : 1.480000

*/

int main(void)
{
	float a = 0, b = 0;

	printf("두 개의 실수 입력: ");
	scanf("%f %f", &a, &b);

	float sum = a + b;
	float sub = a - b;
	float mul = a * b;
	float div = a / b;

	printf("덧셈 결과 : %f\n", sum);
	printf("뺄셈 결과 : %f\n", sub);
	printf("곱셈 결과 : %f\n", mul);
	printf("나눗셈 결과 : %f\n", div);

	return 0;
}
