#include <stdio.h>
/*

문제 6-1. 입력 받은 정수 n 이하의 자연수 중에서 짝수의 합과, 홀수의 합을 각각 계산하여
출력하는 프로그램을 구현하세요. 참고로 자연수라 함은 0보다 큰 정수를 의미합니다.


문제 6-1 실행의 예

자연수 입력 : 12
12 이하 홀수 합 : 36
12 이하 짝수 합 : 42

*/

int main_q6_1(void)
{
	int a = 0, sum1 = 0, sum2 = 0;

	printf("자연수 입력 :");
	scanf("%d", &a);

	for (int i = 0; i <= a; i++)
	{
		if (i % 2 == 1)		// 홀수
		{
			sum1 += i;
		}
		else				// 짝수
		{
			sum2 += i;
		}
	}

	printf("%d 이하 홀수 합 : %d\n", a, sum1);
	printf("%d 이하 짝수 합 : %d\n", a, sum2);

	return 0;
}