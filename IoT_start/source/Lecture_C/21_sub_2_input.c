#include <stdio.h>

extern int count_2;						// _main.c ������ �������� count_2 ����
int total_2 = 0;						// ���� ���� ����

int input_data_2(void)
{
	int pos;

	while (1)
	{
		printf("��� �Է� : ");
		scanf("%d", &pos);
		if (pos < 0) break;
		count_2++;
		total_2 += pos;
	}

	return total_2;
}