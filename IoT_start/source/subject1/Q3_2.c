#include <stdio.h>
/*

문제 3-2
세 개의 숫자를 입력 받아서 그 중 가장 큰 수를 출력하는 프로그램을 구현하세요.
삼항연산자(조건연산자)를 사용해서 작성해보세요.

세 개의 숫자를 입력하세요 : 3 7 12
큰 수는 12


*/

int main_q3_2(void)
{
	int a = 0, b = 0, c = 0, res1 = 0, res2 = 0, res = 0;

	printf("세 개의 숫자를 입력하세요 : ");
	scanf("%d %d %d", &a, &b, &c);

	res1 = (a > b) ? a : b;
	res2 = (b > c) ? b : c;
	res = (res1 > res2) ? res1 : res2;

	printf("큰 수는 %d", res);

	// 다중 삼항연산자 사용도 가능
	// ex) ( a > b ) ? (( a > c ) ? a : c ) :(( b > c ) ? b : c ))

	return 0;

	
}