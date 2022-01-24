#include <stdio.h>

/*

문제 3-1
두 개의 숫자를 입력 받아서 그 중 큰 수를 출력하는 프로그램을 작성하세요.
단, if 관련 문장을 사용한다면 삼항연산자(조건연산자)를 사용하는 프로그램도 작성해보세요.

문제 3-1 실행의 예

두 개의 숫자를 입력하세요 : 7 12
큰 수는 12

*/

int main_q3_1(void)
{
	// 1. if문을 이용
	/*
	int i = 0, j = 0;

	printf("두개의 숫자를 입력해 주세요 : ");
	scanf("%d %d", &i, &j);

	if (i > j)
	{
		printf("큰 값 : %d 입니다.\n", i);
	}
	else if (i == j)
	{
		printf("값이 같습니다. 다시 시작해 주세요\n");
	}
	else
	{
		printf("큰 값 : %d 입니다.\n", j);
	}
	*/

	// 2. 삼항연산자(조건 연산자)이용
	int a = 0, b = 0, res = 0;

	printf("두개의 숫자를 입력해 주세요 : ");
	scanf("%d %d", &a, &b);

	res = (a > b) ? a : b;		// a와 b중 큰 값 출력
	printf("둘 중 더 큰 값 : %d\n", res);


	return 0;
}