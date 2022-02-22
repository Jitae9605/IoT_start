#include <stdio.h>

extern int count_2;						// _main.c 파일의 전역변수 count_2 공유
int total_2 = 0;						// 전역 변수 선언

int input_data_2(void)
{
	int pos;

	while (1)
	{
		printf("양수 입력 : ");
		scanf("%d", &pos);
		if (pos < 0) break;
		count_2++;
		total_2 += pos;
	}

	return total_2;
}