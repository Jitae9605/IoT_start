#include <stdio.h>

/*

문제 7-2. 정수 n을 입력 받습니다. 그리고 다음 수식을 만족하는 정수 a, b, c의 모든 조합을 찾아서
출력하는 프로그램을 작성하세요. 단, a, b 그리고 c 값의 범위는 0 이상 100 이하로 제한합니다.

axb-c=n


문제 7-2 실행의 예

정수 입력 : 12
(1) × (12) - (0) = (12)
(1) × (13) - (1) = (12)
(1) X (14) - (2) (12)

*/

int main_q7_2(void)
{
	int a = 0;

	printf("정수 입력 :");
	scanf("%d", &a);

	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{

			for (int k = 0; k <= 100; k++)
			{
				if ((i * j - k) == a)
				{
					printf("(%d) × (%d) - (%d) = (%d)\n ", i, j, k, a);
				}
			}
		}
	}
}