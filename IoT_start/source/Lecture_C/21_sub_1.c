#include<stdio.h>

void input_data_1(int* pa, int* pb)
{
	printf("두 정수 입력 : ");
	scanf("%d%d", pa, pb);
}

double average_1(int a, int b)
{
	int tot;
	double avg;

	tot = a + b;
	avg = tot / 2.0;

	return avg;
}